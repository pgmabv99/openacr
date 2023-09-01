//
// cpp/gen/bash2html_gen.cpp
// Generated by AMC
//
// (C) AlgoEngineering LLC 2008-2013
// (C) NYSE | Intercontinental Exchange 2013-2016
//


#include "include/algo.h"  // hard-coded include
#include "include/gen/bash2html_gen.h"
#include "include/gen/bash2html_gen.inl.h"
#include "include/gen/command_gen.h"
#include "include/gen/command_gen.inl.h"
#include "include/gen/lib_json_gen.h"
#include "include/gen/lib_json_gen.inl.h"
#include "include/gen/lib_prot_gen.h"
#include "include/gen/lib_prot_gen.inl.h"
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
"    -in       string  Input directory or filename, - for stdin. default: \"data\"\n"
"    -test             Produce Test Output. default: false\n"
"    -verbose          Enable verbose mode\n"
"    -debug            Enable debug mode\n"
"    -version          Show version information\n"
"    -sig              Print SHA1 signatures for dispatches\n"
"    -help             Print this screen and exit\n"
;


const char *bash2html_syntax =
"-in:string=\"data\"\n"
" -test:flag\n"
;
} // namespace bash2html
namespace bash2html { // gen:ns_print_proto
    // Load statically available data into tables, register tables and database.
    static void          InitReflection();
    // find trace by row id (used to implement reflection)
    static algo::ImrowPtr trace_RowidFind(int t) __attribute__((nothrow));
    // Function return 1
    static i32           trace_N() __attribute__((__warn_unused_result__, nothrow, pure));
    static void          SizeCheck();
} // gen:ns_print_proto

// --- bash2html.trace..Print
// print string representation of bash2html::trace to string LHS, no header -- cprint:bash2html.trace.String
void bash2html::trace_Print(bash2html::trace & row, algo::cstring &str) {
    algo::tempstr temp;
    str << "bash2html.trace";
    (void)row;//only to avoid -Wunused-parameter
}

// --- bash2html.FDb._db.MainArgs
// Main function
void bash2html::MainArgs(int argc, char **argv) {
    Argtuple argtuple;
    Argtuple_ReadArgv(argtuple, argc,argv,bash2html_syntax, bash2html_help);
    vrfy(bash2html_ReadTupleMaybe(bash2html::_db.cmdline, argtuple.tuple),"where:read_cmdline");
    vrfy(bash2html::LoadTuplesMaybe(bash2html::_db.cmdline.in)
    ,tempstr()<<"where:load_input  "<<algo_lib::DetachBadTags());
    bash2html::Main(); // call through to user-defined main
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
bool bash2html::LoadTuplesMaybe(algo::strptr root) {
    bool retval = true;
    (void)root;//only to avoid -Wunused-parameter
    return retval;
}

// --- bash2html.FDb._db.LoadSsimfileMaybe
// Load specified ssimfile.
bool bash2html::LoadSsimfileMaybe(algo::strptr fname) {
    bool retval = true;
    if (FileQ(fname)) {
        retval = algo_lib::LoadTuplesFile(fname, bash2html::InsertStrptrMaybe, true);
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
    retval = retval && bash2html::value_ReadStrptrMaybe(parent, in_str);
    return retval;
}

// --- bash2html.FieldId..Print
// print string representation of bash2html::FieldId to string LHS, no header -- cprint:bash2html.FieldId.String
void bash2html::FieldId_Print(bash2html::FieldId & row, algo::cstring &str) {
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
        bash2html::MainArgs(algo_lib::_db.argc,algo_lib::_db.argv); // dmmeta.main:bash2html
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