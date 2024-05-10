//
// include/gen/lib_git_gen.h
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
//#pragma endinclude
// gen:ns_enums

// --- lib_git_FieldIdEnum

enum lib_git_FieldIdEnum {        // lib_git.FieldId.value
     lib_git_FieldId_value   = 0
};

enum { lib_git_FieldIdEnum_N = 1 };

namespace lib_git { // gen:ns_pkeytypedef
} // gen:ns_pkeytypedef
namespace lib_git { // gen:ns_tclass_field
} // gen:ns_tclass_field
// gen:ns_fwddecl2
namespace lib_git { struct trace; }
namespace lib_git { struct FDb; }
namespace lib_git { struct FieldId; }
namespace lib_git { extern struct lib_git::FDb _db; }
namespace lib_git { // gen:ns_print_struct

// --- lib_git.trace
#pragma pack(push,1)
struct trace { // lib_git.trace
    trace();
};
#pragma pack(pop)

// print string representation of ROW to string STR
// cfmt:lib_git.trace.String  printfmt:Tuple
// func:lib_git.trace..Print
void                 trace_Print(lib_git::trace& row, algo::cstring& str) __attribute__((nothrow));

// --- lib_git.FDb
// create: lib_git.FDb._db (Global)
struct FDb { // lib_git.FDb: In-memory database for lib_git
    lib_git::trace   trace;   //
};

// Parse strptr into known type and add to database.
// Return value is true unless an error occurs. If return value is false, algo_lib::_db.errtext has error text
// func:lib_git.FDb._db.InsertStrptrMaybe
bool                 InsertStrptrMaybe(algo::strptr str);
// Load all finputs from given directory.
// func:lib_git.FDb._db.LoadTuplesMaybe
bool                 LoadTuplesMaybe(algo::strptr root, bool recursive) __attribute__((nothrow));
// Load all finputs from given file.
// Read tuples from file FNAME into this namespace's in-memory database.
// If RECURSIVE is TRUE, then also load these tuples into any parent namespaces
// It a file referred to by FNAME is missing, no error is reported (it's considered an empty set).
// Function returns TRUE if all records were parsed and inserted without error.
// If the function returns FALSE, use algo_lib::DetachBadTags() for error description
// func:lib_git.FDb._db.LoadTuplesFile
bool                 LoadTuplesFile(algo::strptr fname, bool recursive) __attribute__((nothrow));
// Load all finputs from given file descriptor.
// func:lib_git.FDb._db.LoadTuplesFd
bool                 LoadTuplesFd(algo::Fildes fd, algo::strptr fname, bool recursive) __attribute__((nothrow));
// Load specified ssimfile.
// func:lib_git.FDb._db.LoadSsimfileMaybe
bool                 LoadSsimfileMaybe(algo::strptr fname, bool recursive) __attribute__((nothrow));
// Calls Step function of dependencies
// func:lib_git.FDb._db.Steps
void                 Steps();
// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Caller must Delete or Unref such row.
// func:lib_git.FDb._db.XrefMaybe
bool                 _db_XrefMaybe();

// Set all fields to initial values.
// func:lib_git.FDb..Init
void                 FDb_Init();
// func:lib_git.FDb..Uninit
void                 FDb_Uninit() __attribute__((nothrow));

// --- lib_git.FieldId
#pragma pack(push,1)
struct FieldId { // lib_git.FieldId: Field read helper
    i32   value;   //   -1
    inline operator lib_git_FieldIdEnum() const;
    explicit FieldId(i32                            in_value);
    FieldId(lib_git_FieldIdEnum arg);
    FieldId();
};
#pragma pack(pop)

// Get value of field as enum type
// func:lib_git.FieldId.value.GetEnum
lib_git_FieldIdEnum  value_GetEnum(const lib_git::FieldId& parent) __attribute__((nothrow));
// Set value of field from enum type.
// func:lib_git.FieldId.value.SetEnum
void                 value_SetEnum(lib_git::FieldId& parent, lib_git_FieldIdEnum rhs) __attribute__((nothrow));
// Convert numeric value of field to one of predefined string constants.
// If string is found, return a static C string. Otherwise, return NULL.
// func:lib_git.FieldId.value.ToCstr
const char*          value_ToCstr(const lib_git::FieldId& parent) __attribute__((nothrow));
// Convert value to a string. First, attempt conversion to a known string.
// If no string matches, print value as a numeric value.
// func:lib_git.FieldId.value.Print
void                 value_Print(const lib_git::FieldId& parent, algo::cstring &lhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, do not modify field and return false.
// In case of success, return true
// func:lib_git.FieldId.value.SetStrptrMaybe
bool                 value_SetStrptrMaybe(lib_git::FieldId& parent, algo::strptr rhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, set numeric value to DFLT
// func:lib_git.FieldId.value.SetStrptr
void                 value_SetStrptr(lib_git::FieldId& parent, algo::strptr rhs, lib_git_FieldIdEnum dflt) __attribute__((nothrow));
// Convert string to field. Return success value
// func:lib_git.FieldId.value.ReadStrptrMaybe
bool                 value_ReadStrptrMaybe(lib_git::FieldId& parent, algo::strptr rhs) __attribute__((nothrow));

// Read fields of lib_git::FieldId from an ascii string.
// The format of the string is the format of the lib_git::FieldId's only field
// func:lib_git.FieldId..ReadStrptrMaybe
bool                 FieldId_ReadStrptrMaybe(lib_git::FieldId &parent, algo::strptr in_str) __attribute__((nothrow));
// Set all fields to initial values.
// func:lib_git.FieldId..Init
void                 FieldId_Init(lib_git::FieldId& parent);
// print string representation of ROW to string STR
// cfmt:lib_git.FieldId.String  printfmt:Raw
// func:lib_git.FieldId..Print
void                 FieldId_Print(lib_git::FieldId& row, algo::cstring& str) __attribute__((nothrow));
} // gen:ns_print_struct
namespace lib_git { // gen:ns_func
// func:lib_git...StaticCheck
void                 StaticCheck();
} // gen:ns_func
// gen:ns_operators
namespace algo {
inline algo::cstring &operator <<(algo::cstring &str, const lib_git::trace &row);// cfmt:lib_git.trace.String
inline algo::cstring &operator <<(algo::cstring &str, const lib_git::FieldId &row);// cfmt:lib_git.FieldId.String
}
