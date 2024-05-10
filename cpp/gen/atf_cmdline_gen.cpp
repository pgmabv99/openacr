//
// cpp/gen/atf_cmdline_gen.cpp
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
#include "include/gen/atf_cmdline_gen.h"
#include "include/gen/atf_cmdline_gen.inl.h"
#include "include/gen/command_gen.h"
#include "include/gen/command_gen.inl.h"
#include "include/gen/lib_json_gen.h"
#include "include/gen/lib_json_gen.inl.h"
#include "include/gen/algo_lib_gen.h"
#include "include/gen/algo_lib_gen.inl.h"
//#pragma endinclude

// Instantiate all libraries linked into this executable,
// in dependency order
lib_json::FDb      lib_json::_db;       // dependency found via dev.targdep
algo_lib::FDb      algo_lib::_db;       // dependency found via dev.targdep
atf_cmdline::FDb   atf_cmdline::_db;    // dependency found via dev.targdep

namespace atf_cmdline {
const char *atf_cmdline_help =
"atf_cmdline: Test tool for command line parsing\n"
"Usage: atf_cmdline [-astr:]<string> [[-anum:]<int>] [[-adbl:]<double>] -str:<string> [[-amnum:]<int>] [options]\n"
"    OPTION      TYPE    DFLT    COMMENT\n"
"    -in         string  \"data\"  Input directory or filename, - for stdin\n"
"    -exec                       Execv itself\n"
"    [astr]      string          Required anon string\n"
"    [anum]      int     0       Anon number\n"
"    [adbl]      double  0.0     Anon double\n"
"    [aflag]                     Anon flag\n"
"    -str        string          Required string\n"
"    -num        int     0       Required Number\n"
"    -dbl        double  0.0     Required double\n"
"    -flag                       Required flag\n"
"    -dstr       string  \"blah\"  Predefined string\n"
"    -dnum       int     -33     Predefined number\n"
"    -ddbl       double  0.0001  Predefined double\n"
"    -dflag              Y       Predefined flag\n"
"    -mstr...    string          String array\n"
"    -mnum...    int             Number array\n"
"    -mdbl...    double          Double array\n"
"    [amnum]...  int             Anon number array\n"
"    -fconst     int     high    Fconst for field (high|medium|low)\n"
"                                    high  Cool\n"
"                                    medium  So-so\n"
"                                    low  Bad\n"
"    -cconst     enum    None    Fconst for arg ctype (January|February|March|April|May|June|July|August|September|October|November|December|None)\n"
"    -dregx      regx    \"%\"     Predefined regx\n"
"    -dpkey      string  \"\"      Predefined pkey\n"
"    -verbose    int             Verbosity level (0..255); alias -v; cumulative\n"
"    -debug      int             Debug level (0..255); alias -d; cumulative\n"
"    -help                       Print help and exit; alias -h\n"
"    -version                    Print version and exit\n"
"    -signature                  Show signatures and exit; alias -sig\n"
;


} // namespace atf_cmdline
namespace atf_cmdline { // gen:ns_print_proto
    // Load statically available data into tables, register tables and database.
    // func:atf_cmdline.FDb._db.InitReflection
    static void          InitReflection();
    // find trace by row id (used to implement reflection)
    // func:atf_cmdline.FDb.trace.RowidFind
    static algo::ImrowPtr trace_RowidFind(int t) __attribute__((nothrow));
    // Function return 1
    // func:atf_cmdline.FDb.trace.N
    static i32           trace_N() __attribute__((__warn_unused_result__, nothrow, pure));
    // func:atf_cmdline...SizeCheck
    static void          SizeCheck();
} // gen:ns_print_proto

// --- atf_cmdline.trace..Print
// print string representation of ROW to string STR
// cfmt:atf_cmdline.trace.String  printfmt:Tuple
void atf_cmdline::trace_Print(atf_cmdline::trace& row, algo::cstring& str) {
    algo::tempstr temp;
    str << "atf_cmdline.trace";
    (void)row;//only to avoid -Wunused-parameter
}

// --- atf_cmdline.FDb._db.ReadArgv
// Read argc,argv directly into the fields of the command line(s)
// The following fields are updated:
//     atf_cmdline.FDb.cmdline
//     algo_lib.FDb.cmdline
void atf_cmdline::ReadArgv() {
    command::atf_cmdline &cmd = atf_cmdline::_db.cmdline;
    algo_lib::Cmdline &base = algo_lib::_db.cmdline;
    int needarg=-1;// unknown
    int argidx=1;// skip process name
    int anonidx=0;
    algo::strptr nextanon = command::atf_cmdline_GetAnon(cmd, anonidx);
    tempstr err;
    algo::strptr attrname;
    bool isanon=false; // true if attrname is anonfld (positional)
    algo_lib::FieldId baseattrid;
    command::FieldId attrid;
    bool endopt=false;
    int whichns=0;// which namespace does the current attribute belong to
    bool astr_present = false;
    bool str_present = false;
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
                    needarg = command::atf_cmdline_NArgs(attrid,dfltval,&isanon);
                }
            }
            if (attrval == "" && dfltval != "") {
                attrval=dfltval;
                haveval=true;
            }
            if (needarg<0) {
                err<<"atf_cmdline: unknown option "<<Keyval("value",arg)<<eol;
            } else {
                if (isanon) {
                    if (attrname == nextanon) { // treat named anon (positional) argument as unnamed
                        attrname = ""; // treat it as unnamed
                    } else if (nextanon != "") { // disallow out-of-order anon (positional) args
                        err<<"atf_cmdline: error at "<<algo::strptr_ToSsim(arg)<<": must be preceded by [-"<<nextanon<<"]"<<eol;
                    }
                }
            }
        }
        // look up anon field name based on index
        // anon fields are only allowed in the leaf ns, never base
        if (ch_N(attrname) == 0) {
            attrname = nextanon;
            nextanon = command::atf_cmdline_GetAnon(cmd, ++anonidx);
            command::FieldId_ReadStrptrMaybe(attrid,attrname);
            whichns=1;
        }
        if (ch_N(attrname) == 0) {
            err << "atf_cmdline: too many arguments. error at "<<algo::strptr_ToSsim(arg)<<eol;
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
                ret=command::atf_cmdline_ReadFieldMaybe(cmd, attrname, attrval);
                switch(attrid.value) {
                    case command_FieldId_astr: astr_present=true; break;
                    case command_FieldId_str: str_present=true; break;
                    default:break;
                }
            }
            if (!ret) {
                err<<"atf_cmdline: error in "
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
        if (!astr_present) {
            err << "atf_cmdline: Missing value for required argument -astr (see -help)" << eol;
            doexit = true;
        }
        if (!str_present) {
            err << "atf_cmdline: Missing value for required argument -str (see -help)" << eol;
            doexit = true;
        }
    }
    // dmmeta.floadtuples:atf_cmdline.FDb.cmdline
    if (!dohelp && err=="") {
        algo_lib::ResetErrtext();
        if (!atf_cmdline::LoadTuplesMaybe(cmd.in,true)) {
            err << "atf_cmdline.load_input  "<<algo_lib::DetachBadTags()<<eol;
        }
    }
    if (err != "") {
        algo_lib::_db.exit_code=1;
        prerr(err);
        doexit=true;
    }
    if (dohelp) {
        prlog(atf_cmdline_help);
    }
    if (doexit) {
        _exit(algo_lib::_db.exit_code);
    }
    algo_lib::ResetErrtext();
}

// --- atf_cmdline.FDb._db.MainLoop
// Main loop.
void atf_cmdline::MainLoop() {
    algo::SchedTime time(algo::get_cycles());
    algo_lib::_db.clock          = time;
    do {
        algo_lib::_db.next_loop.value = algo_lib::_db.limit;
        atf_cmdline::Steps();
    } while (algo_lib::_db.next_loop < algo_lib::_db.limit);
}

// --- atf_cmdline.FDb._db.Step
// Main step
void atf_cmdline::Step() {
}

// --- atf_cmdline.FDb._db.InitReflection
// Load statically available data into tables, register tables and database.
static void atf_cmdline::InitReflection() {
    algo_lib::imdb_InsertMaybe(algo::Imdb("atf_cmdline", NULL, NULL, atf_cmdline::MainLoop, NULL, algo::Comment()));

    algo::Imtable t_trace;
    t_trace.imtable         = "atf_cmdline.trace";
    t_trace.ssimfile        = "";
    t_trace.size            = sizeof(atf_cmdline::trace);
    t_trace.comment.value   = "";
    t_trace.c_RowidFind     = trace_RowidFind;
    t_trace.NItems          = trace_N;
    t_trace.Print           = (algo::ImrowPrintFcn)atf_cmdline::trace_Print;
    algo_lib::imtable_InsertMaybe(t_trace);


    // -- load signatures of existing dispatches --
}

// --- atf_cmdline.FDb._db.InsertStrptrMaybe
// Parse strptr into known type and add to database.
// Return value is true unless an error occurs. If return value is false, algo_lib::_db.errtext has error text
bool atf_cmdline::InsertStrptrMaybe(algo::strptr str) {
    bool retval = true;
    (void)str;//only to avoid -Wunused-parameter
    return retval;
}

// --- atf_cmdline.FDb._db.LoadTuplesMaybe
// Load all finputs from given directory.
bool atf_cmdline::LoadTuplesMaybe(algo::strptr root, bool recursive) {
    bool retval = true;
    if (FileQ(root)) {
        retval = atf_cmdline::LoadTuplesFile(root, recursive);
    } else if (root == "-") {
        retval = atf_cmdline::LoadTuplesFd(algo::Fildes(0),"(stdin)",recursive);
    } else if (DirectoryQ(root)) {
        retval = retval && atf_cmdline::LoadTuplesFile(algo::SsimFname(root,"dmmeta.dispsigcheck"),recursive);
    } else {
        algo_lib::SaveBadTag("path", root);
        algo_lib::SaveBadTag("comment", "Wrong working directory?");
        retval = false;
    }
    return retval;
}

// --- atf_cmdline.FDb._db.LoadTuplesFile
// Load all finputs from given file.
// Read tuples from file FNAME into this namespace's in-memory database.
// If RECURSIVE is TRUE, then also load these tuples into any parent namespaces
// It a file referred to by FNAME is missing, no error is reported (it's considered an empty set).
// Function returns TRUE if all records were parsed and inserted without error.
// If the function returns FALSE, use algo_lib::DetachBadTags() for error description
bool atf_cmdline::LoadTuplesFile(algo::strptr fname, bool recursive) {
    bool retval = true;
    algo_lib::FFildes fildes;
    // missing files are not an error
    fildes.fd = OpenRead(fname,algo::FileFlags());
    if (ValidQ(fildes.fd)) {
        retval = LoadTuplesFd(fildes.fd, fname, recursive);
    }
    return retval;
}

// --- atf_cmdline.FDb._db.LoadTuplesFd
// Load all finputs from given file descriptor.
bool atf_cmdline::LoadTuplesFd(algo::Fildes fd, algo::strptr fname, bool recursive) {
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

// --- atf_cmdline.FDb._db.LoadSsimfileMaybe
// Load specified ssimfile.
bool atf_cmdline::LoadSsimfileMaybe(algo::strptr fname, bool recursive) {
    bool retval = true;
    if (FileQ(fname)) {
        retval = atf_cmdline::LoadTuplesFile(fname, recursive);
    }
    return retval;
}

// --- atf_cmdline.FDb._db.Steps
// Calls Step function of dependencies
void atf_cmdline::Steps() {
    algo_lib::Step(); // dependent namespace specified via (dev.targdep)
}

// --- atf_cmdline.FDb._db.XrefMaybe
// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Caller must Delete or Unref such row.
bool atf_cmdline::_db_XrefMaybe() {
    bool retval = true;
    return retval;
}

// --- atf_cmdline.FDb.trace.RowidFind
// find trace by row id (used to implement reflection)
static algo::ImrowPtr atf_cmdline::trace_RowidFind(int t) {
    return algo::ImrowPtr(t==0 ? u64(&_db.trace) : u64(0));
}

// --- atf_cmdline.FDb.trace.N
// Function return 1
inline static i32 atf_cmdline::trace_N() {
    return 1;
}

// --- atf_cmdline.FDb..Init
// Set all fields to initial values.
void atf_cmdline::FDb_Init() {

    atf_cmdline::InitReflection();
}

// --- atf_cmdline.FDb..Uninit
void atf_cmdline::FDb_Uninit() {
    atf_cmdline::FDb &row = _db; (void)row;
}

// --- atf_cmdline.FieldId.value.ToCstr
// Convert numeric value of field to one of predefined string constants.
// If string is found, return a static C string. Otherwise, return NULL.
const char* atf_cmdline::value_ToCstr(const atf_cmdline::FieldId& parent) {
    const char *ret = NULL;
    switch(value_GetEnum(parent)) {
        case atf_cmdline_FieldId_value     : ret = "value";  break;
    }
    return ret;
}

// --- atf_cmdline.FieldId.value.Print
// Convert value to a string. First, attempt conversion to a known string.
// If no string matches, print value as a numeric value.
void atf_cmdline::value_Print(const atf_cmdline::FieldId& parent, algo::cstring &lhs) {
    const char *strval = value_ToCstr(parent);
    if (strval) {
        lhs << strval;
    } else {
        lhs << parent.value;
    }
}

// --- atf_cmdline.FieldId.value.SetStrptrMaybe
// Convert string to field.
// If the string is invalid, do not modify field and return false.
// In case of success, return true
bool atf_cmdline::value_SetStrptrMaybe(atf_cmdline::FieldId& parent, algo::strptr rhs) {
    bool ret = false;
    switch (elems_N(rhs)) {
        case 5: {
            switch (u64(algo::ReadLE32(rhs.elems))|(u64(rhs[4])<<32)) {
                case LE_STR5('v','a','l','u','e'): {
                    value_SetEnum(parent,atf_cmdline_FieldId_value); ret = true; break;
                }
            }
            break;
        }
    }
    return ret;
}

// --- atf_cmdline.FieldId.value.SetStrptr
// Convert string to field.
// If the string is invalid, set numeric value to DFLT
void atf_cmdline::value_SetStrptr(atf_cmdline::FieldId& parent, algo::strptr rhs, atf_cmdline_FieldIdEnum dflt) {
    if (!value_SetStrptrMaybe(parent,rhs)) value_SetEnum(parent,dflt);
}

// --- atf_cmdline.FieldId.value.ReadStrptrMaybe
// Convert string to field. Return success value
bool atf_cmdline::value_ReadStrptrMaybe(atf_cmdline::FieldId& parent, algo::strptr rhs) {
    bool retval = false;
    retval = value_SetStrptrMaybe(parent,rhs); // try symbol conversion
    if (!retval) { // didn't work? try reading as underlying type
        retval = i32_ReadStrptrMaybe(parent.value,rhs);
    }
    return retval;
}

// --- atf_cmdline.FieldId..ReadStrptrMaybe
// Read fields of atf_cmdline::FieldId from an ascii string.
// The format of the string is the format of the atf_cmdline::FieldId's only field
bool atf_cmdline::FieldId_ReadStrptrMaybe(atf_cmdline::FieldId &parent, algo::strptr in_str) {
    bool retval = true;
    retval = retval && value_ReadStrptrMaybe(parent, in_str);
    return retval;
}

// --- atf_cmdline.FieldId..Print
// print string representation of ROW to string STR
// cfmt:atf_cmdline.FieldId.String  printfmt:Raw
void atf_cmdline::FieldId_Print(atf_cmdline::FieldId& row, algo::cstring& str) {
    atf_cmdline::value_Print(row, str);
}

// --- atf_cmdline...SizeCheck
inline static void atf_cmdline::SizeCheck() {
}

// --- atf_cmdline...StaticCheck
void atf_cmdline::StaticCheck() {
    algo_assert(_offset_of(atf_cmdline::FieldId, value) + sizeof(((atf_cmdline::FieldId*)0)->value) == sizeof(atf_cmdline::FieldId));
}

// --- atf_cmdline...main
int main(int argc, char **argv) {
    try {
        lib_json::FDb_Init();
        algo_lib::FDb_Init();
        atf_cmdline::FDb_Init();
        algo_lib::_db.argc = argc;
        algo_lib::_db.argv = argv;
        algo_lib::IohookInit();
        atf_cmdline::ReadArgv(); // dmmeta.main:atf_cmdline
        atf_cmdline::Main(); // user-defined main
    } catch(algo_lib::ErrorX &x) {
        prerr("atf_cmdline.error  " << x); // there may be additional hints in DetachBadTags
        algo_lib::_db.exit_code = 1;
    }
    if (algo_lib::_db.last_signal) {
        algo_lib::_db.exit_code = 1;
    }
    try {
        atf_cmdline::FDb_Uninit();
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

// --- atf_cmdline...WinMain
#if defined(WIN32)
int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int) {
    return main(__argc,__argv);
}
#endif
