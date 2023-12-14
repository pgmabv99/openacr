//
// cpp/gen/ams_sendtest_gen.cpp
// Generated by AMC
//
// Copyright (C) 2008-2013 AlgoEngineering LLC
// Copyright (C) 2013-2019 NYSE | Intercontinental Exchange
// Copyright (C) 2020-2023 Astra
// Copyright (C) 2023 AlgoRND
//
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


#include "include/algo.h"  // hard-coded include
#include "include/gen/ams_sendtest_gen.h"
#include "include/gen/ams_sendtest_gen.inl.h"
#include "include/gen/algo_lib_gen.h"
#include "include/gen/algo_lib_gen.inl.h"
#include "include/gen/algo_gen.h"
#include "include/gen/algo_gen.inl.h"
#include "include/gen/command_gen.h"
#include "include/gen/command_gen.inl.h"
#include "include/gen/ams_gen.h"
#include "include/gen/ams_gen.inl.h"
#include "include/gen/lib_ams_gen.h"
#include "include/gen/lib_ams_gen.inl.h"
#include "include/gen/lib_json_gen.h"
#include "include/gen/lib_json_gen.inl.h"
#include "include/gen/lib_prot_gen.h"
#include "include/gen/lib_prot_gen.inl.h"
//#pragma endinclude

// Instantiate all libraries linked into this executable,
// in dependency order
lib_json::FDb       lib_json::_db;        // dependency found via dev.targdep
algo_lib::FDb       algo_lib::_db;        // dependency found via dev.targdep
lib_ams::FDb        lib_ams::_db;         // dependency found via dev.targdep
ams_sendtest::FDb   ams_sendtest::_db;    // dependency found via dev.targdep

namespace ams_sendtest {
const char *ams_sendtest_help =
"ams_sendtest: Algo Messaging System test tool\n"
"Usage: ams_sendtest [options]\n"
"    OPTION         TYPE    DFLT    COMMENT\n"
"    -in            string  \"data\"  Input directory or filename, - for stdin\n"
"    -id            int     0       Process index (0=parent)\n"
"    -file_prefix   string  \"\"      Use file_prefix\n"
"    -nchild        int     1       Number of stream readers\n"
"    -blocking                      Use blocking send mode\n"
"    -nmsg          int     1000    Number of messages to send/receive\n"
"    -trace         regx    \"\"      Regx expression specifying what to trace\n"
"    -timeout       int     30      Time limit for the send\n"
"    -recvdelay_ns  int     0       Pause nanoseconds between messages\n"
"    -senddelay_ns  int     0       Pause nanoseconds between messages\n"
"    -msgsize_min   int     64      Minimum message length\n"
"    -msgsize_max   int     1024    Maximum message length\n"
"    -bufsize       int     32768   Shared memory buffer size\n"
"    -recvdelay     int     0       Pause nanoseconds between messages\n"
"    -verbose       int             Verbosity level (0..255); alias -v; cumulative\n"
"    -debug         int             Debug level (0..255); alias -d; cumulative\n"
"    -help                          Print help and exit; alias -h\n"
"    -version                       Print version and exit\n"
"    -signature                     Show signatures and exit; alias -sig\n"
;


} // namespace ams_sendtest
namespace ams_sendtest { // gen:ns_print_proto
    // Load statically available data into tables, register tables and database.
    static void          InitReflection();
    // find trace by row id (used to implement reflection)
    static algo::ImrowPtr trace_RowidFind(int t) __attribute__((nothrow));
    // Function return 1
    static i32           trace_N() __attribute__((__warn_unused_result__, nothrow, pure));
    static void          SizeCheck();
} // gen:ns_print_proto

// --- ams_sendtest.AmsSendTest..Print
// print string representation of ams_sendtest::AmsSendTest to string LHS, no header -- cprint:ams_sendtest.AmsSendTest.String
void ams_sendtest::AmsSendTest_Print(ams_sendtest::AmsSendTest & row, algo::cstring &str) {
    algo::tempstr temp;
    str << "ams_sendtest.AmsSendTest";

    u64_Print(row.n_msg_send, temp);
    PrintAttrSpaceReset(str,"n_msg_send", temp);

    u64_Print(row.n_msg_recv, temp);
    PrintAttrSpaceReset(str,"n_msg_recv", temp);

    u64_Print(row.n_write_wait, temp);
    PrintAttrSpaceReset(str,"n_write_wait", temp);

    u64_Print(row.n_msg_limit, temp);
    PrintAttrSpaceReset(str,"n_msg_limit", temp);

    u64_Print(row.sum_recv_latency, temp);
    PrintAttrSpaceReset(str,"sum_recv_latency", temp);
}

// --- ams_sendtest.FChild.child.Start
// Start subprocess
// If subprocess already running, do nothing. Otherwise, start it
int ams_sendtest::child_Start(ams_sendtest::FChild& child) {
    int retval = 0;
    if (child.child_pid == 0) {
        verblog(child_ToCmdline(child)); // maybe print command
#ifdef WIN32
        algo_lib::ResolveExecFname(child.child_path);
        tempstr cmdline(child_ToCmdline(child));
        child.child_pid = dospawn(Zeroterm(child.child_path),Zeroterm(cmdline),child.child_timeout,child.child_fstdin,child.child_fstdout,child.child_fstderr);
#else
        child.child_pid = fork();
        if (child.child_pid == 0) { // child
            algo_lib::DieWithParent();
            if (child.child_timeout > 0) {
                alarm(child.child_timeout);
            }
            if (retval==0) retval=algo_lib::ApplyRedirect(child.child_fstdin , 0);
            if (retval==0) retval=algo_lib::ApplyRedirect(child.child_fstdout, 1);
            if (retval==0) retval=algo_lib::ApplyRedirect(child.child_fstderr, 2);
            if (retval==0) retval= child_Execv(child);
            if (retval != 0) { // if start fails, print error
                int err=errno;
                prerr("ams_sendtest.child_execv"
                <<Keyval("errno",err)
                <<Keyval("errstr",strerror(err))
                <<Keyval("comment","Execv failed"));
            }
            _exit(127); // if failed to start, exit anyway
        } else if (child.child_pid == -1) {
            retval = errno; // failed to fork
        }
#endif
    }
    child.child_status = child.child_pid > 0 ? 0 : -1; // if didn't start, set error status
    return retval;
}

// --- ams_sendtest.FChild.child.StartRead
// Start subprocess & Read output
algo::Fildes ams_sendtest::child_StartRead(ams_sendtest::FChild& child, algo_lib::FFildes &read) {
    int pipefd[2];
    int rc=pipe(pipefd);
    (void)rc;
    read.fd.value = pipefd[0];
    child.child_fstdout  << ">&" << pipefd[1];
    child_Start(child);
    (void)close(pipefd[1]);
    return read.fd;
}

// --- ams_sendtest.FChild.child.Kill
// Kill subprocess and wait
void ams_sendtest::child_Kill(ams_sendtest::FChild& child) {
    if (child.child_pid != 0) {
        kill(child.child_pid,9);
        child_Wait(child);
    }
}

// --- ams_sendtest.FChild.child.Wait
// Wait for subprocess to return
void ams_sendtest::child_Wait(ams_sendtest::FChild& child) {
    if (child.child_pid > 0) {
        int wait_flags = 0;
        int wait_status = 0;
        int rc = -1;
        do {
            // really wait for subprocess to exit
            rc = waitpid(child.child_pid,&wait_status,wait_flags);
        } while (rc==-1 && errno==EINTR);
        if (rc == child.child_pid) {
            child.child_status = wait_status;
            child.child_pid = 0;
        }
    }
}

// --- ams_sendtest.FChild.child.Exec
// Start + Wait
// Execute subprocess and return exit code
int ams_sendtest::child_Exec(ams_sendtest::FChild& child) {
    child_Start(child);
    child_Wait(child);
    return child.child_status;
}

// --- ams_sendtest.FChild.child.ExecX
// Start + Wait, throw exception on error
// Execute subprocess; throw human-readable exception on error
void ams_sendtest::child_ExecX(ams_sendtest::FChild& child) {
    int rc = child_Exec(child);
    vrfy(rc==0, tempstr() << "algo_lib.exec" << Keyval("cmd",child_ToCmdline(child))
    << Keyval("comment",algo::DescribeWaitStatus(child.child_status)));
}

// --- ams_sendtest.FChild.child.Execv
// Call execv()
// Call execv with specified parameters -- cprint:ams_sendtest.Argv
int ams_sendtest::child_Execv(ams_sendtest::FChild& child) {
    algo_lib::exec_args_Alloc() << child.child_path;

    if (child.child_cmd.in != "data") {
        cstring *arg = &algo_lib::exec_args_Alloc();
        *arg << "-in:";
        cstring_Print(child.child_cmd.in, *arg);
    }

    if (child.child_cmd.id != 0) {
        cstring *arg = &algo_lib::exec_args_Alloc();
        *arg << "-id:";
        i32_Print(child.child_cmd.id, *arg);
    }

    if (child.child_cmd.file_prefix != "") {
        cstring *arg = &algo_lib::exec_args_Alloc();
        *arg << "-file_prefix:";
        cstring_Print(child.child_cmd.file_prefix, *arg);
    }

    if (child.child_cmd.nchild != 1) {
        cstring *arg = &algo_lib::exec_args_Alloc();
        *arg << "-nchild:";
        i32_Print(child.child_cmd.nchild, *arg);
    }

    if (child.child_cmd.blocking != false) {
        cstring *arg = &algo_lib::exec_args_Alloc();
        *arg << "-blocking:";
        bool_Print(child.child_cmd.blocking, *arg);
    }

    if (child.child_cmd.nmsg != 1000) {
        cstring *arg = &algo_lib::exec_args_Alloc();
        *arg << "-nmsg:";
        i32_Print(child.child_cmd.nmsg, *arg);
    }

    if (child.child_cmd.trace.expr != "") {
        cstring *arg = &algo_lib::exec_args_Alloc();
        *arg << "-trace:";
        command::trace_Print(child.child_cmd, *arg);
    }

    if (child.child_cmd.timeout != 30) {
        cstring *arg = &algo_lib::exec_args_Alloc();
        *arg << "-timeout:";
        i32_Print(child.child_cmd.timeout, *arg);
    }

    if (child.child_cmd.recvdelay_ns != 0) {
        cstring *arg = &algo_lib::exec_args_Alloc();
        *arg << "-recvdelay_ns:";
        i64_Print(child.child_cmd.recvdelay_ns, *arg);
    }

    if (child.child_cmd.senddelay_ns != 0) {
        cstring *arg = &algo_lib::exec_args_Alloc();
        *arg << "-senddelay_ns:";
        i64_Print(child.child_cmd.senddelay_ns, *arg);
    }

    if (child.child_cmd.msgsize_min != 64) {
        cstring *arg = &algo_lib::exec_args_Alloc();
        *arg << "-msgsize_min:";
        i32_Print(child.child_cmd.msgsize_min, *arg);
    }

    if (child.child_cmd.msgsize_max != 1024) {
        cstring *arg = &algo_lib::exec_args_Alloc();
        *arg << "-msgsize_max:";
        i32_Print(child.child_cmd.msgsize_max, *arg);
    }

    if (child.child_cmd.bufsize != 32768) {
        cstring *arg = &algo_lib::exec_args_Alloc();
        *arg << "-bufsize:";
        i32_Print(child.child_cmd.bufsize, *arg);
    }

    if (child.child_cmd.recvdelay != 0) {
        cstring *arg = &algo_lib::exec_args_Alloc();
        *arg << "-recvdelay:";
        i64_Print(child.child_cmd.recvdelay, *arg);
    }
    for (int i=1; i < algo_lib::_db.cmdline.verbose; ++i) {
        algo_lib::exec_args_Alloc() << "-verbose";
    }
    char **argv = (char**)alloca((algo_lib::exec_args_N()+1)*sizeof(*argv));
    ind_beg(algo_lib::_db_exec_args_curs,arg,algo_lib::_db) {
        argv[ind_curs(arg).index] = Zeroterm(arg);
    }ind_end;
    argv[algo_lib::exec_args_N()] = NULL;
    // if child.child_path is relative, search for it in PATH
    algo_lib::ResolveExecFname(child.child_path);
    return execv(Zeroterm(child.child_path),argv);
}

// --- ams_sendtest.FChild.child.ToCmdline
algo::tempstr ams_sendtest::child_ToCmdline(ams_sendtest::FChild& child) {
    algo::tempstr retval;
    retval << child.child_path << " ";
    command::ams_sendtest_PrintArgv(child.child_cmd,retval);
    if (ch_N(child.child_fstdin)) {
        retval << " " << child.child_fstdin;
    }
    if (ch_N(child.child_fstdout)) {
        retval << " " << child.child_fstdout;
    }
    if (ch_N(child.child_fstderr)) {
        retval << " 2" << child.child_fstderr;
    }
    return retval;
}

// --- ams_sendtest.FChild..Init
// Set all fields to initial values.
void ams_sendtest::FChild_Init(ams_sendtest::FChild& child) {
    child.child_path = algo::strptr("bin/ams_sendtest");
    child.child_pid = pid_t(0);
    child.child_timeout = i32(0);
    child.child_status = i32(0);
}

// --- ams_sendtest.FChild..Uninit
void ams_sendtest::FChild_Uninit(ams_sendtest::FChild& child) {
    ams_sendtest::FChild &row = child; (void)row;

    // ams_sendtest.FChild.child.Uninit (Exec)  //
    child_Kill(child); // kill child, ensure forward progress
}

// --- ams_sendtest.trace..Print
// print string representation of ams_sendtest::trace to string LHS, no header -- cprint:ams_sendtest.trace.String
void ams_sendtest::trace_Print(ams_sendtest::trace & row, algo::cstring &str) {
    algo::tempstr temp;
    str << "ams_sendtest.trace";
    (void)row;//only to avoid -Wunused-parameter
}

// --- ams_sendtest.FDb._db.ReadArgv
// Read argc,argv directly into the fields of the command line(s)
// The following fields are updated:
//     ams_sendtest.FDb.cmdline
//     algo_lib.FDb.cmdline
void ams_sendtest::ReadArgv() {
    command::ams_sendtest &cmd = ams_sendtest::_db.cmdline;
    algo_lib::Cmdline &base = algo_lib::_db.cmdline;
    int needarg=-1;// unknown
    int argidx=1;// skip process name
    tempstr err;
    algo::strptr attrname;
    bool isanon=false; // true if attrname is anonfld (positional)
    algo_lib::FieldId baseattrid;
    command::FieldId attrid;
    bool endopt=false;
    int whichns=0;// which namespace does the current attribute belong to
    for (; argidx < algo_lib::_db.argc; argidx++) {
        algo::strptr arg = algo_lib::_db.argv[argidx];
        algo::strptr attrval;
        algo::strptr dfltval;
        bool haveval=false;
        bool dash=elems_N(arg)>1 && arg.elems[0]=='-'; // a single dash is not an option
        // this attribute is a value
        if (endopt || needarg>0 || !dash) {
            attrval=arg;
            haveval=true;
        } else {
            // this attribute is a field name (with - or --)
            // or a -- by itself
            bool dashdash = elems_N(arg) >= 2 && arg.elems[1]=='-';
            int skip = int(dash) + dashdash;
            attrname=ch_RestFrom(arg,skip);
            if (skip==2 && elems_N(arg)==2) {
                endopt=true;
                continue;// nothing else to do here
            }
            // parse "-a:B" arg into attrname,attrvalue
            algo::i32_Range colon = TFind(attrname,':');
            if (colon.beg < colon.end) {
                attrval=ch_RestFrom(attrname,colon.end);
                attrname=ch_FirstN(attrname,colon.beg);
                haveval=true;
            }
            // look up which command (this one or the base) contains the field
            whichns=0;
            needarg=-1;
            // look up parameter information in base namespace (needarg will be -1 if lookup fails)
            if (algo_lib::FieldId_ReadStrptrMaybe(baseattrid,attrname)) {
                needarg = algo_lib::Cmdline_NArgs(baseattrid,dfltval,&isanon);
            }
            if (needarg<0) {
                whichns=1;
                // look up parameter information in this namespace (needarg will be -1 if lookup fails)
                if (command::FieldId_ReadStrptrMaybe(attrid,attrname)) {
                    needarg = command::ams_sendtest_NArgs(attrid,dfltval,&isanon);
                }
            }
            if (attrval == "" && dfltval != "") {
                attrval=dfltval;
                haveval=true;
            }
            if (needarg<0) {
                err<<"ams_sendtest: unknown option "<<Keyval("value",arg)<<eol;
            } else {
            }
        }
        if (ch_N(attrname) == 0) {
            err << "ams_sendtest: too many arguments. error at "<<algo::strptr_ToSsim(arg)<<eol;
        }
        // read value into currently selected arg
        if (haveval) {
            bool ret=false;
            // it's already known which namespace is consuming the args,
            // so directly go there
            if (whichns == 0) {
                ret=algo_lib::Cmdline_ReadFieldMaybe(base, attrname, attrval);
            }
            if (whichns==1) {
                ret=command::ams_sendtest_ReadFieldMaybe(cmd, attrname, attrval);
                switch(attrid.value) {
                    default:break;
                }
            }
            if (!ret) {
                err<<"ams_sendtest: error in "
                <<Keyval("option",attrname)
                <<Keyval("value",attrval)<<eol;
            }
            needarg--;
            if (needarg <= 0) {
                attrname="";// forget which argument was being filled
            }
        }
    }
    bool dohelp = false;
    bool doexit=false;
    if (algo_lib::_db.cmdline.help) {
        dohelp = true;
        doexit = true;
        algo_lib::_db.exit_code = 1; // help exits with non-zero status code
    } else if (algo_lib::_db.cmdline.version) {
        // -ver output goes to stdout
        prlog(algo::gitinfo_Get());
        doexit = true;
    } else if (algo_lib::_db.cmdline.signature) {
        ind_beg(algo_lib::_db_dispsigcheck_curs,dispsigcheck,algo_lib::_db) {
            // dispsig goes to stdout
            dmmeta::Dispsigcheck out;
            dispsigcheck_CopyOut(dispsigcheck,out);
            prlog(out);
        }ind_end
        doexit = true;
    }
    if (!dohelp) {
    }
    if (err != "") {
        algo_lib::_db.exit_code=1;
        prerr(err);
        doexit=true;
    }
    if (dohelp) {
        prlog(ams_sendtest_help);
    }
    if (doexit) {
        _exit(algo_lib::_db.exit_code);
    }
    algo_lib::ResetErrtext();
    vrfy(ams_sendtest::LoadTuplesMaybe(cmd.in,true)
    ,tempstr()<<"where:load_input  "<<algo_lib::DetachBadTags());
}

// --- ams_sendtest.FDb._db.MainLoop
// Main loop.
void ams_sendtest::MainLoop() {
    algo::SchedTime time(algo::get_cycles());
    algo_lib::_db.clock          = time;
    do {
        algo_lib::_db.next_loop.value = algo_lib::_db.limit;
        ams_sendtest::Steps();
    } while (algo_lib::_db.next_loop < algo_lib::_db.limit);
}

// --- ams_sendtest.FDb._db.Step
// Main step
void ams_sendtest::Step() {
}

// --- ams_sendtest.FDb._db.InitReflection
// Load statically available data into tables, register tables and database.
static void ams_sendtest::InitReflection() {
    algo_lib::imdb_InsertMaybe(algo::Imdb("ams_sendtest", NULL, NULL, ams_sendtest::MainLoop, NULL, algo::Comment()));

    algo::Imtable t_trace;
    t_trace.imtable         = "ams_sendtest.trace";
    t_trace.ssimfile        = "";
    t_trace.size            = sizeof(ams_sendtest::trace);
    t_trace.comment.value   = "";
    t_trace.c_RowidFind     = trace_RowidFind;
    t_trace.NItems          = trace_N;
    t_trace.Print           = (algo::ImrowPrintFcn)ams_sendtest::trace_Print;
    algo_lib::imtable_InsertMaybe(t_trace);


    // -- load signatures of existing dispatches --
}

// --- ams_sendtest.FDb._db.StaticCheck
void ams_sendtest::StaticCheck() {
    algo_assert(_offset_of(ams_sendtest::FieldId, value) + sizeof(((ams_sendtest::FieldId*)0)->value) == sizeof(ams_sendtest::FieldId));
}

// --- ams_sendtest.FDb._db.InsertStrptrMaybe
// Parse strptr into known type and add to database.
// Return value is true unless an error occurs. If return value is false, algo_lib::_db.errtext has error text
bool ams_sendtest::InsertStrptrMaybe(algo::strptr str) {
    bool retval = true;
    (void)str;//only to avoid -Wunused-parameter
    return retval;
}

// --- ams_sendtest.FDb._db.LoadTuplesMaybe
// Load all finputs from given directory.
bool ams_sendtest::LoadTuplesMaybe(algo::strptr root, bool recursive) {
    bool retval = true;
    if (FileQ(root)) {
        retval = ams_sendtest::LoadTuplesFile(root, recursive);
    } else if (root == "-") {
        retval = ams_sendtest::LoadTuplesFd(algo::Fildes(0),"(stdin)",recursive);
    } else if (DirectoryQ(root)) {
        retval = retval && ams_sendtest::LoadTuplesFile(algo::SsimFname(root,"dmmeta.dispsigcheck"),recursive);
    } else {
        algo_lib::SaveBadTag("path", root);
        algo_lib::SaveBadTag("comment", "Wrong working directory?");
        retval = false;
    }
    return retval;
}

// --- ams_sendtest.FDb._db.LoadTuplesFile
// Load all finputs from given file.
// Read tuples from file FNAME into this namespace's in-memory database.
// If RECURSIVE is TRUE, then also load these tuples into any parent namespaces
// It a file referred to by FNAME is missing, no error is reported (it's considered an empty set).
// Function returns TRUE if all records were parsed and inserted without error.
// If the function returns FALSE, use algo_lib::DetachBadTags() for error description
bool ams_sendtest::LoadTuplesFile(algo::strptr fname, bool recursive) {
    bool retval = true;
    algo_lib::FFildes fildes;
    // missing files are not an error
    fildes.fd = OpenRead(fname,algo::FileFlags());
    if (ValidQ(fildes.fd)) {
        retval = LoadTuplesFd(fildes.fd, fname, recursive);
    }
    return retval;
}

// --- ams_sendtest.FDb._db.LoadTuplesFd
// Load all finputs from given file descriptor.
bool ams_sendtest::LoadTuplesFd(algo::Fildes fd, algo::strptr fname, bool recursive) {
    bool retval = true;
    ind_beg(algo::FileLine_curs,line,fd) {
        if (recursive) {
            retval = retval && algo_lib::InsertStrptrMaybe(line);
        }
        if (!retval) {
            algo_lib::_db.errtext << eol
            << fname << ":"
            << (ind_curs(line).i+1)
            << ": " << line << eol;
            break;
        }
    }ind_end;
    return retval;
}

// --- ams_sendtest.FDb._db.LoadSsimfileMaybe
// Load specified ssimfile.
bool ams_sendtest::LoadSsimfileMaybe(algo::strptr fname, bool recursive) {
    bool retval = true;
    if (FileQ(fname)) {
        retval = ams_sendtest::LoadTuplesFile(fname, recursive);
    }
    return retval;
}

// --- ams_sendtest.FDb._db.Steps
// Calls Step function of dependencies
void ams_sendtest::Steps() {
    lib_ams::Step(); // dependent namespace specified via (dev.targdep)
    algo_lib::Step(); // dependent namespace specified via (dev.targdep)
}

// --- ams_sendtest.FDb._db.XrefMaybe
// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Caller must Delete or Unref such row.
bool ams_sendtest::_db_XrefMaybe() {
    bool retval = true;
    return retval;
}

// --- ams_sendtest.FDb.child.Alloc
// Allocate memory for new default row.
// If out of memory, process is killed.
ams_sendtest::FChild& ams_sendtest::child_Alloc() {
    ams_sendtest::FChild* row = child_AllocMaybe();
    if (UNLIKELY(row == NULL)) {
        FatalErrorExit("ams_sendtest.out_of_mem  field:ams_sendtest.FDb.child  comment:'Alloc failed'");
    }
    return *row;
}

// --- ams_sendtest.FDb.child.AllocMaybe
// Allocate memory for new element. If out of memory, return NULL.
ams_sendtest::FChild* ams_sendtest::child_AllocMaybe() {
    ams_sendtest::FChild *row = (ams_sendtest::FChild*)child_AllocMem();
    if (row) {
        new (row) ams_sendtest::FChild; // call constructor
    }
    return row;
}

// --- ams_sendtest.FDb.child.AllocMem
// Allocate space for one element. If no memory available, return NULL.
void* ams_sendtest::child_AllocMem() {
    u64 new_nelems     = _db.child_n+1;
    // compute level and index on level
    u64 bsr   = algo::u64_BitScanReverse(new_nelems);
    u64 base  = u64(1)<<bsr;
    u64 index = new_nelems-base;
    void *ret = NULL;
    // if level doesn't exist yet, create it
    ams_sendtest::FChild*  lev   = NULL;
    if (bsr < 32) {
        lev = _db.child_lary[bsr];
        if (!lev) {
            lev=(ams_sendtest::FChild*)algo_lib::malloc_AllocMem(sizeof(ams_sendtest::FChild) * (u64(1)<<bsr));
            _db.child_lary[bsr] = lev;
        }
    }
    // allocate element from this level
    if (lev) {
        _db.child_n = i32(new_nelems);
        ret = lev + index;
    }
    return ret;
}

// --- ams_sendtest.FDb.child.RemoveAll
// Remove all elements from Lary
void ams_sendtest::child_RemoveAll() {
    for (u64 n = _db.child_n; n>0; ) {
        n--;
        child_qFind(u64(n)).~FChild(); // destroy last element
        _db.child_n = i32(n);
    }
}

// --- ams_sendtest.FDb.child.RemoveLast
// Delete last element of array. Do nothing if array is empty.
void ams_sendtest::child_RemoveLast() {
    u64 n = _db.child_n;
    if (n > 0) {
        n -= 1;
        child_qFind(u64(n)).~FChild();
        _db.child_n = i32(n);
    }
}

// --- ams_sendtest.FDb.child.XrefMaybe
// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Caller must Delete or Unref such row.
bool ams_sendtest::child_XrefMaybe(ams_sendtest::FChild &row) {
    bool retval = true;
    (void)row;
    return retval;
}

// --- ams_sendtest.FDb.trace.RowidFind
// find trace by row id (used to implement reflection)
static algo::ImrowPtr ams_sendtest::trace_RowidFind(int t) {
    return algo::ImrowPtr(t==0 ? u64(&_db.trace) : u64(0));
}

// --- ams_sendtest.FDb.trace.N
// Function return 1
inline static i32 ams_sendtest::trace_N() {
    return 1;
}

// --- ams_sendtest.FDb..Init
// Set all fields to initial values.
void ams_sendtest::FDb_Init() {
    _db.c_out = NULL;
    // initialize LAry child (ams_sendtest.FDb.child)
    _db.child_n = 0;
    memset(_db.child_lary, 0, sizeof(_db.child_lary)); // zero out all level pointers
    ams_sendtest::FChild* child_first = (ams_sendtest::FChild*)algo_lib::malloc_AllocMem(sizeof(ams_sendtest::FChild) * (u64(1)<<4));
    if (!child_first) {
        FatalErrorExit("out of memory");
    }
    for (int i = 0; i < 4; i++) {
        _db.child_lary[i]  = child_first;
        child_first    += 1ULL<<i;
    }

    ams_sendtest::InitReflection();
}

// --- ams_sendtest.FDb..Uninit
void ams_sendtest::FDb_Uninit() {
    ams_sendtest::FDb &row = _db; (void)row;

    // ams_sendtest.FDb.child.Uninit (Lary)  //
    // skip destruction in global scope
}

// --- ams_sendtest.FieldId.value.ToCstr
// Convert numeric value of field to one of predefined string constants.
// If string is found, return a static C string. Otherwise, return NULL.
const char* ams_sendtest::value_ToCstr(const ams_sendtest::FieldId& parent) {
    const char *ret = NULL;
    switch(value_GetEnum(parent)) {
        case ams_sendtest_FieldId_value    : ret = "value";  break;
    }
    return ret;
}

// --- ams_sendtest.FieldId.value.Print
// Convert value to a string. First, attempt conversion to a known string.
// If no string matches, print value as a numeric value.
void ams_sendtest::value_Print(const ams_sendtest::FieldId& parent, algo::cstring &lhs) {
    const char *strval = value_ToCstr(parent);
    if (strval) {
        lhs << strval;
    } else {
        lhs << parent.value;
    }
}

// --- ams_sendtest.FieldId.value.SetStrptrMaybe
// Convert string to field.
// If the string is invalid, do not modify field and return false.
// In case of success, return true
bool ams_sendtest::value_SetStrptrMaybe(ams_sendtest::FieldId& parent, algo::strptr rhs) {
    bool ret = false;
    switch (elems_N(rhs)) {
        case 5: {
            switch (u64(algo::ReadLE32(rhs.elems))|(u64(rhs[4])<<32)) {
                case LE_STR5('v','a','l','u','e'): {
                    value_SetEnum(parent,ams_sendtest_FieldId_value); ret = true; break;
                }
            }
            break;
        }
    }
    return ret;
}

// --- ams_sendtest.FieldId.value.SetStrptr
// Convert string to field.
// If the string is invalid, set numeric value to DFLT
void ams_sendtest::value_SetStrptr(ams_sendtest::FieldId& parent, algo::strptr rhs, ams_sendtest_FieldIdEnum dflt) {
    if (!value_SetStrptrMaybe(parent,rhs)) value_SetEnum(parent,dflt);
}

// --- ams_sendtest.FieldId.value.ReadStrptrMaybe
// Convert string to field. Return success value
bool ams_sendtest::value_ReadStrptrMaybe(ams_sendtest::FieldId& parent, algo::strptr rhs) {
    bool retval = false;
    retval = value_SetStrptrMaybe(parent,rhs); // try symbol conversion
    if (!retval) { // didn't work? try reading as underlying type
        retval = i32_ReadStrptrMaybe(parent.value,rhs);
    }
    return retval;
}

// --- ams_sendtest.FieldId..ReadStrptrMaybe
// Read fields of ams_sendtest::FieldId from an ascii string.
// The format of the string is the format of the ams_sendtest::FieldId's only field
bool ams_sendtest::FieldId_ReadStrptrMaybe(ams_sendtest::FieldId &parent, algo::strptr in_str) {
    bool retval = true;
    retval = retval && value_ReadStrptrMaybe(parent, in_str);
    return retval;
}

// --- ams_sendtest.FieldId..Print
// print string representation of ams_sendtest::FieldId to string LHS, no header -- cprint:ams_sendtest.FieldId.String
void ams_sendtest::FieldId_Print(ams_sendtest::FieldId & row, algo::cstring &str) {
    ams_sendtest::value_Print(row, str);
}

// --- ams_sendtest...SizeCheck
inline static void ams_sendtest::SizeCheck() {
}

// --- ams_sendtest...main
int main(int argc, char **argv) {
    try {
        lib_json::FDb_Init();
        algo_lib::FDb_Init();
        lib_ams::FDb_Init();
        ams_sendtest::FDb_Init();
        algo_lib::_db.argc = argc;
        algo_lib::_db.argv = argv;
        algo_lib::IohookInit();
        ams_sendtest::ReadArgv(); // dmmeta.main:ams_sendtest
        ams_sendtest::Main(); // user-defined main
    } catch(algo_lib::ErrorX &x) {
        prerr("ams_sendtest.error  " << x); // there may be additional hints in DetachBadTags
        algo_lib::_db.exit_code = 1;
    }
    if (algo_lib::_db.last_signal) {
        algo_lib::_db.exit_code = 1;
    }
    try {
        ams_sendtest::FDb_Uninit();
        lib_ams::FDb_Uninit();
        algo_lib::FDb_Uninit();
        lib_json::FDb_Uninit();
    } catch(algo_lib::ErrorX &) {
        // don't print anything, might crash
        algo_lib::_db.exit_code = 1;
    }
    // only the lower 1 byte makes it to the outside world
    (void)i32_UpdateMin(algo_lib::_db.exit_code,255);
    return algo_lib::_db.exit_code;
}

// --- ams_sendtest...WinMain
#if defined(WIN32)
int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int) {
    return main(__argc,__argv);
}
#endif
