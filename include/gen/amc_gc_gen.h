//
// include/gen/amc_gc_gen.h
// Generated by AMC
//
// (C) AlgoEngineering LLC 2008-2013
// (C) NYSE | Intercontinental Exchange 2013-2016
//


#pragma once
#include "include/gen/algo_gen.h"
#include "include/gen/command_gen.h"
//#pragma endinclude

// --- amc_gc_FieldIdEnum

enum amc_gc_FieldIdEnum {        // amc_gc.FieldId.value
     amc_gc_FieldId_value   = 0
};

enum { amc_gc_FieldIdEnum_N = 1 };

namespace amc_gc { struct Acr; }
namespace amc_gc { struct Check; }
namespace amc_gc { struct trace; }
namespace amc_gc { struct FDb; }
namespace amc_gc { struct FieldId; }
namespace amc_gc {
}//pkey typedefs
namespace amc_gc {
extern const char *amc_gc_help;
extern const char *amc_gc_syntax;
extern FDb _db;

// --- amc_gc.Acr
struct Acr { // amc_gc.Acr
    algo::cstring   acr_path;      //   "bin/acr"  path for executable
    command::acr    acr_cmd;       // command line for child process
    algo::cstring   acr_stdin;     // redirect for stdin
    algo::cstring   acr_stdout;    // redirect for stdout
    algo::cstring   acr_stderr;    // redirect for stderr
    pid_t           acr_pid;       //   0  pid of running child process
    i32             acr_timeout;   //   0  optional timeout for child process
    i32             acr_status;    //   0  last exit status of child process
    Acr();
    ~Acr();
private:
    // reftype of amc_gc.Acr.acr prohibits copy
    Acr(const Acr&){ /*disallow copy constructor */}
    void operator =(const Acr&){ /*disallow direct assignment */}
};

// Start subprocess
// If subprocess already running, do nothing. Otherwise, start it
int                  acr_Start(amc_gc::Acr& parent) __attribute__((nothrow));
// Kill subprocess and wait
void                 acr_Kill(amc_gc::Acr& parent);
// Wait for subprocess to return
void                 acr_Wait(amc_gc::Acr& parent) __attribute__((nothrow));
// Start + Wait
// Execute subprocess and return exit code
int                  acr_Exec(amc_gc::Acr& parent) __attribute__((nothrow));
// Call execv()
// Call execv with specified parameters -- cprint:acr.Argv
int                  acr_Execv(amc_gc::Acr& parent) __attribute__((nothrow));
algo::tempstr        acr_ToCmdline(amc_gc::Acr& parent) __attribute__((nothrow));

// Set all fields to initial values.
void                 Acr_Init(amc_gc::Acr& parent);
void                 Acr_Uninit(amc_gc::Acr& parent) __attribute__((nothrow));

// --- amc_gc.Check
struct Check { // amc_gc.Check
    algo::cstring   acr_path;      //   "bin/acr"  path for executable
    command::acr    acr_cmd;       // command line for child process
    algo::cstring   acr_stdin;     // redirect for stdin
    algo::cstring   acr_stdout;    // redirect for stdout
    algo::cstring   acr_stderr;    // redirect for stderr
    pid_t           acr_pid;       //   0  pid of running child process
    i32             acr_timeout;   //   0  optional timeout for child process
    i32             acr_status;    //   0  last exit status of child process
    algo::cstring   amc_path;      //   "bin/amc"  path for executable
    command::amc    amc_cmd;       // command line for child process
    algo::cstring   amc_stdin;     // redirect for stdin
    algo::cstring   amc_stdout;    // redirect for stdout
    algo::cstring   amc_stderr;    // redirect for stderr
    pid_t           amc_pid;       //   0  pid of running child process
    i32             amc_timeout;   //   0  optional timeout for child process
    i32             amc_status;    //   0  last exit status of child process
    algo::cstring   abt_path;      //   "bin/abt"  path for executable
    command::abt    abt_cmd;       // command line for child process
    algo::cstring   abt_stdin;     // redirect for stdin
    algo::cstring   abt_stdout;    // redirect for stdout
    algo::cstring   abt_stderr;    // redirect for stderr
    pid_t           abt_pid;       //   0  pid of running child process
    i32             abt_timeout;   //   0  optional timeout for child process
    i32             abt_status;    //   0  last exit status of child process
    Check();
    ~Check();
private:
    // reftype of amc_gc.Check.acr prohibits copy
    // reftype of amc_gc.Check.amc prohibits copy
    // reftype of amc_gc.Check.abt prohibits copy
    // ... and several other reasons
    Check(const Check&){ /*disallow copy constructor */}
    void operator =(const Check&){ /*disallow direct assignment */}
};

// Start subprocess
// If subprocess already running, do nothing. Otherwise, start it
int                  acr_Start(amc_gc::Check& parent) __attribute__((nothrow));
// Kill subprocess and wait
void                 acr_Kill(amc_gc::Check& parent);
// Wait for subprocess to return
void                 acr_Wait(amc_gc::Check& parent) __attribute__((nothrow));
// Start + Wait
// Execute subprocess and return exit code
int                  acr_Exec(amc_gc::Check& parent) __attribute__((nothrow));
// Call execv()
// Call execv with specified parameters -- cprint:acr.Argv
int                  acr_Execv(amc_gc::Check& parent) __attribute__((nothrow));
algo::tempstr        acr_ToCmdline(amc_gc::Check& parent) __attribute__((nothrow));

// Start subprocess
// If subprocess already running, do nothing. Otherwise, start it
int                  amc_Start(amc_gc::Check& parent) __attribute__((nothrow));
// Kill subprocess and wait
void                 amc_Kill(amc_gc::Check& parent);
// Wait for subprocess to return
void                 amc_Wait(amc_gc::Check& parent) __attribute__((nothrow));
// Start + Wait
// Execute subprocess and return exit code
int                  amc_Exec(amc_gc::Check& parent) __attribute__((nothrow));
// Call execv()
// Call execv with specified parameters -- cprint:amc.Argv
int                  amc_Execv(amc_gc::Check& parent) __attribute__((nothrow));
algo::tempstr        amc_ToCmdline(amc_gc::Check& parent) __attribute__((nothrow));

// Start subprocess
// If subprocess already running, do nothing. Otherwise, start it
int                  abt_Start(amc_gc::Check& parent) __attribute__((nothrow));
// Kill subprocess and wait
void                 abt_Kill(amc_gc::Check& parent);
// Wait for subprocess to return
void                 abt_Wait(amc_gc::Check& parent) __attribute__((nothrow));
// Start + Wait
// Execute subprocess and return exit code
int                  abt_Exec(amc_gc::Check& parent) __attribute__((nothrow));
// Call execv()
// Call execv with specified parameters -- cprint:abt.Argv
int                  abt_Execv(amc_gc::Check& parent) __attribute__((nothrow));
algo::tempstr        abt_ToCmdline(amc_gc::Check& parent) __attribute__((nothrow));

// Set all fields to initial values.
void                 Check_Init(amc_gc::Check& parent);
void                 Check_Uninit(amc_gc::Check& parent) __attribute__((nothrow));

// --- amc_gc.trace
#pragma pack(push,1)
struct trace { // amc_gc.trace
    trace();
};
#pragma pack(pop)

// print string representation of amc_gc::trace to string LHS, no header -- cprint:amc_gc.trace.String
void                 trace_Print(amc_gc::trace & row, algo::cstring &str) __attribute__((nothrow));

// --- amc_gc.FDb
// create: amc_gc.FDb._db (Global)
struct FDb { // amc_gc.FDb
    command::amc_gc   cmdline;        //
    u32               n_cur;          //   1
    u32               n_del;          //   0
    u32               n_cppline;      //   0
    u32               n_newcppline;   //   0
    algo::cstring     buildlog;       //   "temp/amc_gc.build"
    algo::cstring     basedir;        //
    u32               n_total;        //   0
    amc_gc::trace     trace;          //
};

// Main function
void                 MainArgs(int argc, char **argv);
// Main loop.
void                 MainLoop();
// Main step
void                 Step();
// Main function
void                 Main();
void                 StaticCheck();
// Parse strptr into known type and add to database.
// Return value is true unless an error occurs. If return value is false, algo_lib::_db.errtext has error text
bool                 InsertStrptrMaybe(algo::strptr str);
// Load all finputs from given directory.
bool                 LoadTuplesMaybe(algo::strptr root) __attribute__((nothrow));
// Load specified ssimfile.
bool                 LoadSsimfileMaybe(algo::strptr fname) __attribute__((nothrow));
// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Call Unref or Delete to cleanup partially inserted row.
bool                 _db_XrefMaybe();

// Set all fields to initial values.
void                 FDb_Init();
void                 FDb_Uninit() __attribute__((nothrow));

// --- amc_gc.FieldId
#pragma pack(push,1)
struct FieldId { // amc_gc.FieldId: Field read helper
    i32   value;   //   -1
    inline operator amc_gc_FieldIdEnum() const;
    explicit FieldId(i32                            in_value);
    FieldId(amc_gc_FieldIdEnum arg);
    FieldId();
};
#pragma pack(pop)

// Get value of field as enum type
amc_gc_FieldIdEnum   value_GetEnum(const amc_gc::FieldId& parent) __attribute__((nothrow));
// Set value of field from enum type.
void                 value_SetEnum(amc_gc::FieldId& parent, amc_gc_FieldIdEnum rhs) __attribute__((nothrow));
// Convert numeric value of field to one of predefined string constants.
// If string is found, return a static C string. Otherwise, return NULL.
const char*          value_ToCstr(const amc_gc::FieldId& parent) __attribute__((nothrow));
// Convert value to a string. First, attempt conversion to a known string.
// If no string matches, print value as a numeric value.
void                 value_Print(const amc_gc::FieldId& parent, algo::cstring &lhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, do not modify field and return false.
// In case of success, return true
bool                 value_SetStrptrMaybe(amc_gc::FieldId& parent, algo::strptr rhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, set numeric value to DFLT
void                 value_SetStrptr(amc_gc::FieldId& parent, algo::strptr rhs, amc_gc_FieldIdEnum dflt) __attribute__((nothrow));
// Convert string to field. Return success value
bool                 value_ReadStrptrMaybe(amc_gc::FieldId& parent, algo::strptr rhs) __attribute__((nothrow));

// Read fields of amc_gc::FieldId from an ascii string.
// The format of the string is the format of the amc_gc::FieldId's only field
bool                 FieldId_ReadStrptrMaybe(amc_gc::FieldId &parent, algo::strptr in_str);
// Set all fields to initial values.
void                 FieldId_Init(amc_gc::FieldId& parent);
// print string representation of amc_gc::FieldId to string LHS, no header -- cprint:amc_gc.FieldId.String
void                 FieldId_Print(amc_gc::FieldId & row, algo::cstring &str) __attribute__((nothrow));
int                  main(int argc, char **argv);
} // end namespace amc_gc
namespace algo {
inline algo::cstring &operator <<(algo::cstring &str, const amc_gc::trace &row);// cfmt:amc_gc.trace.String
inline algo::cstring &operator <<(algo::cstring &str, const amc_gc::FieldId &row);// cfmt:amc_gc.FieldId.String
}