//
// cpp/gen/bash2html_gen.cpp
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
#include "include/gen/bash2html_gen.h"
#include "include/gen/bash2html_gen.inl.h"
#include "include/gen/command_gen.h"
#include "include/gen/command_gen.inl.h"
#include "include/gen/lib_json_gen.h"
#include "include/gen/lib_json_gen.inl.h"
#include "include/gen/algo_lib_gen.h"
#include "include/gen/algo_lib_gen.inl.h"
//#pragma endinclude

// Instantiate all libraries linked into this executable,
// in dependency order
lib_json::FDb    lib_json::_db;     // dependency found via dev.targdep
algo_lib::FDb    algo_lib::_db;     // dependency found via dev.targdep
bash2html::FDb   bash2html::_db;    // dependency found via dev.targdep

namespace bash2html {
const char *bash2html_help =
"bash2html: Convert bash output and colours to html\n"
"Usage: bash2html [options]\n"
"    OPTION      TYPE    DFLT    COMMENT\n"
"    -in         string  \"data\"  Input directory or filename, - for stdin\n"
"    -test                       Produce Test Output\n"
"    -verbose    int             Verbosity level (0..255); alias -v; cumulative\n"
"    -debug      int             Debug level (0..255); alias -d; cumulative\n"
"    -help                       Print help and exit; alias -h\n"
"    -version                    Print version and exit\n"
"    -signature                  Show signatures and exit; alias -sig\n"
;


} // namespace bash2html
namespace bash2html { // gen:ns_print_proto
    // Load statically available data into tables, register tables and database.
    // func:bash2html.FDb._db.InitReflection
    static void          InitReflection();
    // find trace by row id (used to implement reflection)
    // func:bash2html.FDb.trace.RowidFind
    static algo::ImrowPtr trace_RowidFind(int t) __attribute__((nothrow));
    // Function return 1
    // func:bash2html.FDb.trace.N
    static i32           trace_N() __attribute__((__warn_unused_result__, nothrow, pure));
    // func:bash2html...SizeCheck
    static void          SizeCheck();
} // gen:ns_print_proto

// --- bash2html.trace..Print
// print string representation of ROW to string STR
// cfmt:bash2html.trace.String  printfmt:Tuple
void bash2html::trace_Print(bash2html::trace& row, algo::cstring& str) {
    algo::tempstr temp;
    str << "bash2html.trace";
    (void)row;//only to avoid -Wunused-parameter
}

// --- bash2html.FDb._db.ReadArgv
// Read argc,argv directly into the fields of the command line(s)
// The following fields are updated:
//     bash2html.FDb.cmdline
//     algo_lib.FDb.cmdline
void bash2html::ReadArgv() {
    command::bash2html &cmd = bash2html::_db.cmdline;
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
                    needarg = command::bash2html_NArgs(attrid,dfltval,&isanon);
                }
            }
            if (attrval == "" && dfltval != "") {
                attrval=dfltval;
                haveval=true;
            }
            if (needarg<0) {
                err<<"bash2html: unknown option "<<Keyval("value",arg)<<eol;
            } else {
            }
        }
        if (ch_N(attrname) == 0) {
            err << "bash2html: too many arguments. error at "<<algo::strptr_ToSsim(arg)<<eol;
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
                ret=command::bash2html_ReadFieldMaybe(cmd, attrname, attrval);
                switch(attrid.value) {
                    default:break;
                }
            }
            if (!ret) {
                err<<"bash2html: error in "
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
    // dmmeta.floadtuples:bash2html.FDb.cmdline
    if (!dohelp && err=="") {
        algo_lib::ResetErrtext();
        if (!bash2html::LoadTuplesMaybe(cmd.in,true)) {
            err << "bash2html.load_input  "<<algo_lib::DetachBadTags()<<eol;
        }
    }
    if (err != "") {
        algo_lib::_db.exit_code=1;
        prerr(err);
        doexit=true;
    }
    if (dohelp) {
        prlog(bash2html_help);
    }
    if (doexit) {
        _exit(algo_lib::_db.exit_code);
    }
    algo_lib::ResetErrtext();
}

// --- bash2html.FDb._db.MainLoop
// Main loop.
void bash2html::MainLoop() {
    algo::SchedTime time(algo::get_cycles());
    algo_lib::_db.clock          = time;
    do {
        algo_lib::_db.next_loop.value = algo_lib::_db.limit;
        bash2html::Steps();
    } while (algo_lib::_db.next_loop < algo_lib::_db.limit);
}

// --- bash2html.FDb._db.Step
// Main step
void bash2html::Step() {
}

// --- bash2html.FDb._db.InitReflection
// Load statically available data into tables, register tables and database.
static void bash2html::InitReflection() {
    algo_lib::imdb_InsertMaybe(algo::Imdb("bash2html", NULL, NULL, bash2html::MainLoop, NULL, algo::Comment()));

    algo::Imtable t_trace;
    t_trace.imtable         = "bash2html.trace";
    t_trace.ssimfile        = "";
    t_trace.size            = sizeof(bash2html::trace);
    t_trace.comment.value   = "";
    t_trace.c_RowidFind     = trace_RowidFind;
    t_trace.NItems          = trace_N;
    t_trace.Print           = (algo::ImrowPrintFcn)bash2html::trace_Print;
    algo_lib::imtable_InsertMaybe(t_trace);


    // -- load signatures of existing dispatches --
}

// --- bash2html.FDb._db.StaticCheck
void bash2html::StaticCheck() {
    algo_assert(_offset_of(bash2html::FieldId, value) + sizeof(((bash2html::FieldId*)0)->value) == sizeof(bash2html::FieldId));
}

// --- bash2html.FDb._db.InsertStrptrMaybe
// Parse strptr into known type and add to database.
// Return value is true unless an error occurs. If return value is false, algo_lib::_db.errtext has error text
bool bash2html::InsertStrptrMaybe(algo::strptr str) {
    bool retval = true;
    (void)str;//only to avoid -Wunused-parameter
    return retval;
}

// --- bash2html.FDb._db.LoadTuplesMaybe
// Load all finputs from given directory.
bool bash2html::LoadTuplesMaybe(algo::strptr root, bool recursive) {
    bool retval = true;
    if (FileQ(root)) {
        retval = bash2html::LoadTuplesFile(root, recursive);
    } else if (root == "-") {
        retval = bash2html::LoadTuplesFd(algo::Fildes(0),"(stdin)",recursive);
    } else if (DirectoryQ(root)) {
        retval = retval && bash2html::LoadTuplesFile(algo::SsimFname(root,"dmmeta.dispsigcheck"),recursive);
    } else {
        algo_lib::SaveBadTag("path", root);
        algo_lib::SaveBadTag("comment", "Wrong working directory?");
        retval = false;
    }
    return retval;
}

// --- bash2html.FDb._db.LoadTuplesFile
// Load all finputs from given file.
// Read tuples from file FNAME into this namespace's in-memory database.
// If RECURSIVE is TRUE, then also load these tuples into any parent namespaces
// It a file referred to by FNAME is missing, no error is reported (it's considered an empty set).
// Function returns TRUE if all records were parsed and inserted without error.
// If the function returns FALSE, use algo_lib::DetachBadTags() for error description
bool bash2html::LoadTuplesFile(algo::strptr fname, bool recursive) {
    bool retval = true;
    algo_lib::FFildes fildes;
    // missing files are not an error
    fildes.fd = OpenRead(fname,algo::FileFlags());
    if (ValidQ(fildes.fd)) {
        retval = LoadTuplesFd(fildes.fd, fname, recursive);
    }
    return retval;
}

// --- bash2html.FDb._db.LoadTuplesFd
// Load all finputs from given file descriptor.
bool bash2html::LoadTuplesFd(algo::Fildes fd, algo::strptr fname, bool recursive) {
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

// --- bash2html.FDb._db.LoadSsimfileMaybe
// Load specified ssimfile.
bool bash2html::LoadSsimfileMaybe(algo::strptr fname, bool recursive) {
    bool retval = true;
    if (FileQ(fname)) {
        retval = bash2html::LoadTuplesFile(fname, recursive);
    }
    return retval;
}

// --- bash2html.FDb._db.Steps
// Calls Step function of dependencies
void bash2html::Steps() {
    algo_lib::Step(); // dependent namespace specified via (dev.targdep)
}

// --- bash2html.FDb._db.XrefMaybe
// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Caller must Delete or Unref such row.
bool bash2html::_db_XrefMaybe() {
    bool retval = true;
    return retval;
}

// --- bash2html.FDb.trace.RowidFind
// find trace by row id (used to implement reflection)
static algo::ImrowPtr bash2html::trace_RowidFind(int t) {
    return algo::ImrowPtr(t==0 ? u64(&_db.trace) : u64(0));
}

// --- bash2html.FDb.trace.N
// Function return 1
inline static i32 bash2html::trace_N() {
    return 1;
}

// --- bash2html.FDb..Init
// Set all fields to initial values.
void bash2html::FDb_Init() {

    bash2html::InitReflection();
}

// --- bash2html.FDb..Uninit
void bash2html::FDb_Uninit() {
    bash2html::FDb &row = _db; (void)row;
}

// --- bash2html.FieldId.value.ToCstr
// Convert numeric value of field to one of predefined string constants.
// If string is found, return a static C string. Otherwise, return NULL.
const char* bash2html::value_ToCstr(const bash2html::FieldId& parent) {
    const char *ret = NULL;
    switch(value_GetEnum(parent)) {
        case bash2html_FieldId_value       : ret = "value";  break;
    }
    return ret;
}

// --- bash2html.FieldId.value.Print
// Convert value to a string. First, attempt conversion to a known string.
// If no string matches, print value as a numeric value.
void bash2html::value_Print(const bash2html::FieldId& parent, algo::cstring &lhs) {
    const char *strval = value_ToCstr(parent);
    if (strval) {
        lhs << strval;
    } else {
        lhs << parent.value;
    }
}

// --- bash2html.FieldId.value.SetStrptrMaybe
// Convert string to field.
// If the string is invalid, do not modify field and return false.
// In case of success, return true
bool bash2html::value_SetStrptrMaybe(bash2html::FieldId& parent, algo::strptr rhs) {
    bool ret = false;
    switch (elems_N(rhs)) {
        case 5: {
            switch (u64(algo::ReadLE32(rhs.elems))|(u64(rhs[4])<<32)) {
                case LE_STR5('v','a','l','u','e'): {
                    value_SetEnum(parent,bash2html_FieldId_value); ret = true; break;
                }
            }
            break;
        }
    }
    return ret;
}

// --- bash2html.FieldId.value.SetStrptr
// Convert string to field.
// If the string is invalid, set numeric value to DFLT
void bash2html::value_SetStrptr(bash2html::FieldId& parent, algo::strptr rhs, bash2html_FieldIdEnum dflt) {
    if (!value_SetStrptrMaybe(parent,rhs)) value_SetEnum(parent,dflt);
}

// --- bash2html.FieldId.value.ReadStrptrMaybe
// Convert string to field. Return success value
bool bash2html::value_ReadStrptrMaybe(bash2html::FieldId& parent, algo::strptr rhs) {
    bool retval = false;
    retval = value_SetStrptrMaybe(parent,rhs); // try symbol conversion
    if (!retval) { // didn't work? try reading as underlying type
        retval = i32_ReadStrptrMaybe(parent.value,rhs);
    }
    return retval;
}

// --- bash2html.FieldId..ReadStrptrMaybe
// Read fields of bash2html::FieldId from an ascii string.
// The format of the string is the format of the bash2html::FieldId's only field
bool bash2html::FieldId_ReadStrptrMaybe(bash2html::FieldId &parent, algo::strptr in_str) {
    bool retval = true;
    retval = retval && value_ReadStrptrMaybe(parent, in_str);
    return retval;
}

// --- bash2html.FieldId..Print
// print string representation of ROW to string STR
// cfmt:bash2html.FieldId.String  printfmt:Raw
void bash2html::FieldId_Print(bash2html::FieldId& row, algo::cstring& str) {
    bash2html::value_Print(row, str);
}

// --- bash2html...SizeCheck
inline static void bash2html::SizeCheck() {
}

// --- bash2html...main
int main(int argc, char **argv) {
    try {
        lib_json::FDb_Init();
        algo_lib::FDb_Init();
        bash2html::FDb_Init();
        algo_lib::_db.argc = argc;
        algo_lib::_db.argv = argv;
        algo_lib::IohookInit();
        bash2html::ReadArgv(); // dmmeta.main:bash2html
        bash2html::Main(); // user-defined main
    } catch(algo_lib::ErrorX &x) {
        prerr("bash2html.error  " << x); // there may be additional hints in DetachBadTags
        algo_lib::_db.exit_code = 1;
    }
    if (algo_lib::_db.last_signal) {
        algo_lib::_db.exit_code = 1;
    }
    try {
        bash2html::FDb_Uninit();
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

// --- bash2html...WinMain
#if defined(WIN32)
int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int) {
    return main(__argc,__argv);
}
#endif
