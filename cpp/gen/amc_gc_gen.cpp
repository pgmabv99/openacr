//
// cpp/gen/amc_gc_gen.cpp
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
#include "include/gen/amc_gc_gen.h"
#include "include/gen/amc_gc_gen.inl.h"
#include "include/gen/command_gen.h"
#include "include/gen/command_gen.inl.h"
#include "include/gen/algo_gen.h"
#include "include/gen/algo_gen.inl.h"
#include "include/gen/lib_json_gen.h"
#include "include/gen/lib_json_gen.inl.h"
#include "include/gen/lib_prot_gen.h"
#include "include/gen/lib_prot_gen.inl.h"
#include "include/gen/algo_lib_gen.h"
#include "include/gen/algo_lib_gen.inl.h"
//#pragma endinclude

// Instantiate all libraries linked into this executable,
// in dependency order
lib_json::FDb   lib_json::_db;    // dependency found via dev.targdep
algo_lib::FDb   algo_lib::_db;    // dependency found via dev.targdep
amc_gc::FDb     amc_gc::_db;      // dependency found via dev.targdep

namespace amc_gc {
const char *amc_gc_help =
"amc_gc: Empirically eliminate unused records\n"
"Usage: amc_gc [options]\n"
"    OPTION      TYPE    DFLT    COMMENT\n"
"    -target     regx    \"%\"     Target to test-build\n"
"    -key        regx    \"\"      ACR query selecting records to eliminate, e.g. dmmeta.ctype:amc.%\n"
"    -include                    Garbage collect includes for specified target\n"
"    -in         string  \"data\"  Input directory or filename, - for stdin\n"
"    -verbose    int             Verbosity level (0..255); alias -v; cumulative\n"
"    -debug      int             Debug level (0..255); alias -d; cumulative\n"
"    -help                       Print help an exit; alias -h\n"
"    -version                    Print version and exit\n"
"    -signature                  Show signatures and exit; alias -sig\n"
;


} // namespace amc_gc
namespace amc_gc { // gen:ns_print_proto
    // Load statically available data into tables, register tables and database.
    static void          InitReflection();
    // find trace by row id (used to implement reflection)
    static algo::ImrowPtr trace_RowidFind(int t) __attribute__((nothrow));
    // Function return 1
    static i32           trace_N() __attribute__((__warn_unused_result__, nothrow, pure));
    static void          SizeCheck();
} // gen:ns_print_proto

// --- amc_gc.trace..Print
// print string representation of amc_gc::trace to string LHS, no header -- cprint:amc_gc.trace.String
void amc_gc::trace_Print(amc_gc::trace & row, algo::cstring &str) {
    algo::tempstr temp;
    str << "amc_gc.trace";
    (void)row;//only to avoid -Wunused-parameter
}

// --- amc_gc.FDb._db.ReadArgv
// Read argc,argv directly into the fields of the command line(s)
// The following fields are updated:
//     amc_gc.FDb.cmdline
//     algo_lib.FDb.cmdline
void amc_gc::ReadArgv() {
    command::amc_gc &cmd = amc_gc::_db.cmdline;
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
                    needarg = command::amc_gc_NArgs(attrid,dfltval,&isanon);
                }
            }
            if (attrval == "" && dfltval != "") {
                attrval=dfltval;
                haveval=true;
            }
            if (needarg<0) {
                err<<"amc_gc: unknown option "<<Keyval("value",arg)<<eol;
            } else {
            }
        }
        if (ch_N(attrname) == 0) {
            err << "amc_gc: too many arguments. error at "<<algo::strptr_ToSsim(arg)<<eol;
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
                ret=command::amc_gc_ReadFieldMaybe(cmd, attrname, attrval);
                switch(attrid.value) {
                    default:break;
                }
            }
            if (!ret) {
                err<<"amc_gc: error in "
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
        prlog(amc_gc_help);
    }
    if (doexit) {
        _exit(algo_lib::_db.exit_code);
    }
    algo_lib::ResetErrtext();
    vrfy(amc_gc::LoadTuplesMaybe(cmd.in)
    ,tempstr()<<"where:load_input  "<<algo_lib::DetachBadTags());
}

// --- amc_gc.FDb._db.MainLoop
// Main loop.
void amc_gc::MainLoop() {
    algo::SchedTime time(algo::get_cycles());
    algo_lib::_db.clock          = time;
    do {
        algo_lib::_db.next_loop.value = algo_lib::_db.limit;
        amc_gc::Steps();
    } while (algo_lib::_db.next_loop < algo_lib::_db.limit);
}

// --- amc_gc.FDb._db.Step
// Main step
void amc_gc::Step() {
}

// --- amc_gc.FDb._db.InitReflection
// Load statically available data into tables, register tables and database.
static void amc_gc::InitReflection() {
    algo_lib::imdb_InsertMaybe(algo::Imdb("amc_gc", NULL, NULL, amc_gc::MainLoop, NULL, algo::Comment()));

    algo::Imtable t_trace;
    t_trace.imtable         = "amc_gc.trace";
    t_trace.ssimfile        = "";
    t_trace.size            = sizeof(amc_gc::trace);
    t_trace.comment.value   = "";
    t_trace.c_RowidFind     = trace_RowidFind;
    t_trace.NItems          = trace_N;
    t_trace.Print           = (algo::ImrowPrintFcn)amc_gc::trace_Print;
    algo_lib::imtable_InsertMaybe(t_trace);


    // -- load signatures of existing dispatches --
}

// --- amc_gc.FDb._db.StaticCheck
void amc_gc::StaticCheck() {
    algo_assert(_offset_of(amc_gc::FieldId, value) + sizeof(((amc_gc::FieldId*)0)->value) == sizeof(amc_gc::FieldId));
}

// --- amc_gc.FDb._db.InsertStrptrMaybe
// Parse strptr into known type and add to database.
// Return value is true unless an error occurs. If return value is false, algo_lib::_db.errtext has error text
bool amc_gc::InsertStrptrMaybe(algo::strptr str) {
    bool retval = true;
    (void)str;//only to avoid -Wunused-parameter
    return retval;
}

// --- amc_gc.FDb._db.LoadTuplesMaybe
// Load all finputs from given directory.
bool amc_gc::LoadTuplesMaybe(algo::strptr root) {
    bool retval = true;
    (void)root;//only to avoid -Wunused-parameter
    return retval;
}

// --- amc_gc.FDb._db.LoadSsimfileMaybe
// Load specified ssimfile.
bool amc_gc::LoadSsimfileMaybe(algo::strptr fname) {
    bool retval = true;
    if (FileQ(fname)) {
        retval = algo_lib::LoadTuplesFile(fname, amc_gc::InsertStrptrMaybe, true);
    }
    return retval;
}

// --- amc_gc.FDb._db.Steps
// Calls Step function of dependencies
void amc_gc::Steps() {
    algo_lib::Step(); // dependent namespace specified via (dev.targdep)
}

// --- amc_gc.FDb._db.XrefMaybe
// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Caller must Delete or Unref such row.
bool amc_gc::_db_XrefMaybe() {
    bool retval = true;
    return retval;
}

// --- amc_gc.FDb.trace.RowidFind
// find trace by row id (used to implement reflection)
static algo::ImrowPtr amc_gc::trace_RowidFind(int t) {
    return algo::ImrowPtr(t==0 ? u64(&_db.trace) : u64(0));
}

// --- amc_gc.FDb.trace.N
// Function return 1
inline static i32 amc_gc::trace_N() {
    return 1;
}

// --- amc_gc.FDb..Init
// Set all fields to initial values.
void amc_gc::FDb_Init() {
    _db.n_cur = u32(1);
    _db.n_del = u32(0);
    _db.n_cppline = u32(0);
    _db.n_newcppline = u32(0);
    _db.buildlog = algo::strptr("temp/amc_gc.build");
    _db.n_total = u32(0);

    amc_gc::InitReflection();
}

// --- amc_gc.FDb..Uninit
void amc_gc::FDb_Uninit() {
    amc_gc::FDb &row = _db; (void)row;
}

// --- amc_gc.FieldId.value.ToCstr
// Convert numeric value of field to one of predefined string constants.
// If string is found, return a static C string. Otherwise, return NULL.
const char* amc_gc::value_ToCstr(const amc_gc::FieldId& parent) {
    const char *ret = NULL;
    switch(value_GetEnum(parent)) {
        case amc_gc_FieldId_value          : ret = "value";  break;
    }
    return ret;
}

// --- amc_gc.FieldId.value.Print
// Convert value to a string. First, attempt conversion to a known string.
// If no string matches, print value as a numeric value.
void amc_gc::value_Print(const amc_gc::FieldId& parent, algo::cstring &lhs) {
    const char *strval = value_ToCstr(parent);
    if (strval) {
        lhs << strval;
    } else {
        lhs << parent.value;
    }
}

// --- amc_gc.FieldId.value.SetStrptrMaybe
// Convert string to field.
// If the string is invalid, do not modify field and return false.
// In case of success, return true
bool amc_gc::value_SetStrptrMaybe(amc_gc::FieldId& parent, algo::strptr rhs) {
    bool ret = false;
    switch (elems_N(rhs)) {
        case 5: {
            switch (u64(algo::ReadLE32(rhs.elems))|(u64(rhs[4])<<32)) {
                case LE_STR5('v','a','l','u','e'): {
                    value_SetEnum(parent,amc_gc_FieldId_value); ret = true; break;
                }
            }
            break;
        }
    }
    return ret;
}

// --- amc_gc.FieldId.value.SetStrptr
// Convert string to field.
// If the string is invalid, set numeric value to DFLT
void amc_gc::value_SetStrptr(amc_gc::FieldId& parent, algo::strptr rhs, amc_gc_FieldIdEnum dflt) {
    if (!value_SetStrptrMaybe(parent,rhs)) value_SetEnum(parent,dflt);
}

// --- amc_gc.FieldId.value.ReadStrptrMaybe
// Convert string to field. Return success value
bool amc_gc::value_ReadStrptrMaybe(amc_gc::FieldId& parent, algo::strptr rhs) {
    bool retval = false;
    retval = value_SetStrptrMaybe(parent,rhs); // try symbol conversion
    if (!retval) { // didn't work? try reading as underlying type
        retval = i32_ReadStrptrMaybe(parent.value,rhs);
    }
    return retval;
}

// --- amc_gc.FieldId..ReadStrptrMaybe
// Read fields of amc_gc::FieldId from an ascii string.
// The format of the string is the format of the amc_gc::FieldId's only field
bool amc_gc::FieldId_ReadStrptrMaybe(amc_gc::FieldId &parent, algo::strptr in_str) {
    bool retval = true;
    retval = retval && value_ReadStrptrMaybe(parent, in_str);
    return retval;
}

// --- amc_gc.FieldId..Print
// print string representation of amc_gc::FieldId to string LHS, no header -- cprint:amc_gc.FieldId.String
void amc_gc::FieldId_Print(amc_gc::FieldId & row, algo::cstring &str) {
    amc_gc::value_Print(row, str);
}

// --- amc_gc...SizeCheck
inline static void amc_gc::SizeCheck() {
}

// --- amc_gc...main
int main(int argc, char **argv) {
    try {
        lib_json::FDb_Init();
        algo_lib::FDb_Init();
        amc_gc::FDb_Init();
        algo_lib::_db.argc = argc;
        algo_lib::_db.argv = argv;
        algo_lib::IohookInit();
        amc_gc::ReadArgv(); // dmmeta.main:amc_gc
        amc_gc::Main(); // user-defined main
    } catch(algo_lib::ErrorX &x) {
        prerr("amc_gc.error  " << x); // there may be additional hints in DetachBadTags
        algo_lib::_db.exit_code = 1;
    }
    if (algo_lib::_db.last_signal) {
        algo_lib::_db.exit_code = 1;
    }
    try {
        amc_gc::FDb_Uninit();
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

// --- amc_gc...WinMain
#if defined(WIN32)
int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int) {
    return main(__argc,__argv);
}
#endif
