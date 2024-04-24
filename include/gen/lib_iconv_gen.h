//
// include/gen/lib_iconv_gen.h
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
#include <iconv.h>
//#pragma endinclude
// gen:ns_enums

// --- lib_iconv_FieldIdEnum

enum lib_iconv_FieldIdEnum {        // lib_iconv.FieldId.value
     lib_iconv_FieldId_value   = 0
};

enum { lib_iconv_FieldIdEnum_N = 1 };

namespace lib_iconv { // gen:ns_pkeytypedef
} // gen:ns_pkeytypedef
namespace lib_iconv { // gen:ns_field
} // gen:ns_field
// gen:ns_fwddecl2
namespace lib_iconv { struct trace; }
namespace lib_iconv { struct FDb; }
namespace lib_iconv { struct FieldId; }
namespace lib_iconv { struct Icd; }
namespace lib_iconv { extern struct lib_iconv::FDb _db; }
namespace lib_iconv { // gen:ns_print_struct

// --- lib_iconv.trace
#pragma pack(push,1)
struct trace { // lib_iconv.trace
    trace();
};
#pragma pack(pop)

// print string representation of ROW to string STR
// cfmt:lib_iconv.trace.String  printfmt:Tuple
// func:lib_iconv.trace..Print
void                 trace_Print(lib_iconv::trace& row, algo::cstring& str) __attribute__((nothrow));

// --- lib_iconv.FDb
// create: lib_iconv.FDb._db (Global)
struct FDb { // lib_iconv.FDb: In-memory database for lib_iconv
    lib_iconv::trace   trace;   //
};

// func:lib_iconv.FDb._db.StaticCheck
void                 StaticCheck();
// Parse strptr into known type and add to database.
// Return value is true unless an error occurs. If return value is false, algo_lib::_db.errtext has error text
// func:lib_iconv.FDb._db.InsertStrptrMaybe
bool                 InsertStrptrMaybe(algo::strptr str);
// Load all finputs from given directory.
// func:lib_iconv.FDb._db.LoadTuplesMaybe
bool                 LoadTuplesMaybe(algo::strptr root, bool recursive) __attribute__((nothrow));
// Load all finputs from given file.
// Read tuples from file FNAME into this namespace's in-memory database.
// If RECURSIVE is TRUE, then also load these tuples into any parent namespaces
// It a file referred to by FNAME is missing, no error is reported (it's considered an empty set).
// Function returns TRUE if all records were parsed and inserted without error.
// If the function returns FALSE, use algo_lib::DetachBadTags() for error description
// func:lib_iconv.FDb._db.LoadTuplesFile
bool                 LoadTuplesFile(algo::strptr fname, bool recursive) __attribute__((nothrow));
// Load all finputs from given file descriptor.
// func:lib_iconv.FDb._db.LoadTuplesFd
bool                 LoadTuplesFd(algo::Fildes fd, algo::strptr fname, bool recursive) __attribute__((nothrow));
// Load specified ssimfile.
// func:lib_iconv.FDb._db.LoadSsimfileMaybe
bool                 LoadSsimfileMaybe(algo::strptr fname, bool recursive) __attribute__((nothrow));
// Calls Step function of dependencies
// func:lib_iconv.FDb._db.Steps
void                 Steps();
// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Caller must Delete or Unref such row.
// func:lib_iconv.FDb._db.XrefMaybe
bool                 _db_XrefMaybe();

// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Caller must Delete or Unref such row.
// func:lib_iconv.FDb.icd.XrefMaybe
bool                 icd_XrefMaybe(lib_iconv::Icd &row);

// Set all fields to initial values.
// func:lib_iconv.FDb..Init
void                 FDb_Init();
// func:lib_iconv.FDb..Uninit
void                 FDb_Uninit() __attribute__((nothrow));

// --- lib_iconv.FieldId
#pragma pack(push,1)
struct FieldId { // lib_iconv.FieldId: Field read helper
    i32   value;   //   -1
    inline operator lib_iconv_FieldIdEnum() const;
    explicit FieldId(i32                            in_value);
    FieldId(lib_iconv_FieldIdEnum arg);
    FieldId();
};
#pragma pack(pop)

// Get value of field as enum type
// func:lib_iconv.FieldId.value.GetEnum
lib_iconv_FieldIdEnum value_GetEnum(const lib_iconv::FieldId& parent) __attribute__((nothrow));
// Set value of field from enum type.
// func:lib_iconv.FieldId.value.SetEnum
void                 value_SetEnum(lib_iconv::FieldId& parent, lib_iconv_FieldIdEnum rhs) __attribute__((nothrow));
// Convert numeric value of field to one of predefined string constants.
// If string is found, return a static C string. Otherwise, return NULL.
// func:lib_iconv.FieldId.value.ToCstr
const char*          value_ToCstr(const lib_iconv::FieldId& parent) __attribute__((nothrow));
// Convert value to a string. First, attempt conversion to a known string.
// If no string matches, print value as a numeric value.
// func:lib_iconv.FieldId.value.Print
void                 value_Print(const lib_iconv::FieldId& parent, algo::cstring &lhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, do not modify field and return false.
// In case of success, return true
// func:lib_iconv.FieldId.value.SetStrptrMaybe
bool                 value_SetStrptrMaybe(lib_iconv::FieldId& parent, algo::strptr rhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, set numeric value to DFLT
// func:lib_iconv.FieldId.value.SetStrptr
void                 value_SetStrptr(lib_iconv::FieldId& parent, algo::strptr rhs, lib_iconv_FieldIdEnum dflt) __attribute__((nothrow));
// Convert string to field. Return success value
// func:lib_iconv.FieldId.value.ReadStrptrMaybe
bool                 value_ReadStrptrMaybe(lib_iconv::FieldId& parent, algo::strptr rhs) __attribute__((nothrow));

// Read fields of lib_iconv::FieldId from an ascii string.
// The format of the string is the format of the lib_iconv::FieldId's only field
// func:lib_iconv.FieldId..ReadStrptrMaybe
bool                 FieldId_ReadStrptrMaybe(lib_iconv::FieldId &parent, algo::strptr in_str) __attribute__((nothrow));
// Set all fields to initial values.
// func:lib_iconv.FieldId..Init
void                 FieldId_Init(lib_iconv::FieldId& parent);
// print string representation of ROW to string STR
// cfmt:lib_iconv.FieldId.String  printfmt:Raw
// func:lib_iconv.FieldId..Print
void                 FieldId_Print(lib_iconv::FieldId& row, algo::cstring& str) __attribute__((nothrow));

// --- lib_iconv.Icd
// create: lib_iconv.FDb.icd (Cppstack)
struct Icd { // lib_iconv.Icd
    iconv_t   icd;   //   ((iconv_t)-1)  iconv descriptor
    Icd();
    ~Icd();
private:
    // user-defined fcleanup on lib_iconv.Icd.icd prevents copy
    Icd(const Icd&){ /*disallow copy constructor */}
    void operator =(const Icd&){ /*disallow direct assignment */}
};

// Declaration for user-defined cleanup function
// User-defined cleanup function invoked for field icd of lib_iconv::Icd
// func:lib_iconv.Icd.icd.Cleanup
// this function is 'extrn' and implemented by user
void                 icd_Cleanup(lib_iconv::Icd& icd) __attribute__((nothrow));

// Set all fields to initial values.
// func:lib_iconv.Icd..Init
void                 Icd_Init(lib_iconv::Icd& icd);
// func:lib_iconv.Icd..Uninit
void                 Icd_Uninit(lib_iconv::Icd& icd) __attribute__((nothrow));
// print string representation of ROW to string STR
// cfmt:lib_iconv.Icd.String  printfmt:Raw
// func:lib_iconv.Icd..Print
void                 Icd_Print(lib_iconv::Icd& row, algo::cstring& str) __attribute__((nothrow));
} // gen:ns_print_struct
namespace lib_iconv { // gen:ns_func
} // gen:ns_func
// gen:ns_operators
namespace algo {
inline algo::cstring &operator <<(algo::cstring &str, const lib_iconv::trace &row);// cfmt:lib_iconv.trace.String
inline algo::cstring &operator <<(algo::cstring &str, const lib_iconv::FieldId &row);// cfmt:lib_iconv.FieldId.String
inline algo::cstring &operator <<(algo::cstring &str, const lib_iconv::Icd &row);// cfmt:lib_iconv.Icd.String
}
