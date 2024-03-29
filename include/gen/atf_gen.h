//
// include/gen/atf_gen.h
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
#include "include/gen/algo_gen.h"
//#pragma endinclude
// gen:ns_enums

// --- atf_FieldIdEnum

enum atf_FieldIdEnum {             // atf.FieldId.value
     atf_FieldId_value        = 0
    ,atf_FieldId_testrun      = 1
    ,atf_FieldId_testresult   = 2
    ,atf_FieldId_n_step       = 3
    ,atf_FieldId_n_cmp        = 4
    ,atf_FieldId_comment      = 5
};

enum { atf_FieldIdEnum_N = 6 };


// --- atf_TestresultEnum

enum atf_TestresultEnum {                      // atf.Testresult.value
     atf_Testresult_UNTESTED             = 0   // Test has not been run
    ,atf_Testresult_UNTESTED_PREPERROR   = 4   // Test has not been run, error in definition
    ,atf_Testresult_UNRESOLVED           = 1   // Test has been run, verdict unresolved
    ,atf_Testresult_PASSED               = 2   // Test has been run, verdict resolved - passed
    ,atf_Testresult_FAILED               = 3   // Test has been run, verdict resolved - failed
    ,atf_Testresult_TIMEOUT              = 5   // Test has been run, verdict resolved - timeout
};

enum { atf_TestresultEnum_N = 6 };

namespace atf { // gen:ns_pkeytypedef
} // gen:ns_pkeytypedef
namespace atf { // gen:ns_field
} // gen:ns_field
// gen:ns_fwddecl2
namespace atf { struct FieldId; }
namespace atf { struct Protocol; }
namespace atf { struct Testresult; }
namespace atf { struct Testrun; }
namespace atf { // gen:ns_print_struct

// --- atf.FieldId
#pragma pack(push,1)
struct FieldId { // atf.FieldId: Field read helper
    i32   value;   //   -1
    inline operator atf_FieldIdEnum() const;
    explicit FieldId(i32                            in_value);
    FieldId(atf_FieldIdEnum arg);
    FieldId();
};
#pragma pack(pop)

// Get value of field as enum type
// func:atf.FieldId.value.GetEnum
atf_FieldIdEnum      value_GetEnum(const atf::FieldId& parent) __attribute__((nothrow));
// Set value of field from enum type.
// func:atf.FieldId.value.SetEnum
void                 value_SetEnum(atf::FieldId& parent, atf_FieldIdEnum rhs) __attribute__((nothrow));
// Convert numeric value of field to one of predefined string constants.
// If string is found, return a static C string. Otherwise, return NULL.
// func:atf.FieldId.value.ToCstr
const char*          value_ToCstr(const atf::FieldId& parent) __attribute__((nothrow));
// Convert value to a string. First, attempt conversion to a known string.
// If no string matches, print value as a numeric value.
// func:atf.FieldId.value.Print
void                 value_Print(const atf::FieldId& parent, algo::cstring &lhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, do not modify field and return false.
// In case of success, return true
// func:atf.FieldId.value.SetStrptrMaybe
bool                 value_SetStrptrMaybe(atf::FieldId& parent, algo::strptr rhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, set numeric value to DFLT
// func:atf.FieldId.value.SetStrptr
void                 value_SetStrptr(atf::FieldId& parent, algo::strptr rhs, atf_FieldIdEnum dflt) __attribute__((nothrow));
// Convert string to field. Return success value
// func:atf.FieldId.value.ReadStrptrMaybe
bool                 value_ReadStrptrMaybe(atf::FieldId& parent, algo::strptr rhs) __attribute__((nothrow));

// Read fields of atf::FieldId from an ascii string.
// The format of the string is the format of the atf::FieldId's only field
// func:atf.FieldId..ReadStrptrMaybe
bool                 FieldId_ReadStrptrMaybe(atf::FieldId &parent, algo::strptr in_str);
// Set all fields to initial values.
// func:atf.FieldId..Init
void                 FieldId_Init(atf::FieldId& parent);
// print string representation of ROW to string STR
// cfmt:atf.FieldId.String  printfmt:Raw
// func:atf.FieldId..Print
void                 FieldId_Print(atf::FieldId& row, algo::cstring& str) __attribute__((nothrow));

// --- atf.Protocol
// access: atf.Protocol.proto (Protocol)
#pragma pack(push,1)
struct Protocol { // atf.Protocol: amc-generated struct for internal purposes
    Protocol();
};
#pragma pack(pop)

// func:atf.Protocol.proto.StaticCheck
void                 StaticCheck();


// --- atf.Testresult
struct Testresult { // atf.Testresult
    u32   value;   //   0
    inline operator atf_TestresultEnum() const;
    explicit Testresult(u32                            in_value);
    Testresult(atf_TestresultEnum arg);
    Testresult();
};

// Get value of field as enum type
// func:atf.Testresult.value.GetEnum
atf_TestresultEnum   value_GetEnum(const atf::Testresult& parent) __attribute__((nothrow));
// Set value of field from enum type.
// func:atf.Testresult.value.SetEnum
void                 value_SetEnum(atf::Testresult& parent, atf_TestresultEnum rhs) __attribute__((nothrow));
// Convert numeric value of field to one of predefined string constants.
// If string is found, return a static C string. Otherwise, return NULL.
// func:atf.Testresult.value.ToCstr
const char*          value_ToCstr(const atf::Testresult& parent) __attribute__((nothrow));
// Convert value to a string. First, attempt conversion to a known string.
// If no string matches, print value as a numeric value.
// func:atf.Testresult.value.Print
void                 value_Print(const atf::Testresult& parent, algo::cstring &lhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, do not modify field and return false.
// In case of success, return true
// func:atf.Testresult.value.SetStrptrMaybe
bool                 value_SetStrptrMaybe(atf::Testresult& parent, algo::strptr rhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, set numeric value to DFLT
// func:atf.Testresult.value.SetStrptr
void                 value_SetStrptr(atf::Testresult& parent, algo::strptr rhs, atf_TestresultEnum dflt) __attribute__((nothrow));
// Convert string to field. Return success value
// func:atf.Testresult.value.ReadStrptrMaybe
bool                 value_ReadStrptrMaybe(atf::Testresult& parent, algo::strptr rhs) __attribute__((nothrow));

// Read fields of atf::Testresult from an ascii string.
// The format of the string is the format of the atf::Testresult's only field
// func:atf.Testresult..ReadStrptrMaybe
bool                 Testresult_ReadStrptrMaybe(atf::Testresult &parent, algo::strptr in_str);
// Set all fields to initial values.
// func:atf.Testresult..Init
void                 Testresult_Init(atf::Testresult& parent);
// print string representation of ROW to string STR
// cfmt:atf.Testresult.String  printfmt:Raw
// func:atf.Testresult..Print
void                 Testresult_Print(atf::Testresult& row, algo::cstring& str) __attribute__((nothrow));

// --- atf.Testrun
struct Testrun { // atf.Testrun
    algo::Smallstr50   testrun;      // Test name
    atf::Testresult    testresult;   //   0  Result
    u64                n_step;       //   0  Number of sub-steps
    u64                n_cmp;        //   0  Number of comparisons made during test
    algo::cstring      comment;      // Testcase comment
    explicit Testrun(const algo::strptr&            in_testrun
        ,const atf::Testresult&         in_testresult
        ,u64                            in_n_step
        ,u64                            in_n_cmp
        ,const algo::strptr&            in_comment);
    Testrun();
};

// func:atf.Testrun..ReadFieldMaybe
bool                 Testrun_ReadFieldMaybe(atf::Testrun& parent, algo::strptr field, algo::strptr strval) __attribute__((nothrow));
// Read fields of atf::Testrun from an ascii string.
// The format of the string is an ssim Tuple
// func:atf.Testrun..ReadStrptrMaybe
bool                 Testrun_ReadStrptrMaybe(atf::Testrun &parent, algo::strptr in_str);
// Set all fields to initial values.
// func:atf.Testrun..Init
void                 Testrun_Init(atf::Testrun& parent);
// print string representation of ROW to string STR
// cfmt:atf.Testrun.String  printfmt:Tuple
// func:atf.Testrun..Print
void                 Testrun_Print(atf::Testrun& row, algo::cstring& str) __attribute__((nothrow));
} // gen:ns_print_struct
namespace atf { // gen:ns_func
} // gen:ns_func
// gen:ns_operators
namespace algo {
inline algo::cstring &operator <<(algo::cstring &str, const atf::FieldId &row);// cfmt:atf.FieldId.String
inline algo::cstring &operator <<(algo::cstring &str, const atf::Testresult &row);// cfmt:atf.Testresult.String
inline algo::cstring &operator <<(algo::cstring &str, const atf::Testrun &row);// cfmt:atf.Testrun.String
}
