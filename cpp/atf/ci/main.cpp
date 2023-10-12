// Copyright (C) 2013-2019 NYSE | Intercontinental Exchange
// Copyright (C) 2020-2023 Astra
// Copyright (C) 2023 AlgoRND
//
// License: GPL
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.
//
// Contacting ICE: <https://www.theice.com/contact>
// Target: atf_ci (exe) -- Normalization tests (see citest table)
// Exceptions: yes
// Source: cpp/atf/ci/main.cpp
//

#include "include/atf_ci.h"
#include "include/lib_git.h"

// -----------------------------------------------------------------------------

static strptr CurCitest() {
    return atf_ci::_db.c_citest ? strptr(atf_ci::_db.c_citest->citest) : strptr();
}

// -----------------------------------------------------------------------------

static bool CaptureQ() {
    return atf_ci::_db.cmdline.capture
        || (atf_ci::_db.c_citest
            && atf_ci::_db.c_citest->cijob == atf_ci::atfdb_cijob_normalize);
}

// -----------------------------------------------------------------------------

// Check that a list of directories specified with DIRS is clean
// Nothing is done if an error exit code is already set, since
// this error might have been caused by the previous error.
// Return TRUE if test succeeds
bool atf_ci::CheckCleanDirs(strptr dirs) {
    bool ret=true;
    tempstr mod = lib_git::GitModifiedFiles(dirs);
    if (mod != "") {
        prerr("atf_ci.modified_files"
              <<Keyval("during",CurCitest())
              <<Keyval("files",mod)
              <<Keyval("success","N")
              <<Keyval("comment","Please resolve modified files and try again"));
        prerr("Some of the diffs are shown below");
        SysCmd("git diff | head -500");
        ret=false;
    }
    return ret;
}

// Check that DIR is not generated by the test
void atf_ci::CheckNoDir(strptr dir) {
    if (algo_lib::_db.exit_code==0) {
        if (algo::DirectoryQ(dir)) {
            prerr("atf_ci.modified_files"
                  <<Keyval("during",CurCitest())
                  <<Keyval("dir",dir)
                  <<Keyval("success","N")
                  <<Keyval("comment","Please check generated dir and try again"));
            algo_lib::_db.exit_code=1;
        }
    }
}



// -----------------------------------------------------------------------------

void atf_ci::citest_atf_amc() {
    command::atf_amc_proc atf_amc;
    atf_amc_ExecX(atf_amc);
}

// -----------------------------------------------------------------------------

void atf_ci::citest_atf_unit() {
    command::atf_unit_proc atf_unit;
    atf_unit.cmd.capture = CaptureQ();
    atf_unit.cmd.perf_secs=0;
    atf_unit_ExecX(atf_unit);
}

// -----------------------------------------------------------------------------
void atf_ci::citest_atf_comp() {
    command::atf_comp_proc atf_comp;
    atf_comp.cmd.capture = CaptureQ();
    atf_comp_ExecX(atf_comp);
}

// -----------------------------------------------------------------------------
void atf_ci::citest_atf_comp_cov() {
    command::atf_comp_proc atf_comp;
    atf_comp.cmd.build = true;
    atf_comp.cmd.covcapture = CaptureQ();
    atf_comp.cmd.covcheck = !atf_comp.cmd.covcapture;
    atf_comp_ExecX(atf_comp);
}

// -----------------------------------------------------------------------------
void atf_ci::citest_atf_comp_mem() {
    command::atf_comp_proc atf_comp;
    atf_comp.cmd.build = true;
    atf_comp.cmd.memcheck = true;
    atf_comp_ExecX(atf_comp);
}

// -----------------------------------------------------------------------------

void atf_ci::citest_normalize_amc_vis() {
    command::amc_vis amc_vis;
    amc_vis.ctype.expr = "%";
    amc_vis.check      = true;
    SysCmd(amc_vis_ToCmdline(amc_vis),FailokQ(false));
}

// -----------------------------------------------------------------------------

void atf_ci::citest_gitfile() {
    SysCmd("bin/update-gitfile >/dev/null",FailokQ(false));
    ind_beg(algo::FileLine_curs,line,SsimFname(atf_ci::_db.cmdline.in,dmmeta_Ssimfile_ssimfile_dev_gitfile)) {
        dev::Gitfile gitfile;
        if (Gitfile_ReadStrptrMaybe(gitfile,line)) {
            if (!FileObjectExistsQ(gitfile.gitfile)) {
                prlog("atf_ci.missing_file"
                      <<Keyval("success","N")
                      <<Keyval("gitfile",gitfile.gitfile)
                      <<Keyval("comment","File missing from filesystem"));
                algo_lib::_db.exit_code=1;
            }
        }
    }ind_end;
}

// -----------------------------------------------------------------------------

static bool RunCiTest(atf_ci::FCitest &citest) {
    prlog("atf_ci.begin"
          <<Keyval("citest",citest.citest));
    algo::UnTime start=algo::CurrUnTime();
    // enter sandbox, if requested
    if (citest.sandbox) {
        command::sandbox_proc sandbox;
        sandbox.cmd.name.expr = dev_Sandbox_sandbox_atf_ci;
        if (bool_Update(atf_ci::_db.sandbox_need_init,true)) {
            sandbox.cmd.reset = true;// initialize
        } else {
            sandbox.cmd.clean = true;// quick reset
        }
        sandbox_ExecX(sandbox);
        algo_lib::SandboxEnter(dev_Sandbox_sandbox_atf_ci);
    }
    try {
        atf_ci::_db.c_citest=&citest;
        int code_before = algo_lib::_db.exit_code;
        citest.step();
        citest.nerr += (code_before ==0 && algo_lib::_db.exit_code != 0);
    } catch (algo_lib::ErrorX &x) {
        citest.nerr++;
        prlog(x.str);
    }
    // for sandboxed tests, do not check for modified files
    // for regular tests, it is mandatory
    if (!citest.sandbox) {
        citest.nerr += !atf_ci::CheckCleanDirs(".");
    }
    if (citest.nerr) {
        algo_lib::_db.exit_code = 1;
    }
    if (citest.sandbox) {
        algo_lib::SandboxExit();
    }
    prlog("atf_ci.citest"
          <<Keyval("citest",citest.citest)
          <<Keyval("runtime", algo::CurrUnTime()-start)
          <<Keyval("success", Bool(citest.nerr==0))
          <<Keyval("comment",citest.comment));
    return citest.nerr==0;
}

// -----------------------------------------------------------------------------

// Compare contents of file `outfname` with the reference file.
// Any difference = error
void atf_ci::CompareOutput(strptr outfname) {
    tempstr expect_fname = tempstr() << "test/atf_ci/" << atf_ci::_db.c_citest->citest;
    if (CaptureQ()) {
        CopyFileX(outfname, expect_fname, 0644);
    } else {
        vrfy_(SysCmd(tempstr()
                     << "git --no-pager diff --no-index "
                     << " " << expect_fname
                     << " " << outfname) == 0);
    }
}


// -----------------------------------------------------------------------------

void atf_ci::citest_bintests() {
    ind_beg(algo::Dir_curs,entry,"bin/test-*") {
        if (!entry.is_dir && !EndsWithQ(entry.pathname,"~")) {
            SysCmd(entry.pathname,FailokQ(false));
        }
    }ind_end;
}

// -----------------------------------------------------------------------------

void atf_ci::citest_checkclean() {
    // do nothing - atf_ci will check clean dirs
    // after this test
}

// -----------------------------------------------------------------------------

void atf_ci::citest_lineendings() {
    algo_lib::Regx regx;
    Regx_ReadSql(regx, "txt/%",true);
    cstring files(SysEval("git ls-files",FailokQ(true),1024*1024*100));
    ind_beg(Line_curs,fname,files) {
        if (Regx_Match(regx,fname) && FileQ(fname)) {
            SysCmd(tempstr() << "sed -i 's/\\r$//;s/\\r/\\n/g' "<<fname);
        }
    }ind_end;
}

// -----------------------------------------------------------------------------

void atf_ci::citest_shebang() {
    ind_beg(_db_scriptfile_curs,scriptfile,_db) {
        ind_beg(algo::FileLine_curs,line,scriptfile.gitfile) {
            if (StartsWithQ(line,"#!")) {
                strptr interpreter = Pathcomp(line,"!LR LL");
                if (interpreter != "/bin/sh" && interpreter != "/usr/bin/env") {
                    prerr(scriptfile.gitfile<<":1: Non-portable interpreter "<<interpreter<<" use /usr/bin/env");
                    algo_lib::_db.exit_code=1;
                }
            }
            break;// first line only
        }ind_end;
    }ind_end;
}

// -----------------------------------------------------------------------------

void atf_ci::citest_comptest() {
    command::atf_comp_proc atf_comp;
    atf_comp.cmd.normalize=true;
    (void)atf_comp_Exec(atf_comp);
}

// -----------------------------------------------------------------------------

void atf_ci::citest_outfile () {
    command::bash_proc bash;
    bash.cmd.c << dev_scriptfile_bin_update_outfile;
    bash_ExecX(bash);
}

// -----------------------------------------------------------------------------

void atf_ci::citest_readme() {
    command::abt_md_proc abt_md;
    abt_md_ExecX(abt_md);
}

// -----------------------------------------------------------------------------

void atf_ci::Main() {
    algo_lib::DieWithParent();

    lib_ctype::Init(_db.cmdline.in);

    int n_run  = 0;
    int n_pass = 0;
    ind_beg(atf_ci::_db_citest_curs,citest,atf_ci::_db) {
        if (Regx_Match(atf_ci::_db.cmdline.citest, citest.citest)
            && Regx_Match(atf_ci::_db.cmdline.cijob, citest.cijob)) {
            ++n_run;
            n_pass += RunCiTest(citest);
            if (n_run-n_pass > _db.cmdline.maxerr) {
                break;
            }
        }
    }ind_end;

    if (n_run==0) {
        algo_lib::_db.exit_code=1;
        prlog("atf_ci.nomatch"
              <<Keyval("citest",atf_ci::_db.cmdline.citest)
              <<Keyval("comment","no tests matched specified pattern. run 'acr citest' to see the full list, or see the list below"));
        SysCmd("acr citest | ssimfilt -t atfdb.%");
    }

    if (algo_lib::_db.exit_code != 0) {
        ind_beg(_db_citest_curs,citest,_db) {
            if (citest.nerr) {
                prlog("atf_ci.failed"
                      <<Keyval("citest",citest.citest)
                      <<Keyval("success",Bool(false))
                      <<Keyval("comment","See prior output for more information"));
            }
        }ind_end;
    }

    prlog("report.atf_ci"
          <<Keyval("n_citest", atf_ci::citest_N())
          <<Keyval("n_run", n_run)
          <<Keyval("n_pass", n_pass)
          <<Keyval("success", Bool(algo_lib::_db.exit_code==0))
          <<Keyval("comment",(algo_lib::_db.exit_code==0
                              ? "The coast is clear. Proceed with caution :-)"
                              : "Some errors occured. Please examine them and try again.")));
}
