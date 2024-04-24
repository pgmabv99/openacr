//
// cpp/gen/mysql2ssim_gen.cpp
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
#include "include/gen/mysql2ssim_gen.h"
#include "include/gen/mysql2ssim_gen.inl.h"
#include "include/gen/command_gen.h"
#include "include/gen/command_gen.inl.h"
#include "include/gen/algo_lib_gen.h"
#include "include/gen/algo_lib_gen.inl.h"
#include "include/gen/lib_json_gen.h"
#include "include/gen/lib_json_gen.inl.h"
#include "include/gen/lib_mysql_gen.h"
#include "include/gen/lib_mysql_gen.inl.h"
//#pragma endinclude

// Instantiate all libraries linked into this executable,
// in dependency order
lib_json::FDb     lib_json::_db;      // dependency found via dev.targdep
algo_lib::FDb     algo_lib::_db;      // dependency found via dev.targdep
lib_mysql::FDb    lib_mysql::_db;     // dependency found via dev.targdep
mysql2ssim::FDb   mysql2ssim::_db;    // dependency found via dev.targdep

namespace mysql2ssim {
const char *mysql2ssim_help =
"mysql2ssim: mysql -> ssim conversion tool\n"
"Usage: mysql2ssim [-url:]<string> [[-tables:]<string>] [options]\n"
"    OPTION          TYPE    DFLT    COMMENT\n"
"    -writessimfile                  Write to ssimfile directly\n"
"    [url]           string          user:pass@host/db or sock:///filename/db\n"
"    [tables]        string  \"\"      comma-separated list of tables. Default is all tables\n"
"    -schema                         Generate ssim type definition\n"
"    -in             string  \"data\"  Input directory or filename, - for stdin\n"
"    -pretty                         Format output for the screen\n"
"    -nologo                         Don't show copyright notice\n"
"    -baddbok                        Don't claim if bad database\n"
"    -verbose        int             Verbosity level (0..255); alias -v; cumulative\n"
"    -debug          int             Debug level (0..255); alias -d; cumulative\n"
"    -help                           Print help and exit; alias -h\n"
"    -version                        Print version and exit\n"
"    -signature                      Show signatures and exit; alias -sig\n"
;


} // namespace mysql2ssim
namespace mysql2ssim { // gen:ns_print_proto
    // Load statically available data into tables, register tables and database.
    // func:mysql2ssim.FDb._db.InitReflection
    static void          InitReflection();
    // find trace by row id (used to implement reflection)
    // func:mysql2ssim.FDb.trace.RowidFind
    static algo::ImrowPtr trace_RowidFind(int t) __attribute__((nothrow));
    // Function return 1
    // func:mysql2ssim.FDb.trace.N
    static i32           trace_N() __attribute__((__warn_unused_result__, nothrow, pure));
    // func:mysql2ssim...SizeCheck
    static void          SizeCheck();
} // gen:ns_print_proto

// --- mysql2ssim.trace..Print
// print string representation of ROW to string STR
// cfmt:mysql2ssim.trace.String  printfmt:Tuple
void mysql2ssim::trace_Print(mysql2ssim::trace& row, algo::cstring& str) {
    algo::tempstr temp;
    str << "mysql2ssim.trace";
    (void)row;//only to avoid -Wunused-parameter
}

// --- mysql2ssim.FDb._db.ReadArgv
// Read argc,argv directly into the fields of the command line(s)
// The following fields are updated:
//     mysql2ssim.FDb.cmdline
//     algo_lib.FDb.cmdline
void mysql2ssim::ReadArgv() {
    command::mysql2ssim &cmd = mysql2ssim::_db.cmdline;
    algo_lib::Cmdline &base = algo_lib::_db.cmdline;
    int needarg=-1;// unknown
    int argidx=1;// skip process name
    int anonidx=0;
    algo::strptr nextanon = command::mysql2ssim_GetAnon(cmd, anonidx);
    tempstr err;
    algo::strptr attrname;
    bool isanon=false; // true if attrname is anonfld (positional)
    algo_lib::FieldId baseattrid;
    command::FieldId attrid;
    bool endopt=false;
    int whichns=0;// which namespace does the current attribute belong to
    bool url_present = false;
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
                    needarg = command::mysql2ssim_NArgs(attrid,dfltval,&isanon);
                }
            }
            if (attrval == "" && dfltval != "") {
                attrval=dfltval;
                haveval=true;
            }
            if (needarg<0) {
                err<<"mysql2ssim: unknown option "<<Keyval("value",arg)<<eol;
            } else {
                if (isanon) {
                    if (attrname == nextanon) { // treat named anon (positional) argument as unnamed
                        attrname = ""; // treat it as unnamed
                    } else if (nextanon != "") { // disallow out-of-order anon (positional) args
                        err<<"mysql2ssim: error at "<<algo::strptr_ToSsim(arg)<<": must be preceded by [-"<<nextanon<<"]"<<eol;
                    }
                }
            }
        }
        // look up anon field name based on index
        // anon fields are only allowed in the leaf ns, never base
        if (ch_N(attrname) == 0) {
            attrname = nextanon;
            nextanon = command::mysql2ssim_GetAnon(cmd, ++anonidx);
            command::FieldId_ReadStrptrMaybe(attrid,attrname);
            whichns=1;
        }
        if (ch_N(attrname) == 0) {
            err << "mysql2ssim: too many arguments. error at "<<algo::strptr_ToSsim(arg)<<eol;
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
                ret=command::mysql2ssim_ReadFieldMaybe(cmd, attrname, attrval);
                switch(attrid.value) {
                    case command_FieldId_url: url_present=true; break;
                    default:break;
                }
            }
            if (!ret) {
                err<<"mysql2ssim: error in "
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
        if (!url_present) {
            err << "mysql2ssim: Missing value for required argument -url (see -help)" << eol;
            doexit = true;
        }
    }
    if (err != "") {
        algo_lib::_db.exit_code=1;
        prerr(err);
        doexit=true;
    }
    if (dohelp) {
        prlog(mysql2ssim_help);
    }
    if (doexit) {
        _exit(algo_lib::_db.exit_code);
    }
    algo_lib::ResetErrtext();
}

// --- mysql2ssim.FDb._db.MainLoop
// Main loop.
void mysql2ssim::MainLoop() {
    algo::SchedTime time(algo::get_cycles());
    algo_lib::_db.clock          = time;
    do {
        algo_lib::_db.next_loop.value = algo_lib::_db.limit;
        mysql2ssim::Steps();
    } while (algo_lib::_db.next_loop < algo_lib::_db.limit);
}

// --- mysql2ssim.FDb._db.Step
// Main step
void mysql2ssim::Step() {
}

// --- mysql2ssim.FDb._db.InitReflection
// Load statically available data into tables, register tables and database.
static void mysql2ssim::InitReflection() {
    algo_lib::imdb_InsertMaybe(algo::Imdb("mysql2ssim", NULL, NULL, mysql2ssim::MainLoop, NULL, algo::Comment()));

    algo::Imtable t_trace;
    t_trace.imtable         = "mysql2ssim.trace";
    t_trace.ssimfile        = "";
    t_trace.size            = sizeof(mysql2ssim::trace);
    t_trace.comment.value   = "";
    t_trace.c_RowidFind     = trace_RowidFind;
    t_trace.NItems          = trace_N;
    t_trace.Print           = (algo::ImrowPrintFcn)mysql2ssim::trace_Print;
    algo_lib::imtable_InsertMaybe(t_trace);


    // -- load signatures of existing dispatches --
}

// --- mysql2ssim.FDb._db.StaticCheck
void mysql2ssim::StaticCheck() {
    algo_assert(_offset_of(mysql2ssim::FieldId, value) + sizeof(((mysql2ssim::FieldId*)0)->value) == sizeof(mysql2ssim::FieldId));
}

// --- mysql2ssim.FDb._db.InsertStrptrMaybe
// Parse strptr into known type and add to database.
// Return value is true unless an error occurs. If return value is false, algo_lib::_db.errtext has error text
bool mysql2ssim::InsertStrptrMaybe(algo::strptr str) {
    bool retval = true;
    (void)str;//only to avoid -Wunused-parameter
    return retval;
}

// --- mysql2ssim.FDb._db.LoadTuplesMaybe
// Load all finputs from given directory.
bool mysql2ssim::LoadTuplesMaybe(algo::strptr root, bool recursive) {
    bool retval = true;
    if (FileQ(root)) {
        retval = mysql2ssim::LoadTuplesFile(root, recursive);
    } else if (root == "-") {
        retval = mysql2ssim::LoadTuplesFd(algo::Fildes(0),"(stdin)",recursive);
    } else if (DirectoryQ(root)) {
        retval = retval && mysql2ssim::LoadTuplesFile(algo::SsimFname(root,"dmmeta.dispsigcheck"),recursive);
    } else {
        algo_lib::SaveBadTag("path", root);
        algo_lib::SaveBadTag("comment", "Wrong working directory?");
        retval = false;
    }
    return retval;
}

// --- mysql2ssim.FDb._db.LoadTuplesFile
// Load all finputs from given file.
// Read tuples from file FNAME into this namespace's in-memory database.
// If RECURSIVE is TRUE, then also load these tuples into any parent namespaces
// It a file referred to by FNAME is missing, no error is reported (it's considered an empty set).
// Function returns TRUE if all records were parsed and inserted without error.
// If the function returns FALSE, use algo_lib::DetachBadTags() for error description
bool mysql2ssim::LoadTuplesFile(algo::strptr fname, bool recursive) {
    bool retval = true;
    algo_lib::FFildes fildes;
    // missing files are not an error
    fildes.fd = OpenRead(fname,algo::FileFlags());
    if (ValidQ(fildes.fd)) {
        retval = LoadTuplesFd(fildes.fd, fname, recursive);
    }
    return retval;
}

// --- mysql2ssim.FDb._db.LoadTuplesFd
// Load all finputs from given file descriptor.
bool mysql2ssim::LoadTuplesFd(algo::Fildes fd, algo::strptr fname, bool recursive) {
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

// --- mysql2ssim.FDb._db.LoadSsimfileMaybe
// Load specified ssimfile.
bool mysql2ssim::LoadSsimfileMaybe(algo::strptr fname, bool recursive) {
    bool retval = true;
    if (FileQ(fname)) {
        retval = mysql2ssim::LoadTuplesFile(fname, recursive);
    }
    return retval;
}

// --- mysql2ssim.FDb._db.Steps
// Calls Step function of dependencies
void mysql2ssim::Steps() {
    algo_lib::Step(); // dependent namespace specified via (dev.targdep)
}

// --- mysql2ssim.FDb._db.XrefMaybe
// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Caller must Delete or Unref such row.
bool mysql2ssim::_db_XrefMaybe() {
    bool retval = true;
    return retval;
}

// --- mysql2ssim.FDb.table_names.Addary
// Reserve space (this may move memory). Insert N element at the end.
// Return aryptr to newly inserted block.
// If the RHS argument aliases the array (refers to the same memory), exit program with fatal error.
algo::aryptr<algo::cstring> mysql2ssim::table_names_Addary(algo::aryptr<algo::cstring> rhs) {
    bool overlaps = rhs.n_elems>0 && rhs.elems >= _db.table_names_elems && rhs.elems < _db.table_names_elems + _db.table_names_max;
    if (UNLIKELY(overlaps)) {
        FatalErrorExit("mysql2ssim.tary_alias  field:mysql2ssim.FDb.table_names  comment:'alias error: sub-array is being appended to the whole'");
    }
    int nnew = rhs.n_elems;
    table_names_Reserve(nnew); // reserve space
    int at = _db.table_names_n;
    for (int i = 0; i < nnew; i++) {
        new (_db.table_names_elems + at + i) algo::cstring(rhs[i]);
        _db.table_names_n++;
    }
    return algo::aryptr<algo::cstring>(_db.table_names_elems + at, nnew);
}

// --- mysql2ssim.FDb.table_names.Alloc
// Reserve space. Insert element at the end
// The new element is initialized to a default value
algo::cstring& mysql2ssim::table_names_Alloc() {
    table_names_Reserve(1);
    int n  = _db.table_names_n;
    int at = n;
    algo::cstring *elems = _db.table_names_elems;
    new (elems + at) algo::cstring(); // construct new element, default initializer
    _db.table_names_n = n+1;
    return elems[at];
}

// --- mysql2ssim.FDb.table_names.AllocAt
// Reserve space for new element, reallocating the array if necessary
// Insert new element at specified index. Index must be in range or a fatal error occurs.
algo::cstring& mysql2ssim::table_names_AllocAt(int at) {
    table_names_Reserve(1);
    int n  = _db.table_names_n;
    if (UNLIKELY(u64(at) >= u64(n+1))) {
        FatalErrorExit("mysql2ssim.bad_alloc_at  field:mysql2ssim.FDb.table_names  comment:'index out of range'");
    }
    algo::cstring *elems = _db.table_names_elems;
    memmove(elems + at + 1, elems + at, (n - at) * sizeof(algo::cstring));
    new (elems + at) algo::cstring(); // construct element, default initializer
    _db.table_names_n = n+1;
    return elems[at];
}

// --- mysql2ssim.FDb.table_names.AllocN
// Reserve space. Insert N elements at the end of the array, return pointer to array
algo::aryptr<algo::cstring> mysql2ssim::table_names_AllocN(int n_elems) {
    table_names_Reserve(n_elems);
    int old_n  = _db.table_names_n;
    int new_n = old_n + n_elems;
    algo::cstring *elems = _db.table_names_elems;
    for (int i = old_n; i < new_n; i++) {
        new (elems + i) algo::cstring(); // construct new element, default initialize
    }
    _db.table_names_n = new_n;
    return algo::aryptr<algo::cstring>(elems + old_n, n_elems);
}

// --- mysql2ssim.FDb.table_names.Remove
// Remove item by index. If index outside of range, do nothing.
void mysql2ssim::table_names_Remove(u32 i) {
    u32 lim = _db.table_names_n;
    algo::cstring *elems = _db.table_names_elems;
    if (i < lim) {
        elems[i].~cstring(); // destroy element
        memmove(elems + i, elems + (i + 1), sizeof(algo::cstring) * (lim - (i + 1)));
        _db.table_names_n = lim - 1;
    }
}

// --- mysql2ssim.FDb.table_names.RemoveAll
void mysql2ssim::table_names_RemoveAll() {
    u32 n = _db.table_names_n;
    while (n > 0) {
        n -= 1;
        _db.table_names_elems[n].~cstring();
        _db.table_names_n = n;
    }
}

// --- mysql2ssim.FDb.table_names.RemoveLast
// Delete last element of array. Do nothing if array is empty.
void mysql2ssim::table_names_RemoveLast() {
    u64 n = _db.table_names_n;
    if (n > 0) {
        n -= 1;
        table_names_qFind(u64(n)).~cstring();
        _db.table_names_n = n;
    }
}

// --- mysql2ssim.FDb.table_names.AbsReserve
// Make sure N elements fit in array. Process dies if out of memory
void mysql2ssim::table_names_AbsReserve(int n) {
    u32 old_max  = _db.table_names_max;
    if (n > i32(old_max)) {
        u32 new_max  = i32_Max(i32_Max(old_max * 2, n), 4);
        void *new_mem = algo_lib::malloc_ReallocMem(_db.table_names_elems, old_max * sizeof(algo::cstring), new_max * sizeof(algo::cstring));
        if (UNLIKELY(!new_mem)) {
            FatalErrorExit("mysql2ssim.tary_nomem  field:mysql2ssim.FDb.table_names  comment:'out of memory'");
        }
        _db.table_names_elems = (algo::cstring*)new_mem;
        _db.table_names_max = new_max;
    }
}

// --- mysql2ssim.FDb.table_names.AllocNVal
// Reserve space. Insert N elements at the end of the array, return pointer to array
algo::aryptr<algo::cstring> mysql2ssim::table_names_AllocNVal(int n_elems, const algo::cstring& val) {
    table_names_Reserve(n_elems);
    int old_n  = _db.table_names_n;
    int new_n = old_n + n_elems;
    algo::cstring *elems = _db.table_names_elems;
    for (int i = old_n; i < new_n; i++) {
        new (elems + i) algo::cstring(val);
    }
    _db.table_names_n = new_n;
    return algo::aryptr<algo::cstring>(elems + old_n, n_elems);
}

// --- mysql2ssim.FDb.table_names.ReadStrptrMaybe
// A single element is read from input string and appended to the array.
// If the string contains an error, the array is untouched.
// Function returns success value.
bool mysql2ssim::table_names_ReadStrptrMaybe(algo::strptr in_str) {
    bool retval = true;
    algo::cstring &elem = table_names_Alloc();
    retval = algo::cstring_ReadStrptrMaybe(elem, in_str);
    if (!retval) {
        table_names_RemoveLast();
    }
    return retval;
}

// --- mysql2ssim.FDb.in_tables.Addary
// Reserve space (this may move memory). Insert N element at the end.
// Return aryptr to newly inserted block.
// If the RHS argument aliases the array (refers to the same memory), exit program with fatal error.
algo::aryptr<algo::cstring> mysql2ssim::in_tables_Addary(algo::aryptr<algo::cstring> rhs) {
    bool overlaps = rhs.n_elems>0 && rhs.elems >= _db.in_tables_elems && rhs.elems < _db.in_tables_elems + _db.in_tables_max;
    if (UNLIKELY(overlaps)) {
        FatalErrorExit("mysql2ssim.tary_alias  field:mysql2ssim.FDb.in_tables  comment:'alias error: sub-array is being appended to the whole'");
    }
    int nnew = rhs.n_elems;
    in_tables_Reserve(nnew); // reserve space
    int at = _db.in_tables_n;
    for (int i = 0; i < nnew; i++) {
        new (_db.in_tables_elems + at + i) algo::cstring(rhs[i]);
        _db.in_tables_n++;
    }
    return algo::aryptr<algo::cstring>(_db.in_tables_elems + at, nnew);
}

// --- mysql2ssim.FDb.in_tables.Alloc
// Reserve space. Insert element at the end
// The new element is initialized to a default value
algo::cstring& mysql2ssim::in_tables_Alloc() {
    in_tables_Reserve(1);
    int n  = _db.in_tables_n;
    int at = n;
    algo::cstring *elems = _db.in_tables_elems;
    new (elems + at) algo::cstring(); // construct new element, default initializer
    _db.in_tables_n = n+1;
    return elems[at];
}

// --- mysql2ssim.FDb.in_tables.AllocAt
// Reserve space for new element, reallocating the array if necessary
// Insert new element at specified index. Index must be in range or a fatal error occurs.
algo::cstring& mysql2ssim::in_tables_AllocAt(int at) {
    in_tables_Reserve(1);
    int n  = _db.in_tables_n;
    if (UNLIKELY(u64(at) >= u64(n+1))) {
        FatalErrorExit("mysql2ssim.bad_alloc_at  field:mysql2ssim.FDb.in_tables  comment:'index out of range'");
    }
    algo::cstring *elems = _db.in_tables_elems;
    memmove(elems + at + 1, elems + at, (n - at) * sizeof(algo::cstring));
    new (elems + at) algo::cstring(); // construct element, default initializer
    _db.in_tables_n = n+1;
    return elems[at];
}

// --- mysql2ssim.FDb.in_tables.AllocN
// Reserve space. Insert N elements at the end of the array, return pointer to array
algo::aryptr<algo::cstring> mysql2ssim::in_tables_AllocN(int n_elems) {
    in_tables_Reserve(n_elems);
    int old_n  = _db.in_tables_n;
    int new_n = old_n + n_elems;
    algo::cstring *elems = _db.in_tables_elems;
    for (int i = old_n; i < new_n; i++) {
        new (elems + i) algo::cstring(); // construct new element, default initialize
    }
    _db.in_tables_n = new_n;
    return algo::aryptr<algo::cstring>(elems + old_n, n_elems);
}

// --- mysql2ssim.FDb.in_tables.Remove
// Remove item by index. If index outside of range, do nothing.
void mysql2ssim::in_tables_Remove(u32 i) {
    u32 lim = _db.in_tables_n;
    algo::cstring *elems = _db.in_tables_elems;
    if (i < lim) {
        elems[i].~cstring(); // destroy element
        memmove(elems + i, elems + (i + 1), sizeof(algo::cstring) * (lim - (i + 1)));
        _db.in_tables_n = lim - 1;
    }
}

// --- mysql2ssim.FDb.in_tables.RemoveAll
void mysql2ssim::in_tables_RemoveAll() {
    u32 n = _db.in_tables_n;
    while (n > 0) {
        n -= 1;
        _db.in_tables_elems[n].~cstring();
        _db.in_tables_n = n;
    }
}

// --- mysql2ssim.FDb.in_tables.RemoveLast
// Delete last element of array. Do nothing if array is empty.
void mysql2ssim::in_tables_RemoveLast() {
    u64 n = _db.in_tables_n;
    if (n > 0) {
        n -= 1;
        in_tables_qFind(u64(n)).~cstring();
        _db.in_tables_n = n;
    }
}

// --- mysql2ssim.FDb.in_tables.AbsReserve
// Make sure N elements fit in array. Process dies if out of memory
void mysql2ssim::in_tables_AbsReserve(int n) {
    u32 old_max  = _db.in_tables_max;
    if (n > i32(old_max)) {
        u32 new_max  = i32_Max(i32_Max(old_max * 2, n), 4);
        void *new_mem = algo_lib::malloc_ReallocMem(_db.in_tables_elems, old_max * sizeof(algo::cstring), new_max * sizeof(algo::cstring));
        if (UNLIKELY(!new_mem)) {
            FatalErrorExit("mysql2ssim.tary_nomem  field:mysql2ssim.FDb.in_tables  comment:'out of memory'");
        }
        _db.in_tables_elems = (algo::cstring*)new_mem;
        _db.in_tables_max = new_max;
    }
}

// --- mysql2ssim.FDb.in_tables.AllocNVal
// Reserve space. Insert N elements at the end of the array, return pointer to array
algo::aryptr<algo::cstring> mysql2ssim::in_tables_AllocNVal(int n_elems, const algo::cstring& val) {
    in_tables_Reserve(n_elems);
    int old_n  = _db.in_tables_n;
    int new_n = old_n + n_elems;
    algo::cstring *elems = _db.in_tables_elems;
    for (int i = old_n; i < new_n; i++) {
        new (elems + i) algo::cstring(val);
    }
    _db.in_tables_n = new_n;
    return algo::aryptr<algo::cstring>(elems + old_n, n_elems);
}

// --- mysql2ssim.FDb.in_tables.ReadStrptrMaybe
// A single element is read from input string and appended to the array.
// If the string contains an error, the array is untouched.
// Function returns success value.
bool mysql2ssim::in_tables_ReadStrptrMaybe(algo::strptr in_str) {
    bool retval = true;
    algo::cstring &elem = in_tables_Alloc();
    retval = algo::cstring_ReadStrptrMaybe(elem, in_str);
    if (!retval) {
        in_tables_RemoveLast();
    }
    return retval;
}

// --- mysql2ssim.FDb.trace.RowidFind
// find trace by row id (used to implement reflection)
static algo::ImrowPtr mysql2ssim::trace_RowidFind(int t) {
    return algo::ImrowPtr(t==0 ? u64(&_db.trace) : u64(0));
}

// --- mysql2ssim.FDb.trace.N
// Function return 1
inline static i32 mysql2ssim::trace_N() {
    return 1;
}

// --- mysql2ssim.FDb..Init
// Set all fields to initial values.
void mysql2ssim::FDb_Init() {
    _db.table_names_elems 	= 0; // (mysql2ssim.FDb.table_names)
    _db.table_names_n     	= 0; // (mysql2ssim.FDb.table_names)
    _db.table_names_max   	= 0; // (mysql2ssim.FDb.table_names)
    _db.in_tables_elems 	= 0; // (mysql2ssim.FDb.in_tables)
    _db.in_tables_n     	= 0; // (mysql2ssim.FDb.in_tables)
    _db.in_tables_max   	= 0; // (mysql2ssim.FDb.in_tables)

    mysql2ssim::InitReflection();
}

// --- mysql2ssim.FDb..Uninit
void mysql2ssim::FDb_Uninit() {
    mysql2ssim::FDb &row = _db; (void)row;

    // mysql2ssim.FDb.in_tables.Uninit (Tary)  //
    // remove all elements from mysql2ssim.FDb.in_tables
    in_tables_RemoveAll();
    // free memory for Tary mysql2ssim.FDb.in_tables
    algo_lib::malloc_FreeMem(_db.in_tables_elems, sizeof(algo::cstring)*_db.in_tables_max); // (mysql2ssim.FDb.in_tables)

    // mysql2ssim.FDb.table_names.Uninit (Tary)  //List of all tables obtained from mysql
    // remove all elements from mysql2ssim.FDb.table_names
    table_names_RemoveAll();
    // free memory for Tary mysql2ssim.FDb.table_names
    algo_lib::malloc_FreeMem(_db.table_names_elems, sizeof(algo::cstring)*_db.table_names_max); // (mysql2ssim.FDb.table_names)
}

// --- mysql2ssim.FTobltin.vals.Addary
// Reserve space (this may move memory). Insert N element at the end.
// Return aryptr to newly inserted block.
// If the RHS argument aliases the array (refers to the same memory), exit program with fatal error.
algo::aryptr<algo::cstring> mysql2ssim::vals_Addary(mysql2ssim::FTobltin& parent, algo::aryptr<algo::cstring> rhs) {
    bool overlaps = rhs.n_elems>0 && rhs.elems >= parent.vals_elems && rhs.elems < parent.vals_elems + parent.vals_max;
    if (UNLIKELY(overlaps)) {
        FatalErrorExit("mysql2ssim.tary_alias  field:mysql2ssim.FTobltin.vals  comment:'alias error: sub-array is being appended to the whole'");
    }
    int nnew = rhs.n_elems;
    vals_Reserve(parent, nnew); // reserve space
    int at = parent.vals_n;
    for (int i = 0; i < nnew; i++) {
        new (parent.vals_elems + at + i) algo::cstring(rhs[i]);
        parent.vals_n++;
    }
    return algo::aryptr<algo::cstring>(parent.vals_elems + at, nnew);
}

// --- mysql2ssim.FTobltin.vals.Alloc
// Reserve space. Insert element at the end
// The new element is initialized to a default value
algo::cstring& mysql2ssim::vals_Alloc(mysql2ssim::FTobltin& parent) {
    vals_Reserve(parent, 1);
    int n  = parent.vals_n;
    int at = n;
    algo::cstring *elems = parent.vals_elems;
    new (elems + at) algo::cstring(); // construct new element, default initializer
    parent.vals_n = n+1;
    return elems[at];
}

// --- mysql2ssim.FTobltin.vals.AllocAt
// Reserve space for new element, reallocating the array if necessary
// Insert new element at specified index. Index must be in range or a fatal error occurs.
algo::cstring& mysql2ssim::vals_AllocAt(mysql2ssim::FTobltin& parent, int at) {
    vals_Reserve(parent, 1);
    int n  = parent.vals_n;
    if (UNLIKELY(u64(at) >= u64(n+1))) {
        FatalErrorExit("mysql2ssim.bad_alloc_at  field:mysql2ssim.FTobltin.vals  comment:'index out of range'");
    }
    algo::cstring *elems = parent.vals_elems;
    memmove(elems + at + 1, elems + at, (n - at) * sizeof(algo::cstring));
    new (elems + at) algo::cstring(); // construct element, default initializer
    parent.vals_n = n+1;
    return elems[at];
}

// --- mysql2ssim.FTobltin.vals.AllocN
// Reserve space. Insert N elements at the end of the array, return pointer to array
algo::aryptr<algo::cstring> mysql2ssim::vals_AllocN(mysql2ssim::FTobltin& parent, int n_elems) {
    vals_Reserve(parent, n_elems);
    int old_n  = parent.vals_n;
    int new_n = old_n + n_elems;
    algo::cstring *elems = parent.vals_elems;
    for (int i = old_n; i < new_n; i++) {
        new (elems + i) algo::cstring(); // construct new element, default initialize
    }
    parent.vals_n = new_n;
    return algo::aryptr<algo::cstring>(elems + old_n, n_elems);
}

// --- mysql2ssim.FTobltin.vals.Remove
// Remove item by index. If index outside of range, do nothing.
void mysql2ssim::vals_Remove(mysql2ssim::FTobltin& parent, u32 i) {
    u32 lim = parent.vals_n;
    algo::cstring *elems = parent.vals_elems;
    if (i < lim) {
        elems[i].~cstring(); // destroy element
        memmove(elems + i, elems + (i + 1), sizeof(algo::cstring) * (lim - (i + 1)));
        parent.vals_n = lim - 1;
    }
}

// --- mysql2ssim.FTobltin.vals.RemoveAll
void mysql2ssim::vals_RemoveAll(mysql2ssim::FTobltin& parent) {
    u32 n = parent.vals_n;
    while (n > 0) {
        n -= 1;
        parent.vals_elems[n].~cstring();
        parent.vals_n = n;
    }
}

// --- mysql2ssim.FTobltin.vals.RemoveLast
// Delete last element of array. Do nothing if array is empty.
void mysql2ssim::vals_RemoveLast(mysql2ssim::FTobltin& parent) {
    u64 n = parent.vals_n;
    if (n > 0) {
        n -= 1;
        vals_qFind(parent, u64(n)).~cstring();
        parent.vals_n = n;
    }
}

// --- mysql2ssim.FTobltin.vals.AbsReserve
// Make sure N elements fit in array. Process dies if out of memory
void mysql2ssim::vals_AbsReserve(mysql2ssim::FTobltin& parent, int n) {
    u32 old_max  = parent.vals_max;
    if (n > i32(old_max)) {
        u32 new_max  = i32_Max(i32_Max(old_max * 2, n), 4);
        void *new_mem = algo_lib::malloc_ReallocMem(parent.vals_elems, old_max * sizeof(algo::cstring), new_max * sizeof(algo::cstring));
        if (UNLIKELY(!new_mem)) {
            FatalErrorExit("mysql2ssim.tary_nomem  field:mysql2ssim.FTobltin.vals  comment:'out of memory'");
        }
        parent.vals_elems = (algo::cstring*)new_mem;
        parent.vals_max = new_max;
    }
}

// --- mysql2ssim.FTobltin.vals.Setary
// Copy contents of RHS to PARENT.
void mysql2ssim::vals_Setary(mysql2ssim::FTobltin& parent, mysql2ssim::FTobltin &rhs) {
    vals_RemoveAll(parent);
    int nnew = rhs.vals_n;
    vals_Reserve(parent, nnew); // reserve space
    for (int i = 0; i < nnew; i++) { // copy elements over
        new (parent.vals_elems + i) algo::cstring(vals_qFind(rhs, i));
        parent.vals_n = i + 1;
    }
}

// --- mysql2ssim.FTobltin.vals.Setary2
// Copy specified array into vals, discarding previous contents.
// If the RHS argument aliases the array (refers to the same memory), throw exception.
void mysql2ssim::vals_Setary(mysql2ssim::FTobltin& parent, const algo::aryptr<algo::cstring> &rhs) {
    vals_RemoveAll(parent);
    vals_Addary(parent, rhs);
}

// --- mysql2ssim.FTobltin.vals.AllocNVal
// Reserve space. Insert N elements at the end of the array, return pointer to array
algo::aryptr<algo::cstring> mysql2ssim::vals_AllocNVal(mysql2ssim::FTobltin& parent, int n_elems, const algo::cstring& val) {
    vals_Reserve(parent, n_elems);
    int old_n  = parent.vals_n;
    int new_n = old_n + n_elems;
    algo::cstring *elems = parent.vals_elems;
    for (int i = old_n; i < new_n; i++) {
        new (elems + i) algo::cstring(val);
    }
    parent.vals_n = new_n;
    return algo::aryptr<algo::cstring>(elems + old_n, n_elems);
}

// --- mysql2ssim.FTobltin.vals.ReadStrptrMaybe
// A single element is read from input string and appended to the array.
// If the string contains an error, the array is untouched.
// Function returns success value.
bool mysql2ssim::vals_ReadStrptrMaybe(mysql2ssim::FTobltin& parent, algo::strptr in_str) {
    bool retval = true;
    algo::cstring &elem = vals_Alloc(parent);
    retval = algo::cstring_ReadStrptrMaybe(elem, in_str);
    if (!retval) {
        vals_RemoveLast(parent);
    }
    return retval;
}

// --- mysql2ssim.FTobltin..Uninit
void mysql2ssim::FTobltin_Uninit(mysql2ssim::FTobltin& parent) {
    mysql2ssim::FTobltin &row = parent; (void)row;

    // mysql2ssim.FTobltin.vals.Uninit (Tary)  //Used during schema extraction
    // remove all elements from mysql2ssim.FTobltin.vals
    vals_RemoveAll(parent);
    // free memory for Tary mysql2ssim.FTobltin.vals
    algo_lib::malloc_FreeMem(parent.vals_elems, sizeof(algo::cstring)*parent.vals_max); // (mysql2ssim.FTobltin.vals)
}

// --- mysql2ssim.FieldId.value.ToCstr
// Convert numeric value of field to one of predefined string constants.
// If string is found, return a static C string. Otherwise, return NULL.
const char* mysql2ssim::value_ToCstr(const mysql2ssim::FieldId& parent) {
    const char *ret = NULL;
    switch(value_GetEnum(parent)) {
        case mysql2ssim_FieldId_value      : ret = "value";  break;
    }
    return ret;
}

// --- mysql2ssim.FieldId.value.Print
// Convert value to a string. First, attempt conversion to a known string.
// If no string matches, print value as a numeric value.
void mysql2ssim::value_Print(const mysql2ssim::FieldId& parent, algo::cstring &lhs) {
    const char *strval = value_ToCstr(parent);
    if (strval) {
        lhs << strval;
    } else {
        lhs << parent.value;
    }
}

// --- mysql2ssim.FieldId.value.SetStrptrMaybe
// Convert string to field.
// If the string is invalid, do not modify field and return false.
// In case of success, return true
bool mysql2ssim::value_SetStrptrMaybe(mysql2ssim::FieldId& parent, algo::strptr rhs) {
    bool ret = false;
    switch (elems_N(rhs)) {
        case 5: {
            switch (u64(algo::ReadLE32(rhs.elems))|(u64(rhs[4])<<32)) {
                case LE_STR5('v','a','l','u','e'): {
                    value_SetEnum(parent,mysql2ssim_FieldId_value); ret = true; break;
                }
            }
            break;
        }
    }
    return ret;
}

// --- mysql2ssim.FieldId.value.SetStrptr
// Convert string to field.
// If the string is invalid, set numeric value to DFLT
void mysql2ssim::value_SetStrptr(mysql2ssim::FieldId& parent, algo::strptr rhs, mysql2ssim_FieldIdEnum dflt) {
    if (!value_SetStrptrMaybe(parent,rhs)) value_SetEnum(parent,dflt);
}

// --- mysql2ssim.FieldId.value.ReadStrptrMaybe
// Convert string to field. Return success value
bool mysql2ssim::value_ReadStrptrMaybe(mysql2ssim::FieldId& parent, algo::strptr rhs) {
    bool retval = false;
    retval = value_SetStrptrMaybe(parent,rhs); // try symbol conversion
    if (!retval) { // didn't work? try reading as underlying type
        retval = i32_ReadStrptrMaybe(parent.value,rhs);
    }
    return retval;
}

// --- mysql2ssim.FieldId..ReadStrptrMaybe
// Read fields of mysql2ssim::FieldId from an ascii string.
// The format of the string is the format of the mysql2ssim::FieldId's only field
bool mysql2ssim::FieldId_ReadStrptrMaybe(mysql2ssim::FieldId &parent, algo::strptr in_str) {
    bool retval = true;
    retval = retval && value_ReadStrptrMaybe(parent, in_str);
    return retval;
}

// --- mysql2ssim.FieldId..Print
// print string representation of ROW to string STR
// cfmt:mysql2ssim.FieldId.String  printfmt:Raw
void mysql2ssim::FieldId_Print(mysql2ssim::FieldId& row, algo::cstring& str) {
    mysql2ssim::value_Print(row, str);
}

// --- mysql2ssim...SizeCheck
inline static void mysql2ssim::SizeCheck() {
}

// --- mysql2ssim...main
int main(int argc, char **argv) {
    try {
        lib_json::FDb_Init();
        algo_lib::FDb_Init();
        lib_mysql::FDb_Init();
        mysql2ssim::FDb_Init();
        algo_lib::_db.argc = argc;
        algo_lib::_db.argv = argv;
        algo_lib::IohookInit();
        mysql2ssim::ReadArgv(); // dmmeta.main:mysql2ssim
        mysql2ssim::Main(); // user-defined main
    } catch(algo_lib::ErrorX &x) {
        prerr("mysql2ssim.error  " << x); // there may be additional hints in DetachBadTags
        algo_lib::_db.exit_code = 1;
    }
    if (algo_lib::_db.last_signal) {
        algo_lib::_db.exit_code = 1;
    }
    try {
        mysql2ssim::FDb_Uninit();
        lib_mysql::FDb_Uninit();
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

// --- mysql2ssim...WinMain
#if defined(WIN32)
int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int) {
    return main(__argc,__argv);
}
#endif
