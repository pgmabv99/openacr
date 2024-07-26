//
// cpp/gen/acr_my_gen.cpp
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
#include "include/gen/acr_my_gen.h"
#include "include/gen/acr_my_gen.inl.h"
#include "include/gen/algo_lib_gen.h"
#include "include/gen/algo_lib_gen.inl.h"
#include "include/gen/algo_gen.h"
#include "include/gen/algo_gen.inl.h"
#include "include/gen/command_gen.h"
#include "include/gen/command_gen.inl.h"
#include "include/gen/dmmeta_gen.h"
#include "include/gen/dmmeta_gen.inl.h"
//#pragma endinclude

// Instantiate all libraries linked into this executable,
// in dependency order
algo_lib::FDb   algo_lib::_db;    // dependency found via dev.targdep
acr_my::FDb     acr_my::_db;      // dependency found via dev.targdep

namespace acr_my {
const char *acr_my_help =
"acr_my: ACR <-> MariaDB adaptor\n"
"Usage: acr_my [[-nsdb:]<regx>] [options]\n"
"    OPTION      TYPE    DFLT    COMMENT\n"
"    [nsdb]      regx    \"\"      Regx of ssim namespace (dmmeta.nsdb) to select\n"
"    -in         string  \"data\"  Input directory or filename, - for stdin\n"
"    -schema     string  \"data\"  Input directory or filename, - for stdin\n"
"    -fldfunc                    Evaluate fldfunc when printing tuple\n"
"    -fkey                       Enable foreign key constraints\n"
"    -e                          Alias for -start -shell -stop\n"
"    -start                      Start local mysql server\n"
"    -stop                       Stop local mysql server, saving data\n"
"    -abort                      Abort local mysql server, losing data\n"
"    -shell                      Connect to local mysql server\n"
"    -serv                       Start mysql with TCP/IP service enabled\n"
"    -verbose    int             Verbosity level (0..255); alias -v; cumulative\n"
"    -debug      int             Debug level (0..255); alias -d; cumulative\n"
"    -help                       Print help and exit; alias -h\n"
"    -version                    Print version and exit\n"
"    -signature                  Show signatures and exit; alias -sig\n"
;


} // namespace acr_my
namespace acr_my { // gen:ns_print_proto
    // Load statically available data into tables, register tables and database.
    // func:acr_my.FDb._db.InitReflection
    static void          InitReflection();
    // func:acr_my.FDb.nsdb.InputMaybe
    static bool          nsdb_InputMaybe(dmmeta::Nsdb &elem) __attribute__((nothrow));
    // func:acr_my.FDb.ssimfile.InputMaybe
    static bool          ssimfile_InputMaybe(dmmeta::Ssimfile &elem) __attribute__((nothrow));
    // find trace by row id (used to implement reflection)
    // func:acr_my.FDb.trace.RowidFind
    static algo::ImrowPtr trace_RowidFind(int t) __attribute__((nothrow));
    // Function return 1
    // func:acr_my.FDb.trace.N
    static i32           trace_N() __attribute__((__warn_unused_result__, nothrow, pure));
    // func:acr_my...SizeCheck
    static void          SizeCheck();
} // gen:ns_print_proto

// --- acr_my.trace..Print
// print string representation of ROW to string STR
// cfmt:acr_my.trace.String  printfmt:Tuple
void acr_my::trace_Print(acr_my::trace& row, algo::cstring& str) {
    algo::tempstr temp;
    str << "acr_my.trace";
    (void)row;//only to avoid -Wunused-parameter
}

// --- acr_my.FDb.ary_ns.Addary
// Reserve space (this may move memory). Insert N element at the end.
// Return aryptr to newly inserted block.
// If the RHS argument aliases the array (refers to the same memory), exit program with fatal error.
algo::aryptr<algo::cstring> acr_my::ary_ns_Addary(algo::aryptr<algo::cstring> rhs) {
    bool overlaps = rhs.n_elems>0 && rhs.elems >= _db.ary_ns_elems && rhs.elems < _db.ary_ns_elems + _db.ary_ns_max;
    if (UNLIKELY(overlaps)) {
        FatalErrorExit("acr_my.tary_alias  field:acr_my.FDb.ary_ns  comment:'alias error: sub-array is being appended to the whole'");
    }
    int nnew = rhs.n_elems;
    ary_ns_Reserve(nnew); // reserve space
    int at = _db.ary_ns_n;
    for (int i = 0; i < nnew; i++) {
        new (_db.ary_ns_elems + at + i) algo::cstring(rhs[i]);
        _db.ary_ns_n++;
    }
    return algo::aryptr<algo::cstring>(_db.ary_ns_elems + at, nnew);
}

// --- acr_my.FDb.ary_ns.Alloc
// Reserve space. Insert element at the end
// The new element is initialized to a default value
algo::cstring& acr_my::ary_ns_Alloc() {
    ary_ns_Reserve(1);
    int n  = _db.ary_ns_n;
    int at = n;
    algo::cstring *elems = _db.ary_ns_elems;
    new (elems + at) algo::cstring(); // construct new element, default initializer
    _db.ary_ns_n = n+1;
    return elems[at];
}

// --- acr_my.FDb.ary_ns.AllocAt
// Reserve space for new element, reallocating the array if necessary
// Insert new element at specified index. Index must be in range or a fatal error occurs.
algo::cstring& acr_my::ary_ns_AllocAt(int at) {
    ary_ns_Reserve(1);
    int n  = _db.ary_ns_n;
    if (UNLIKELY(u64(at) >= u64(n+1))) {
        FatalErrorExit("acr_my.bad_alloc_at  field:acr_my.FDb.ary_ns  comment:'index out of range'");
    }
    algo::cstring *elems = _db.ary_ns_elems;
    memmove(elems + at + 1, elems + at, (n - at) * sizeof(algo::cstring));
    new (elems + at) algo::cstring(); // construct element, default initializer
    _db.ary_ns_n = n+1;
    return elems[at];
}

// --- acr_my.FDb.ary_ns.AllocN
// Reserve space. Insert N elements at the end of the array, return pointer to array
algo::aryptr<algo::cstring> acr_my::ary_ns_AllocN(int n_elems) {
    ary_ns_Reserve(n_elems);
    int old_n  = _db.ary_ns_n;
    int new_n = old_n + n_elems;
    algo::cstring *elems = _db.ary_ns_elems;
    for (int i = old_n; i < new_n; i++) {
        new (elems + i) algo::cstring(); // construct new element, default initialize
    }
    _db.ary_ns_n = new_n;
    return algo::aryptr<algo::cstring>(elems + old_n, n_elems);
}

// --- acr_my.FDb.ary_ns.Remove
// Remove item by index. If index outside of range, do nothing.
void acr_my::ary_ns_Remove(u32 i) {
    u32 lim = _db.ary_ns_n;
    algo::cstring *elems = _db.ary_ns_elems;
    if (i < lim) {
        elems[i].~cstring(); // destroy element
        memmove(elems + i, elems + (i + 1), sizeof(algo::cstring) * (lim - (i + 1)));
        _db.ary_ns_n = lim - 1;
    }
}

// --- acr_my.FDb.ary_ns.RemoveAll
void acr_my::ary_ns_RemoveAll() {
    u32 n = _db.ary_ns_n;
    while (n > 0) {
        n -= 1;
        _db.ary_ns_elems[n].~cstring();
        _db.ary_ns_n = n;
    }
}

// --- acr_my.FDb.ary_ns.RemoveLast
// Delete last element of array. Do nothing if array is empty.
void acr_my::ary_ns_RemoveLast() {
    u64 n = _db.ary_ns_n;
    if (n > 0) {
        n -= 1;
        ary_ns_qFind(u64(n)).~cstring();
        _db.ary_ns_n = n;
    }
}

// --- acr_my.FDb.ary_ns.AbsReserve
// Make sure N elements fit in array. Process dies if out of memory
void acr_my::ary_ns_AbsReserve(int n) {
    u32 old_max  = _db.ary_ns_max;
    if (n > i32(old_max)) {
        u32 new_max  = i32_Max(i32_Max(old_max * 2, n), 4);
        void *new_mem = algo_lib::malloc_ReallocMem(_db.ary_ns_elems, old_max * sizeof(algo::cstring), new_max * sizeof(algo::cstring));
        if (UNLIKELY(!new_mem)) {
            FatalErrorExit("acr_my.tary_nomem  field:acr_my.FDb.ary_ns  comment:'out of memory'");
        }
        _db.ary_ns_elems = (algo::cstring*)new_mem;
        _db.ary_ns_max = new_max;
    }
}

// --- acr_my.FDb.ary_ns.AllocNVal
// Reserve space. Insert N elements at the end of the array, return pointer to array
algo::aryptr<algo::cstring> acr_my::ary_ns_AllocNVal(int n_elems, const algo::cstring& val) {
    ary_ns_Reserve(n_elems);
    int old_n  = _db.ary_ns_n;
    int new_n = old_n + n_elems;
    algo::cstring *elems = _db.ary_ns_elems;
    for (int i = old_n; i < new_n; i++) {
        new (elems + i) algo::cstring(val);
    }
    _db.ary_ns_n = new_n;
    return algo::aryptr<algo::cstring>(elems + old_n, n_elems);
}

// --- acr_my.FDb.ary_ns.ReadStrptrMaybe
// A single element is read from input string and appended to the array.
// If the string contains an error, the array is untouched.
// Function returns success value.
bool acr_my::ary_ns_ReadStrptrMaybe(algo::strptr in_str) {
    bool retval = true;
    algo::cstring &elem = ary_ns_Alloc();
    retval = algo::cstring_ReadStrptrMaybe(elem, in_str);
    if (!retval) {
        ary_ns_RemoveLast();
    }
    return retval;
}

// --- acr_my.FDb._db.ReadArgv
// Read argc,argv directly into the fields of the command line(s)
// The following fields are updated:
//     acr_my.FDb.cmdline
//     algo_lib.FDb.cmdline
void acr_my::ReadArgv() {
    command::acr_my &cmd = acr_my::_db.cmdline;
    algo_lib::Cmdline &base = algo_lib::_db.cmdline;
    int needarg=-1;// unknown
    int argidx=1;// skip process name
    int anonidx=0;
    algo::strptr nextanon = command::acr_my_GetAnon(cmd, anonidx);
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
                    needarg = command::acr_my_NArgs(attrid,dfltval,&isanon);
                }
            }
            if (attrval == "" && dfltval != "") {
                attrval=dfltval;
                haveval=true;
            }
            if (needarg<0) {
                err<<"acr_my: unknown option "<<Keyval("value",arg)<<eol;
            } else {
                if (isanon) {
                    if (attrname == nextanon) { // treat named anon (positional) argument as unnamed
                        attrname = ""; // treat it as unnamed
                    } else if (nextanon != "") { // disallow out-of-order anon (positional) args
                        err<<"acr_my: error at "<<algo::strptr_ToSsim(arg)<<": must be preceded by [-"<<nextanon<<"]"<<eol;
                    }
                }
            }
        }
        // look up anon field name based on index
        // anon fields are only allowed in the leaf ns, never base
        if (ch_N(attrname) == 0) {
            attrname = nextanon;
            nextanon = command::acr_my_GetAnon(cmd, ++anonidx);
            command::FieldId_ReadStrptrMaybe(attrid,attrname);
            whichns=1;
        }
        if (ch_N(attrname) == 0) {
            err << "acr_my: too many arguments. error at "<<algo::strptr_ToSsim(arg)<<eol;
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
                ret=command::acr_my_ReadFieldMaybe(cmd, attrname, attrval);
                switch(attrid.value) {
                    default:break;
                }
            }
            if (!ret) {
                err<<"acr_my: error in "
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
    // dmmeta.floadtuples:acr_my.FDb.cmdline
    if (!dohelp && err=="") {
        algo_lib::ResetErrtext();
        if (!acr_my::LoadTuplesMaybe(cmd.schema,true)) {
            err << "acr_my.load_input  "<<algo_lib::DetachBadTags()<<eol;
        }
    }
    if (err != "") {
        algo_lib::_db.exit_code=1;
        prerr(err);
        doexit=true;
    }
    if (dohelp) {
        prlog(acr_my_help);
    }
    if (doexit) {
        _exit(algo_lib::_db.exit_code);
    }
    algo_lib::ResetErrtext();
}

// --- acr_my.FDb._db.MainLoop
// Main loop.
void acr_my::MainLoop() {
    algo::SchedTime time(algo::get_cycles());
    algo_lib::_db.clock          = time;
    do {
        algo_lib::_db.next_loop.value = algo_lib::_db.limit;
        acr_my::Steps();
    } while (algo_lib::_db.next_loop < algo_lib::_db.limit);
}

// --- acr_my.FDb._db.Step
// Main step
void acr_my::Step() {
}

// --- acr_my.FDb._db.InitReflection
// Load statically available data into tables, register tables and database.
static void acr_my::InitReflection() {
    algo_lib::imdb_InsertMaybe(algo::Imdb("acr_my", acr_my::InsertStrptrMaybe, NULL, acr_my::MainLoop, NULL, algo::Comment()));

    algo::Imtable t_trace;
    t_trace.imtable         = "acr_my.trace";
    t_trace.ssimfile        = "";
    t_trace.size            = sizeof(acr_my::trace);
    t_trace.comment.value   = "";
    t_trace.c_RowidFind     = trace_RowidFind;
    t_trace.NItems          = trace_N;
    t_trace.Print           = (algo::ImrowPrintFcn)acr_my::trace_Print;
    algo_lib::imtable_InsertMaybe(t_trace);


    // -- load signatures of existing dispatches --
    algo_lib::InsertStrptrMaybe("dmmeta.Dispsigcheck  dispsig:'acr_my.Input'  signature:'4af1104b912fd0ce532858d685766efe3c9836a6'");
}

// --- acr_my.FDb._db.InsertStrptrMaybe
// Parse strptr into known type and add to database.
// Return value is true unless an error occurs. If return value is false, algo_lib::_db.errtext has error text
bool acr_my::InsertStrptrMaybe(algo::strptr str) {
    bool retval = true;
    acr_my::TableId table_id(-1);
    value_SetStrptrMaybe(table_id, algo::GetTypeTag(str));
    switch (value_GetEnum(table_id)) {
        case acr_my_TableId_dmmeta_Nsdb: { // finput:acr_my.FDb.nsdb
            dmmeta::Nsdb elem;
            retval = dmmeta::Nsdb_ReadStrptrMaybe(elem, str);
            retval = retval && nsdb_InputMaybe(elem);
            break;
        }
        case acr_my_TableId_dmmeta_Ssimfile: { // finput:acr_my.FDb.ssimfile
            dmmeta::Ssimfile elem;
            retval = dmmeta::Ssimfile_ReadStrptrMaybe(elem, str);
            retval = retval && ssimfile_InputMaybe(elem);
            break;
        }
        default:
        break;
    } //switch
    if (!retval) {
        algo_lib::NoteInsertErr(str); // increment error counter
    }
    return retval;
}

// --- acr_my.FDb._db.LoadTuplesMaybe
// Load all finputs from given directory.
bool acr_my::LoadTuplesMaybe(algo::strptr root, bool recursive) {
    bool retval = true;
    if (FileQ(root)) {
        retval = acr_my::LoadTuplesFile(root, recursive);
    } else if (root == "-") {
        retval = acr_my::LoadTuplesFd(algo::Fildes(0),"(stdin)",recursive);
    } else if (DirectoryQ(root)) {
        retval = retval && acr_my::LoadTuplesFile(algo::SsimFname(root,"dmmeta.nsdb"),recursive);
        retval = retval && acr_my::LoadTuplesFile(algo::SsimFname(root,"dmmeta.ssimfile"),recursive);
        retval = retval && acr_my::LoadTuplesFile(algo::SsimFname(root,"dmmeta.dispsigcheck"),recursive);
    } else {
        algo_lib::SaveBadTag("path", root);
        algo_lib::SaveBadTag("comment", "Wrong working directory?");
        retval = false;
    }
    return retval;
}

// --- acr_my.FDb._db.LoadTuplesFile
// Load all finputs from given file.
// Read tuples from file FNAME into this namespace's in-memory database.
// If RECURSIVE is TRUE, then also load these tuples into any parent namespaces
// It a file referred to by FNAME is missing, no error is reported (it's considered an empty set).
// Function returns TRUE if all records were parsed and inserted without error.
// If the function returns FALSE, use algo_lib::DetachBadTags() for error description
bool acr_my::LoadTuplesFile(algo::strptr fname, bool recursive) {
    bool retval = true;
    algo_lib::FFildes fildes;
    // missing files are not an error
    fildes.fd = OpenRead(fname,algo::FileFlags());
    if (ValidQ(fildes.fd)) {
        retval = LoadTuplesFd(fildes.fd, fname, recursive);
    }
    return retval;
}

// --- acr_my.FDb._db.LoadTuplesFd
// Load all finputs from given file descriptor.
bool acr_my::LoadTuplesFd(algo::Fildes fd, algo::strptr fname, bool recursive) {
    bool retval = true;
    ind_beg(algo::FileLine_curs,line,fd) {
        if (recursive) {
            retval = retval && algo_lib::InsertStrptrMaybe(line);
        }
        retval = retval && acr_my::InsertStrptrMaybe(line);
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

// --- acr_my.FDb._db.LoadSsimfileMaybe
// Load specified ssimfile.
bool acr_my::LoadSsimfileMaybe(algo::strptr fname, bool recursive) {
    bool retval = true;
    if (FileQ(fname)) {
        retval = acr_my::LoadTuplesFile(fname, recursive);
    }
    return retval;
}

// --- acr_my.FDb._db.Steps
// Calls Step function of dependencies
void acr_my::Steps() {
    algo_lib::Step(); // dependent namespace specified via (dev.targdep)
}

// --- acr_my.FDb._db.XrefMaybe
// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Caller must Delete or Unref such row.
bool acr_my::_db_XrefMaybe() {
    bool retval = true;
    return retval;
}

// --- acr_my.FDb.nsdb.Alloc
// Allocate memory for new default row.
// If out of memory, process is killed.
acr_my::FNsdb& acr_my::nsdb_Alloc() {
    acr_my::FNsdb* row = nsdb_AllocMaybe();
    if (UNLIKELY(row == NULL)) {
        FatalErrorExit("acr_my.out_of_mem  field:acr_my.FDb.nsdb  comment:'Alloc failed'");
    }
    return *row;
}

// --- acr_my.FDb.nsdb.AllocMaybe
// Allocate memory for new element. If out of memory, return NULL.
acr_my::FNsdb* acr_my::nsdb_AllocMaybe() {
    acr_my::FNsdb *row = (acr_my::FNsdb*)nsdb_AllocMem();
    if (row) {
        new (row) acr_my::FNsdb; // call constructor
    }
    return row;
}

// --- acr_my.FDb.nsdb.InsertMaybe
// Create new row from struct.
// Return pointer to new element, or NULL if insertion failed (due to out-of-memory, duplicate key, etc)
acr_my::FNsdb* acr_my::nsdb_InsertMaybe(const dmmeta::Nsdb &value) {
    acr_my::FNsdb *row = &nsdb_Alloc(); // if out of memory, process dies. if input error, return NULL.
    nsdb_CopyIn(*row,const_cast<dmmeta::Nsdb&>(value));
    bool ok = nsdb_XrefMaybe(*row); // this may return false
    if (!ok) {
        nsdb_RemoveLast(); // delete offending row, any existing xrefs are cleared
        row = NULL; // forget this ever happened
    }
    return row;
}

// --- acr_my.FDb.nsdb.AllocMem
// Allocate space for one element. If no memory available, return NULL.
void* acr_my::nsdb_AllocMem() {
    u64 new_nelems     = _db.nsdb_n+1;
    // compute level and index on level
    u64 bsr   = algo::u64_BitScanReverse(new_nelems);
    u64 base  = u64(1)<<bsr;
    u64 index = new_nelems-base;
    void *ret = NULL;
    // if level doesn't exist yet, create it
    acr_my::FNsdb*  lev   = NULL;
    if (bsr < 32) {
        lev = _db.nsdb_lary[bsr];
        if (!lev) {
            lev=(acr_my::FNsdb*)algo_lib::malloc_AllocMem(sizeof(acr_my::FNsdb) * (u64(1)<<bsr));
            _db.nsdb_lary[bsr] = lev;
        }
    }
    // allocate element from this level
    if (lev) {
        _db.nsdb_n = i32(new_nelems);
        ret = lev + index;
    }
    return ret;
}

// --- acr_my.FDb.nsdb.RemoveLast
// Delete last element of array. Do nothing if array is empty.
void acr_my::nsdb_RemoveLast() {
    u64 n = _db.nsdb_n;
    if (n > 0) {
        n -= 1;
        nsdb_qFind(u64(n)).~FNsdb();
        _db.nsdb_n = i32(n);
    }
}

// --- acr_my.FDb.nsdb.InputMaybe
static bool acr_my::nsdb_InputMaybe(dmmeta::Nsdb &elem) {
    bool retval = true;
    retval = nsdb_InsertMaybe(elem) != nullptr;
    return retval;
}

// --- acr_my.FDb.nsdb.XrefMaybe
// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Caller must Delete or Unref such row.
bool acr_my::nsdb_XrefMaybe(acr_my::FNsdb &row) {
    bool retval = true;
    (void)row;
    return retval;
}

// --- acr_my.FDb.ssimfile.Alloc
// Allocate memory for new default row.
// If out of memory, process is killed.
acr_my::FSsimfile& acr_my::ssimfile_Alloc() {
    acr_my::FSsimfile* row = ssimfile_AllocMaybe();
    if (UNLIKELY(row == NULL)) {
        FatalErrorExit("acr_my.out_of_mem  field:acr_my.FDb.ssimfile  comment:'Alloc failed'");
    }
    return *row;
}

// --- acr_my.FDb.ssimfile.AllocMaybe
// Allocate memory for new element. If out of memory, return NULL.
acr_my::FSsimfile* acr_my::ssimfile_AllocMaybe() {
    acr_my::FSsimfile *row = (acr_my::FSsimfile*)ssimfile_AllocMem();
    if (row) {
        new (row) acr_my::FSsimfile; // call constructor
    }
    return row;
}

// --- acr_my.FDb.ssimfile.InsertMaybe
// Create new row from struct.
// Return pointer to new element, or NULL if insertion failed (due to out-of-memory, duplicate key, etc)
acr_my::FSsimfile* acr_my::ssimfile_InsertMaybe(const dmmeta::Ssimfile &value) {
    acr_my::FSsimfile *row = &ssimfile_Alloc(); // if out of memory, process dies. if input error, return NULL.
    ssimfile_CopyIn(*row,const_cast<dmmeta::Ssimfile&>(value));
    bool ok = ssimfile_XrefMaybe(*row); // this may return false
    if (!ok) {
        ssimfile_RemoveLast(); // delete offending row, any existing xrefs are cleared
        row = NULL; // forget this ever happened
    }
    return row;
}

// --- acr_my.FDb.ssimfile.AllocMem
// Allocate space for one element. If no memory available, return NULL.
void* acr_my::ssimfile_AllocMem() {
    u64 new_nelems     = _db.ssimfile_n+1;
    // compute level and index on level
    u64 bsr   = algo::u64_BitScanReverse(new_nelems);
    u64 base  = u64(1)<<bsr;
    u64 index = new_nelems-base;
    void *ret = NULL;
    // if level doesn't exist yet, create it
    acr_my::FSsimfile*  lev   = NULL;
    if (bsr < 32) {
        lev = _db.ssimfile_lary[bsr];
        if (!lev) {
            lev=(acr_my::FSsimfile*)algo_lib::malloc_AllocMem(sizeof(acr_my::FSsimfile) * (u64(1)<<bsr));
            _db.ssimfile_lary[bsr] = lev;
        }
    }
    // allocate element from this level
    if (lev) {
        _db.ssimfile_n = i32(new_nelems);
        ret = lev + index;
    }
    return ret;
}

// --- acr_my.FDb.ssimfile.RemoveLast
// Delete last element of array. Do nothing if array is empty.
void acr_my::ssimfile_RemoveLast() {
    u64 n = _db.ssimfile_n;
    if (n > 0) {
        n -= 1;
        ssimfile_qFind(u64(n)).~FSsimfile();
        _db.ssimfile_n = i32(n);
    }
}

// --- acr_my.FDb.ssimfile.InputMaybe
static bool acr_my::ssimfile_InputMaybe(dmmeta::Ssimfile &elem) {
    bool retval = true;
    retval = ssimfile_InsertMaybe(elem) != nullptr;
    return retval;
}

// --- acr_my.FDb.ssimfile.XrefMaybe
// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Caller must Delete or Unref such row.
bool acr_my::ssimfile_XrefMaybe(acr_my::FSsimfile &row) {
    bool retval = true;
    (void)row;
    return retval;
}

// --- acr_my.FDb.trace.RowidFind
// find trace by row id (used to implement reflection)
static algo::ImrowPtr acr_my::trace_RowidFind(int t) {
    return algo::ImrowPtr(t==0 ? u64(&_db.trace) : u64(0));
}

// --- acr_my.FDb.trace.N
// Function return 1
inline static i32 acr_my::trace_N() {
    return 1;
}

// --- acr_my.FDb..Init
// Set all fields to initial values.
void acr_my::FDb_Init() {
    _db.ary_ns_elems 	= 0; // (acr_my.FDb.ary_ns)
    _db.ary_ns_n     	= 0; // (acr_my.FDb.ary_ns)
    _db.ary_ns_max   	= 0; // (acr_my.FDb.ary_ns)
    _db.started = bool(false);
    // initialize LAry nsdb (acr_my.FDb.nsdb)
    _db.nsdb_n = 0;
    memset(_db.nsdb_lary, 0, sizeof(_db.nsdb_lary)); // zero out all level pointers
    acr_my::FNsdb* nsdb_first = (acr_my::FNsdb*)algo_lib::malloc_AllocMem(sizeof(acr_my::FNsdb) * (u64(1)<<4));
    if (!nsdb_first) {
        FatalErrorExit("out of memory");
    }
    for (int i = 0; i < 4; i++) {
        _db.nsdb_lary[i]  = nsdb_first;
        nsdb_first    += 1ULL<<i;
    }
    // initialize LAry ssimfile (acr_my.FDb.ssimfile)
    _db.ssimfile_n = 0;
    memset(_db.ssimfile_lary, 0, sizeof(_db.ssimfile_lary)); // zero out all level pointers
    acr_my::FSsimfile* ssimfile_first = (acr_my::FSsimfile*)algo_lib::malloc_AllocMem(sizeof(acr_my::FSsimfile) * (u64(1)<<4));
    if (!ssimfile_first) {
        FatalErrorExit("out of memory");
    }
    for (int i = 0; i < 4; i++) {
        _db.ssimfile_lary[i]  = ssimfile_first;
        ssimfile_first    += 1ULL<<i;
    }

    acr_my::InitReflection();
}

// --- acr_my.FDb..Uninit
void acr_my::FDb_Uninit() {
    acr_my::FDb &row = _db; (void)row;

    // acr_my.FDb.ssimfile.Uninit (Lary)  //
    // skip destruction in global scope

    // acr_my.FDb.nsdb.Uninit (Lary)  //
    // skip destruction in global scope

    // acr_my.FDb.ary_ns.Uninit (Tary)  //
    // remove all elements from acr_my.FDb.ary_ns
    ary_ns_RemoveAll();
    // free memory for Tary acr_my.FDb.ary_ns
    algo_lib::malloc_FreeMem(_db.ary_ns_elems, sizeof(algo::cstring)*_db.ary_ns_max); // (acr_my.FDb.ary_ns)
}

// --- acr_my.FNsdb.base.CopyOut
// Copy fields out of row
void acr_my::nsdb_CopyOut(acr_my::FNsdb &row, dmmeta::Nsdb &out) {
    out.ns = row.ns;
    out.comment = row.comment;
}

// --- acr_my.FNsdb.base.CopyIn
// Copy fields in to row
void acr_my::nsdb_CopyIn(acr_my::FNsdb &row, dmmeta::Nsdb &in) {
    row.ns = in.ns;
    row.comment = in.comment;
}

// --- acr_my.FSsimfile.base.CopyOut
// Copy fields out of row
void acr_my::ssimfile_CopyOut(acr_my::FSsimfile &row, dmmeta::Ssimfile &out) {
    out.ssimfile = row.ssimfile;
    out.ctype = row.ctype;
}

// --- acr_my.FSsimfile.base.CopyIn
// Copy fields in to row
void acr_my::ssimfile_CopyIn(acr_my::FSsimfile &row, dmmeta::Ssimfile &in) {
    row.ssimfile = in.ssimfile;
    row.ctype = in.ctype;
}

// --- acr_my.FSsimfile.ssimns.Get
algo::Smallstr16 acr_my::ssimns_Get(acr_my::FSsimfile& ssimfile) {
    algo::Smallstr16 ret(algo::Pathcomp(ssimfile.ssimfile, ".LL"));
    return ret;
}

// --- acr_my.FSsimfile.ns.Get
algo::Smallstr16 acr_my::ns_Get(acr_my::FSsimfile& ssimfile) {
    algo::Smallstr16 ret(algo::Pathcomp(ssimfile.ssimfile, ".LL"));
    return ret;
}

// --- acr_my.FSsimfile.name.Get
algo::Smallstr50 acr_my::name_Get(acr_my::FSsimfile& ssimfile) {
    algo::Smallstr50 ret(algo::Pathcomp(ssimfile.ssimfile, ".RR"));
    return ret;
}

// --- acr_my.FieldId.value.ToCstr
// Convert numeric value of field to one of predefined string constants.
// If string is found, return a static C string. Otherwise, return NULL.
const char* acr_my::value_ToCstr(const acr_my::FieldId& parent) {
    const char *ret = NULL;
    switch(value_GetEnum(parent)) {
        case acr_my_FieldId_value          : ret = "value";  break;
    }
    return ret;
}

// --- acr_my.FieldId.value.Print
// Convert value to a string. First, attempt conversion to a known string.
// If no string matches, print value as a numeric value.
void acr_my::value_Print(const acr_my::FieldId& parent, algo::cstring &lhs) {
    const char *strval = value_ToCstr(parent);
    if (strval) {
        lhs << strval;
    } else {
        lhs << parent.value;
    }
}

// --- acr_my.FieldId.value.SetStrptrMaybe
// Convert string to field.
// If the string is invalid, do not modify field and return false.
// In case of success, return true
bool acr_my::value_SetStrptrMaybe(acr_my::FieldId& parent, algo::strptr rhs) {
    bool ret = false;
    switch (elems_N(rhs)) {
        case 5: {
            switch (u64(algo::ReadLE32(rhs.elems))|(u64(rhs[4])<<32)) {
                case LE_STR5('v','a','l','u','e'): {
                    value_SetEnum(parent,acr_my_FieldId_value); ret = true; break;
                }
            }
            break;
        }
    }
    return ret;
}

// --- acr_my.FieldId.value.SetStrptr
// Convert string to field.
// If the string is invalid, set numeric value to DFLT
void acr_my::value_SetStrptr(acr_my::FieldId& parent, algo::strptr rhs, acr_my_FieldIdEnum dflt) {
    if (!value_SetStrptrMaybe(parent,rhs)) value_SetEnum(parent,dflt);
}

// --- acr_my.FieldId.value.ReadStrptrMaybe
// Convert string to field. Return success value
bool acr_my::value_ReadStrptrMaybe(acr_my::FieldId& parent, algo::strptr rhs) {
    bool retval = false;
    retval = value_SetStrptrMaybe(parent,rhs); // try symbol conversion
    if (!retval) { // didn't work? try reading as underlying type
        retval = i32_ReadStrptrMaybe(parent.value,rhs);
    }
    return retval;
}

// --- acr_my.FieldId..ReadStrptrMaybe
// Read fields of acr_my::FieldId from an ascii string.
// The format of the string is the format of the acr_my::FieldId's only field
bool acr_my::FieldId_ReadStrptrMaybe(acr_my::FieldId &parent, algo::strptr in_str) {
    bool retval = true;
    retval = retval && value_ReadStrptrMaybe(parent, in_str);
    return retval;
}

// --- acr_my.FieldId..Print
// print string representation of ROW to string STR
// cfmt:acr_my.FieldId.String  printfmt:Raw
void acr_my::FieldId_Print(acr_my::FieldId& row, algo::cstring& str) {
    acr_my::value_Print(row, str);
}

// --- acr_my.TableId.value.ToCstr
// Convert numeric value of field to one of predefined string constants.
// If string is found, return a static C string. Otherwise, return NULL.
const char* acr_my::value_ToCstr(const acr_my::TableId& parent) {
    const char *ret = NULL;
    switch(value_GetEnum(parent)) {
        case acr_my_TableId_dmmeta_Nsdb    : ret = "dmmeta.Nsdb";  break;
        case acr_my_TableId_dmmeta_Ssimfile: ret = "dmmeta.Ssimfile";  break;
    }
    return ret;
}

// --- acr_my.TableId.value.Print
// Convert value to a string. First, attempt conversion to a known string.
// If no string matches, print value as a numeric value.
void acr_my::value_Print(const acr_my::TableId& parent, algo::cstring &lhs) {
    const char *strval = value_ToCstr(parent);
    if (strval) {
        lhs << strval;
    } else {
        lhs << parent.value;
    }
}

// --- acr_my.TableId.value.SetStrptrMaybe
// Convert string to field.
// If the string is invalid, do not modify field and return false.
// In case of success, return true
bool acr_my::value_SetStrptrMaybe(acr_my::TableId& parent, algo::strptr rhs) {
    bool ret = false;
    switch (elems_N(rhs)) {
        case 11: {
            switch (algo::ReadLE64(rhs.elems)) {
                case LE_STR8('d','m','m','e','t','a','.','N'): {
                    if (memcmp(rhs.elems+8,"sdb",3)==0) { value_SetEnum(parent,acr_my_TableId_dmmeta_Nsdb); ret = true; break; }
                    break;
                }
                case LE_STR8('d','m','m','e','t','a','.','n'): {
                    if (memcmp(rhs.elems+8,"sdb",3)==0) { value_SetEnum(parent,acr_my_TableId_dmmeta_nsdb); ret = true; break; }
                    break;
                }
            }
            break;
        }
        case 15: {
            switch (algo::ReadLE64(rhs.elems)) {
                case LE_STR8('d','m','m','e','t','a','.','S'): {
                    if (memcmp(rhs.elems+8,"simfile",7)==0) { value_SetEnum(parent,acr_my_TableId_dmmeta_Ssimfile); ret = true; break; }
                    break;
                }
                case LE_STR8('d','m','m','e','t','a','.','s'): {
                    if (memcmp(rhs.elems+8,"simfile",7)==0) { value_SetEnum(parent,acr_my_TableId_dmmeta_ssimfile); ret = true; break; }
                    break;
                }
            }
            break;
        }
    }
    return ret;
}

// --- acr_my.TableId.value.SetStrptr
// Convert string to field.
// If the string is invalid, set numeric value to DFLT
void acr_my::value_SetStrptr(acr_my::TableId& parent, algo::strptr rhs, acr_my_TableIdEnum dflt) {
    if (!value_SetStrptrMaybe(parent,rhs)) value_SetEnum(parent,dflt);
}

// --- acr_my.TableId.value.ReadStrptrMaybe
// Convert string to field. Return success value
bool acr_my::value_ReadStrptrMaybe(acr_my::TableId& parent, algo::strptr rhs) {
    bool retval = false;
    retval = value_SetStrptrMaybe(parent,rhs); // try symbol conversion
    if (!retval) { // didn't work? try reading as underlying type
        retval = i32_ReadStrptrMaybe(parent.value,rhs);
    }
    return retval;
}

// --- acr_my.TableId..ReadStrptrMaybe
// Read fields of acr_my::TableId from an ascii string.
// The format of the string is the format of the acr_my::TableId's only field
bool acr_my::TableId_ReadStrptrMaybe(acr_my::TableId &parent, algo::strptr in_str) {
    bool retval = true;
    retval = retval && value_ReadStrptrMaybe(parent, in_str);
    return retval;
}

// --- acr_my.TableId..Print
// print string representation of ROW to string STR
// cfmt:acr_my.TableId.String  printfmt:Raw
void acr_my::TableId_Print(acr_my::TableId& row, algo::cstring& str) {
    acr_my::value_Print(row, str);
}

// --- acr_my...SizeCheck
inline static void acr_my::SizeCheck() {
}

// --- acr_my...StaticCheck
void acr_my::StaticCheck() {
    algo_assert(_offset_of(acr_my::FieldId, value) + sizeof(((acr_my::FieldId*)0)->value) == sizeof(acr_my::FieldId));
}

// --- acr_my...main
int main(int argc, char **argv) {
    try {
        algo_lib::FDb_Init();
        acr_my::FDb_Init();
        algo_lib::_db.argc = argc;
        algo_lib::_db.argv = argv;
        algo_lib::IohookInit();
        acr_my::ReadArgv(); // dmmeta.main:acr_my
        acr_my::Main(); // user-defined main
    } catch(algo_lib::ErrorX &x) {
        prerr("acr_my.error  " << x); // there may be additional hints in DetachBadTags
        algo_lib::_db.exit_code = 1;
    }
    if (algo_lib::_db.last_signal) {
        algo_lib::_db.exit_code = 1;
    }
    try {
        acr_my::FDb_Uninit();
        algo_lib::FDb_Uninit();
    } catch(algo_lib::ErrorX &) {
        // don't print anything, might crash
        algo_lib::_db.exit_code = 1;
    }
    // only the lower 1 byte makes it to the outside world
    (void)i32_UpdateMin(algo_lib::_db.exit_code,255);
    return algo_lib::_db.exit_code;
}

// --- acr_my...WinMain
#if defined(WIN32)
int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int) {
    return main(__argc,__argv);
}
#endif
