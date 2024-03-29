//
// include/gen/strconv_gen.h
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


#pragma once
#include "include/gen/command_gen.h"
//#pragma endinclude
// gen:ns_enums

// --- strconv_FieldIdEnum

enum strconv_FieldIdEnum {        // strconv.FieldId.value
     strconv_FieldId_value   = 0
};

enum { strconv_FieldIdEnum_N = 1 };

namespace strconv { // gen:ns_pkeytypedef
} // gen:ns_pkeytypedef
namespace strconv { // gen:ns_field
extern const char *strconv_help;
} // gen:ns_field
// gen:ns_fwddecl2
namespace strconv { struct trace; }
namespace strconv { struct FDb; }
namespace strconv { struct FieldId; }
namespace strconv { extern struct strconv::FDb _db; }
namespace strconv { // gen:ns_print_struct

// --- strconv.trace
#pragma pack(push,1)
struct trace { // strconv.trace
    trace();
};
#pragma pack(pop)

// print string representation of ROW to string STR
// cfmt:strconv.trace.String  printfmt:Tuple
// func:strconv.trace..Print
void                 trace_Print(strconv::trace& row, algo::cstring& str) __attribute__((nothrow));

// --- strconv.FDb
// create: strconv.FDb._db (Global)
struct FDb { // strconv.FDb: In-memory database for strconv
    command::strconv   cmdline;   //
    strconv::trace     trace;     //
};

// Read argc,argv directly into the fields of the command line(s)
// The following fields are updated:
//     strconv.FDb.cmdline
//     algo_lib.FDb.cmdline
// func:strconv.FDb._db.ReadArgv
void                 ReadArgv() __attribute__((nothrow));
// Main loop.
// func:strconv.FDb._db.MainLoop
void                 MainLoop();
// Main step
// func:strconv.FDb._db.Step
void                 Step();
// Main function
// func:strconv.FDb._db.Main
// this function is 'extrn' and implemented by user
void                 Main();
// func:strconv.FDb._db.StaticCheck
void                 StaticCheck();
// Parse strptr into known type and add to database.
// Return value is true unless an error occurs. If return value is false, algo_lib::_db.errtext has error text
// func:strconv.FDb._db.InsertStrptrMaybe
bool                 InsertStrptrMaybe(algo::strptr str);
// Load all finputs from given directory.
// func:strconv.FDb._db.LoadTuplesMaybe
bool                 LoadTuplesMaybe(algo::strptr root, bool recursive) __attribute__((nothrow));
// Load all finputs from given file.
// Read tuples from file FNAME into this namespace's in-memory database.
// If RECURSIVE is TRUE, then also load these tuples into any parent namespaces
// It a file referred to by FNAME is missing, no error is reported (it's considered an empty set).
// Function returns TRUE if all records were parsed and inserted without error.
// If the function returns FALSE, use algo_lib::DetachBadTags() for error description
// func:strconv.FDb._db.LoadTuplesFile
bool                 LoadTuplesFile(algo::strptr fname, bool recursive) __attribute__((nothrow));
// Load all finputs from given file descriptor.
// func:strconv.FDb._db.LoadTuplesFd
bool                 LoadTuplesFd(algo::Fildes fd, algo::strptr fname, bool recursive) __attribute__((nothrow));
// Load specified ssimfile.
// func:strconv.FDb._db.LoadSsimfileMaybe
bool                 LoadSsimfileMaybe(algo::strptr fname, bool recursive) __attribute__((nothrow));
// Calls Step function of dependencies
// func:strconv.FDb._db.Steps
void                 Steps();
// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Caller must Delete or Unref such row.
// func:strconv.FDb._db.XrefMaybe
bool                 _db_XrefMaybe();

// Set all fields to initial values.
// func:strconv.FDb..Init
void                 FDb_Init();
// func:strconv.FDb..Uninit
void                 FDb_Uninit() __attribute__((nothrow));

// --- strconv.FieldId
#pragma pack(push,1)
struct FieldId { // strconv.FieldId: Field read helper
    i32   value;   //   -1
    inline operator strconv_FieldIdEnum() const;
    explicit FieldId(i32                            in_value);
    FieldId(strconv_FieldIdEnum arg);
    FieldId();
};
#pragma pack(pop)

// Get value of field as enum type
// func:strconv.FieldId.value.GetEnum
strconv_FieldIdEnum  value_GetEnum(const strconv::FieldId& parent) __attribute__((nothrow));
// Set value of field from enum type.
// func:strconv.FieldId.value.SetEnum
void                 value_SetEnum(strconv::FieldId& parent, strconv_FieldIdEnum rhs) __attribute__((nothrow));
// Convert numeric value of field to one of predefined string constants.
// If string is found, return a static C string. Otherwise, return NULL.
// func:strconv.FieldId.value.ToCstr
const char*          value_ToCstr(const strconv::FieldId& parent) __attribute__((nothrow));
// Convert value to a string. First, attempt conversion to a known string.
// If no string matches, print value as a numeric value.
// func:strconv.FieldId.value.Print
void                 value_Print(const strconv::FieldId& parent, algo::cstring &lhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, do not modify field and return false.
// In case of success, return true
// func:strconv.FieldId.value.SetStrptrMaybe
bool                 value_SetStrptrMaybe(strconv::FieldId& parent, algo::strptr rhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, set numeric value to DFLT
// func:strconv.FieldId.value.SetStrptr
void                 value_SetStrptr(strconv::FieldId& parent, algo::strptr rhs, strconv_FieldIdEnum dflt) __attribute__((nothrow));
// Convert string to field. Return success value
// func:strconv.FieldId.value.ReadStrptrMaybe
bool                 value_ReadStrptrMaybe(strconv::FieldId& parent, algo::strptr rhs) __attribute__((nothrow));

// Read fields of strconv::FieldId from an ascii string.
// The format of the string is the format of the strconv::FieldId's only field
// func:strconv.FieldId..ReadStrptrMaybe
bool                 FieldId_ReadStrptrMaybe(strconv::FieldId &parent, algo::strptr in_str);
// Set all fields to initial values.
// func:strconv.FieldId..Init
void                 FieldId_Init(strconv::FieldId& parent);
// print string representation of ROW to string STR
// cfmt:strconv.FieldId.String  printfmt:Raw
// func:strconv.FieldId..Print
void                 FieldId_Print(strconv::FieldId& row, algo::cstring& str) __attribute__((nothrow));
} // gen:ns_print_struct
namespace strconv { // gen:ns_func
} // gen:ns_func
// func:strconv...main
int                  main(int argc, char **argv);
#if defined(WIN32)
// func:strconv...WinMain
int WINAPI           WinMain(HINSTANCE,HINSTANCE,LPSTR,int);
#endif
// gen:ns_operators
namespace algo {
inline algo::cstring &operator <<(algo::cstring &str, const strconv::trace &row);// cfmt:strconv.trace.String
inline algo::cstring &operator <<(algo::cstring &str, const strconv::FieldId &row);// cfmt:strconv.FieldId.String
}
