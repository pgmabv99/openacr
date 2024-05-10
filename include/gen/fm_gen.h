//
// include/gen/fm_gen.h
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
#include "include/gen/ams_gen.h"
#include "include/gen/algo_gen.h"
//#pragma endinclude
// gen:ns_enums

// --- fm_Flag_value_Enum

enum fm_Flag_value_Enum {            // fm.Flag.value
     fm_Flag_value_cleared   = 'C'   // Cleared alarm
    ,fm_Flag_value_raised    = 'R'   // Raised alarm
};

enum { fm_Flag_value_Enum_N = 2 };


// --- fm_Severity_value_Enum

enum fm_Severity_value_Enum {             // fm.Severity.value
     fm_Severity_value_critical   = '0'   // Service-affecting fault, immediate attention
    ,fm_Severity_value_major      = '1'   // Service-affecting fault, urgent attention
    ,fm_Severity_value_minor      = '2'   // Non-service affecting fault, need attention
};

enum { fm_Severity_value_Enum_N = 3 };


// --- fm_FieldIdEnum

enum fm_FieldIdEnum {                   // fm.FieldId.value
     fm_FieldId_base              = 0
    ,fm_FieldId_type              = 1
    ,fm_FieldId_length            = 2
    ,fm_FieldId_code              = 3
    ,fm_FieldId_objtype           = 4
    ,fm_FieldId_objinst           = 5
    ,fm_FieldId_flag              = 6
    ,fm_FieldId_severity          = 7
    ,fm_FieldId_n_occurred        = 8
    ,fm_FieldId_first_time        = 9
    ,fm_FieldId_last_time         = 10
    ,fm_FieldId_clear_time        = 11
    ,fm_FieldId_update_time       = 12
    ,fm_FieldId_objtype_summary   = 13
    ,fm_FieldId_summary           = 14
    ,fm_FieldId_description       = 15
    ,fm_FieldId_source            = 16
    ,fm_FieldId_ch                = 17
    ,fm_FieldId_value             = 18
};

enum { fm_FieldIdEnum_N = 19 };

namespace fm { // gen:ns_pkeytypedef
} // gen:ns_pkeytypedef
namespace fm { // gen:ns_tclass_field
} // gen:ns_tclass_field
// gen:ns_fwddecl2
namespace fm { struct Code; }
namespace fm { struct Objtype; }
namespace fm { struct Objinst; }
namespace fm { struct Flag; }
namespace fm { struct Severity; }
namespace fm { struct Summary; }
namespace fm { struct Description; }
namespace fm { struct Source; }
namespace fm { struct FieldId; }
namespace fm { // gen:ns_print_struct

// --- fm.Code
#pragma pack(push,1)
struct Code { // fm.Code
    enum { ch_max = 32 };
    u8 ch[32];
    inline operator algo::strptr() const;
    bool operator ==(const fm::Code &rhs) const;
    bool operator !=(const fm::Code &rhs) const;
    bool operator ==(const algo::strptr &rhs) const;
    // Copy from strptr (operator=)
    // func:fm.Code.ch.AssignStrptr
    void                 operator =(const algo::strptr &str) __attribute__((nothrow));
    // Copy from same type
    // Copy value from RHS.
    // func:fm.Code.ch.Set
    void                 operator =(const fm::Code& parent) __attribute__((nothrow));
    // func:fm.Code.ch.Ctor
    Code(const fm::Code &rhs) __attribute__((nothrow));
    // func:fm.Code.ch.CtorStrptr
    Code(const algo::strptr &rhs) __attribute__((nothrow));
    Code();
};
#pragma pack(pop)

// Access string as array of chars
// func:fm.Code.ch.Getary
algo::aryptr<char>   ch_Getary(const fm::Code& parent) __attribute__((nothrow));
// func:fm.Code.ch.HashStrptr
u32                  Code_Hash(u32 prev, const algo::strptr &str);
// func:fm.Code.ch.Init
void                 ch_Init(fm::Code &parent) __attribute__((nothrow));
// always return constant 32
// func:fm.Code.ch.Max
int                  ch_Max(fm::Code& parent) __attribute__((nothrow));
// func:fm.Code.ch.N
int                  ch_N(const fm::Code& parent) __attribute__((__warn_unused_result__, nothrow, pure));
// func:fm.Code.ch.Print
void                 ch_Print(fm::Code& parent, algo::cstring &out) __attribute__((nothrow));
// Convert string to field. Return success value
// func:fm.Code.ch.ReadStrptrMaybe
bool                 ch_ReadStrptrMaybe(fm::Code& parent, algo::strptr rhs) __attribute__((nothrow));
// Copy from strptr, clipping length
// Set string to the value provided by RHS.
// If RHS is too large, it is silently clipped.
// func:fm.Code.ch.SetStrptr
void                 ch_SetStrptr(fm::Code& parent, const algo::strptr& rhs) __attribute__((nothrow));

// func:fm.Code..Hash
u32                  Code_Hash(u32 prev, const fm::Code & rhs) __attribute__((nothrow));
// Read fields of fm::Code from an ascii string.
// The format of the string is the format of the fm::Code's only field
// func:fm.Code..ReadStrptrMaybe
bool                 Code_ReadStrptrMaybe(fm::Code &parent, algo::strptr in_str) __attribute__((nothrow));
// func:fm.Code..Cmp
i32                  Code_Cmp(fm::Code& lhs, fm::Code& rhs) __attribute__((nothrow));
// Set all fields to initial values.
// func:fm.Code..Init
void                 Code_Init(fm::Code& parent);
// func:fm.Code..Eq
bool                 Code_Eq(fm::Code& lhs, fm::Code& rhs) __attribute__((nothrow));
// func:fm.Code..EqStrptr
bool                 Code_EqStrptr(const fm::Code& lhs, const algo::strptr& rhs) __attribute__((nothrow));
// print string representation of ROW to string STR
// cfmt:fm.Code.String  printfmt:Raw
// func:fm.Code..Print
void                 Code_Print(fm::Code& row, algo::cstring& str) __attribute__((nothrow));

// --- fm.Objtype
#pragma pack(push,1)
struct Objtype { // fm.Objtype
    enum { ch_max = 15 };
    u8 ch[15];
    inline operator algo::strptr() const;
    bool operator ==(const fm::Objtype &rhs) const;
    bool operator !=(const fm::Objtype &rhs) const;
    bool operator ==(const algo::strptr &rhs) const;
    // Copy from strptr (operator=)
    // func:fm.Objtype.ch.AssignStrptr
    void                 operator =(const algo::strptr &str) __attribute__((nothrow));
    // Copy from same type
    // Copy value from RHS.
    // func:fm.Objtype.ch.Set
    void                 operator =(const fm::Objtype& parent) __attribute__((nothrow));
    // func:fm.Objtype.ch.Ctor
    Objtype(const fm::Objtype &rhs) __attribute__((nothrow));
    // func:fm.Objtype.ch.CtorStrptr
    Objtype(const algo::strptr &rhs) __attribute__((nothrow));
    Objtype();
};
#pragma pack(pop)

// Access string as array of chars
// func:fm.Objtype.ch.Getary
algo::aryptr<char>   ch_Getary(const fm::Objtype& parent) __attribute__((nothrow));
// func:fm.Objtype.ch.HashStrptr
u32                  Objtype_Hash(u32 prev, const algo::strptr &str);
// func:fm.Objtype.ch.Init
void                 ch_Init(fm::Objtype &parent) __attribute__((nothrow));
// always return constant 15
// func:fm.Objtype.ch.Max
int                  ch_Max(fm::Objtype& parent) __attribute__((nothrow));
// func:fm.Objtype.ch.N
int                  ch_N(const fm::Objtype& parent) __attribute__((__warn_unused_result__, nothrow, pure));
// func:fm.Objtype.ch.Print
void                 ch_Print(fm::Objtype& parent, algo::cstring &out) __attribute__((nothrow));
// Convert string to field. Return success value
// func:fm.Objtype.ch.ReadStrptrMaybe
bool                 ch_ReadStrptrMaybe(fm::Objtype& parent, algo::strptr rhs) __attribute__((nothrow));
// Copy from strptr, clipping length
// Set string to the value provided by RHS.
// If RHS is too large, it is silently clipped.
// func:fm.Objtype.ch.SetStrptr
void                 ch_SetStrptr(fm::Objtype& parent, const algo::strptr& rhs) __attribute__((nothrow));

// func:fm.Objtype..Hash
u32                  Objtype_Hash(u32 prev, const fm::Objtype & rhs) __attribute__((nothrow));
// Read fields of fm::Objtype from an ascii string.
// The format of the string is the format of the fm::Objtype's only field
// func:fm.Objtype..ReadStrptrMaybe
bool                 Objtype_ReadStrptrMaybe(fm::Objtype &parent, algo::strptr in_str) __attribute__((nothrow));
// func:fm.Objtype..Cmp
i32                  Objtype_Cmp(fm::Objtype& lhs, fm::Objtype& rhs) __attribute__((nothrow));
// Set all fields to initial values.
// func:fm.Objtype..Init
void                 Objtype_Init(fm::Objtype& parent);
// func:fm.Objtype..Eq
bool                 Objtype_Eq(fm::Objtype& lhs, fm::Objtype& rhs) __attribute__((nothrow));
// func:fm.Objtype..EqStrptr
bool                 Objtype_EqStrptr(const fm::Objtype& lhs, const algo::strptr& rhs) __attribute__((nothrow));
// print string representation of ROW to string STR
// cfmt:fm.Objtype.String  printfmt:Raw
// func:fm.Objtype..Print
void                 Objtype_Print(fm::Objtype& row, algo::cstring& str) __attribute__((nothrow));

// --- fm.Objinst
#pragma pack(push,1)
struct Objinst { // fm.Objinst
    enum { ch_max = 79 };
    u8 ch[79];
    inline operator algo::strptr() const;
    bool operator ==(const fm::Objinst &rhs) const;
    bool operator !=(const fm::Objinst &rhs) const;
    bool operator ==(const algo::strptr &rhs) const;
    // Copy from strptr (operator=)
    // func:fm.Objinst.ch.AssignStrptr
    void                 operator =(const algo::strptr &str) __attribute__((nothrow));
    // Copy from same type
    // Copy value from RHS.
    // func:fm.Objinst.ch.Set
    void                 operator =(const fm::Objinst& parent) __attribute__((nothrow));
    // func:fm.Objinst.ch.Ctor
    Objinst(const fm::Objinst &rhs) __attribute__((nothrow));
    // func:fm.Objinst.ch.CtorStrptr
    Objinst(const algo::strptr &rhs) __attribute__((nothrow));
    Objinst();
};
#pragma pack(pop)

// Access string as array of chars
// func:fm.Objinst.ch.Getary
algo::aryptr<char>   ch_Getary(const fm::Objinst& parent) __attribute__((nothrow));
// func:fm.Objinst.ch.HashStrptr
u32                  Objinst_Hash(u32 prev, const algo::strptr &str);
// func:fm.Objinst.ch.Init
void                 ch_Init(fm::Objinst &parent) __attribute__((nothrow));
// always return constant 79
// func:fm.Objinst.ch.Max
int                  ch_Max(fm::Objinst& parent) __attribute__((nothrow));
// func:fm.Objinst.ch.N
int                  ch_N(const fm::Objinst& parent) __attribute__((__warn_unused_result__, nothrow, pure));
// func:fm.Objinst.ch.Print
void                 ch_Print(fm::Objinst& parent, algo::cstring &out) __attribute__((nothrow));
// Convert string to field. Return success value
// func:fm.Objinst.ch.ReadStrptrMaybe
bool                 ch_ReadStrptrMaybe(fm::Objinst& parent, algo::strptr rhs) __attribute__((nothrow));
// Copy from strptr, clipping length
// Set string to the value provided by RHS.
// If RHS is too large, it is silently clipped.
// func:fm.Objinst.ch.SetStrptr
void                 ch_SetStrptr(fm::Objinst& parent, const algo::strptr& rhs) __attribute__((nothrow));

// func:fm.Objinst..Hash
u32                  Objinst_Hash(u32 prev, const fm::Objinst & rhs) __attribute__((nothrow));
// Read fields of fm::Objinst from an ascii string.
// The format of the string is the format of the fm::Objinst's only field
// func:fm.Objinst..ReadStrptrMaybe
bool                 Objinst_ReadStrptrMaybe(fm::Objinst &parent, algo::strptr in_str) __attribute__((nothrow));
// func:fm.Objinst..Cmp
i32                  Objinst_Cmp(fm::Objinst& lhs, fm::Objinst& rhs) __attribute__((nothrow));
// Set all fields to initial values.
// func:fm.Objinst..Init
void                 Objinst_Init(fm::Objinst& parent);
// func:fm.Objinst..Eq
bool                 Objinst_Eq(fm::Objinst& lhs, fm::Objinst& rhs) __attribute__((nothrow));
// func:fm.Objinst..EqStrptr
bool                 Objinst_EqStrptr(const fm::Objinst& lhs, const algo::strptr& rhs) __attribute__((nothrow));
// print string representation of ROW to string STR
// cfmt:fm.Objinst.String  printfmt:Raw
// func:fm.Objinst..Print
void                 Objinst_Print(fm::Objinst& row, algo::cstring& str) __attribute__((nothrow));

// --- fm.Flag
#pragma pack(push,1)
struct Flag { // fm.Flag
    char   value;   //   'C'
    Flag();
};
#pragma pack(pop)

// Get value of field as enum type
// func:fm.Flag.value.GetEnum
fm_Flag_value_Enum   value_GetEnum(const fm::Flag& parent) __attribute__((nothrow));
// Set value of field from enum type.
// func:fm.Flag.value.SetEnum
void                 value_SetEnum(fm::Flag& parent, fm_Flag_value_Enum rhs) __attribute__((nothrow));
// Convert numeric value of field to one of predefined string constants.
// If string is found, return a static C string. Otherwise, return NULL.
// func:fm.Flag.value.ToCstr
const char*          value_ToCstr(const fm::Flag& parent) __attribute__((nothrow));
// Convert value to a string. First, attempt conversion to a known string.
// If no string matches, print value as a numeric value.
// func:fm.Flag.value.Print
void                 value_Print(const fm::Flag& parent, algo::cstring &lhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, do not modify field and return false.
// In case of success, return true
// func:fm.Flag.value.SetStrptrMaybe
bool                 value_SetStrptrMaybe(fm::Flag& parent, algo::strptr rhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, set numeric value to DFLT
// func:fm.Flag.value.SetStrptr
void                 value_SetStrptr(fm::Flag& parent, algo::strptr rhs, fm_Flag_value_Enum dflt) __attribute__((nothrow));
// Convert string to field. Return success value
// func:fm.Flag.value.ReadStrptrMaybe
bool                 value_ReadStrptrMaybe(fm::Flag& parent, algo::strptr rhs) __attribute__((nothrow));

// Read fields of fm::Flag from an ascii string.
// The format of the string is the format of the fm::Flag's only field
// func:fm.Flag..ReadStrptrMaybe
bool                 Flag_ReadStrptrMaybe(fm::Flag &parent, algo::strptr in_str) __attribute__((nothrow));
// Set all fields to initial values.
// func:fm.Flag..Init
void                 Flag_Init(fm::Flag& parent);
// print string representation of ROW to string STR
// cfmt:fm.Flag.String  printfmt:Raw
// func:fm.Flag..Print
void                 Flag_Print(fm::Flag row, algo::cstring& str) __attribute__((nothrow));

// --- fm.Severity
#pragma pack(push,1)
struct Severity { // fm.Severity
    char   value;   //   '1'
    bool operator ==(const fm::Severity &rhs) const;
    bool operator !=(const fm::Severity &rhs) const;
    bool operator <(const fm::Severity &rhs) const;
    bool operator >(const fm::Severity &rhs) const;
    bool operator <=(const fm::Severity &rhs) const;
    bool operator >=(const fm::Severity &rhs) const;
    bool operator ==(fm_Severity_value_Enum rhs) const;
    Severity();
};
#pragma pack(pop)

// Get value of field as enum type
// func:fm.Severity.value.GetEnum
fm_Severity_value_Enum value_GetEnum(const fm::Severity& parent) __attribute__((nothrow));
// Set value of field from enum type.
// func:fm.Severity.value.SetEnum
void                 value_SetEnum(fm::Severity& parent, fm_Severity_value_Enum rhs) __attribute__((nothrow));
// Convert numeric value of field to one of predefined string constants.
// If string is found, return a static C string. Otherwise, return NULL.
// func:fm.Severity.value.ToCstr
const char*          value_ToCstr(const fm::Severity& parent) __attribute__((nothrow));
// Convert value to a string. First, attempt conversion to a known string.
// If no string matches, print value as a numeric value.
// func:fm.Severity.value.Print
void                 value_Print(const fm::Severity& parent, algo::cstring &lhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, do not modify field and return false.
// In case of success, return true
// func:fm.Severity.value.SetStrptrMaybe
bool                 value_SetStrptrMaybe(fm::Severity& parent, algo::strptr rhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, set numeric value to DFLT
// func:fm.Severity.value.SetStrptr
void                 value_SetStrptr(fm::Severity& parent, algo::strptr rhs, fm_Severity_value_Enum dflt) __attribute__((nothrow));
// Convert string to field. Return success value
// func:fm.Severity.value.ReadStrptrMaybe
bool                 value_ReadStrptrMaybe(fm::Severity& parent, algo::strptr rhs) __attribute__((nothrow));

// Read fields of fm::Severity from an ascii string.
// The format of the string is the format of the fm::Severity's only field
// func:fm.Severity..ReadStrptrMaybe
bool                 Severity_ReadStrptrMaybe(fm::Severity &parent, algo::strptr in_str) __attribute__((nothrow));
// func:fm.Severity..Lt
bool                 Severity_Lt(fm::Severity lhs, fm::Severity rhs) __attribute__((nothrow));
// func:fm.Severity..Cmp
i32                  Severity_Cmp(fm::Severity lhs, fm::Severity rhs) __attribute__((nothrow));
// Set all fields to initial values.
// func:fm.Severity..Init
void                 Severity_Init(fm::Severity& parent);
// Attempt to make LHS bigger. Return true if it was changed
// func:fm.Severity..UpdateMax
bool                 Severity_UpdateMax(fm::Severity &lhs, fm::Severity rhs) __attribute__((nothrow));
// Return the lesser of two values
// func:fm.Severity..Min
fm::Severity         Severity_Min(fm::Severity lhs, fm::Severity rhs) __attribute__((nothrow));
// Attempt to make LHS smaller. Return true if it was changed
// func:fm.Severity..UpdateMin
bool                 Severity_UpdateMin(fm::Severity &lhs, fm::Severity rhs) __attribute__((nothrow));
// Return the greater of two values
// func:fm.Severity..Max
fm::Severity         Severity_Max(fm::Severity lhs, fm::Severity rhs) __attribute__((nothrow));
// func:fm.Severity..Eq
bool                 Severity_Eq(fm::Severity lhs, fm::Severity rhs) __attribute__((nothrow));
// Set value. Return true if new value is different from old value.
// func:fm.Severity..Update
bool                 Severity_Update(fm::Severity &lhs, fm::Severity rhs) __attribute__((nothrow));
// print string representation of ROW to string STR
// cfmt:fm.Severity.String  printfmt:Raw
// func:fm.Severity..Print
void                 Severity_Print(fm::Severity row, algo::cstring& str) __attribute__((nothrow));
// define enum comparison operator to avoid ambiguity
// func:fm.Severity..EqEnum
bool                 Severity_EqEnum(fm::Severity lhs, fm_Severity_value_Enum rhs) __attribute__((nothrow));

// --- fm.Summary
#pragma pack(push,1)
struct Summary { // fm.Summary
    enum { ch_max = 64 };
    u8 ch[64];
    inline operator algo::strptr() const;
    bool operator ==(const fm::Summary &rhs) const;
    bool operator !=(const fm::Summary &rhs) const;
    bool operator ==(const algo::strptr &rhs) const;
    // Copy from strptr (operator=)
    // func:fm.Summary.ch.AssignStrptr
    void                 operator =(const algo::strptr &str) __attribute__((nothrow));
    // Copy from same type
    // Copy value from RHS.
    // func:fm.Summary.ch.Set
    void                 operator =(const fm::Summary& parent) __attribute__((nothrow));
    // func:fm.Summary.ch.Ctor
    Summary(const fm::Summary &rhs) __attribute__((nothrow));
    // func:fm.Summary.ch.CtorStrptr
    Summary(const algo::strptr &rhs) __attribute__((nothrow));
    Summary();
};
#pragma pack(pop)

// Access string as array of chars
// func:fm.Summary.ch.Getary
algo::aryptr<char>   ch_Getary(const fm::Summary& parent) __attribute__((nothrow));
// func:fm.Summary.ch.HashStrptr
u32                  Summary_Hash(u32 prev, const algo::strptr &str);
// func:fm.Summary.ch.Init
void                 ch_Init(fm::Summary &parent) __attribute__((nothrow));
// always return constant 64
// func:fm.Summary.ch.Max
int                  ch_Max(fm::Summary& parent) __attribute__((nothrow));
// func:fm.Summary.ch.N
int                  ch_N(const fm::Summary& parent) __attribute__((__warn_unused_result__, nothrow, pure));
// func:fm.Summary.ch.Print
void                 ch_Print(fm::Summary& parent, algo::cstring &out) __attribute__((nothrow));
// Convert string to field. Return success value
// func:fm.Summary.ch.ReadStrptrMaybe
bool                 ch_ReadStrptrMaybe(fm::Summary& parent, algo::strptr rhs) __attribute__((nothrow));
// Copy from strptr, clipping length
// Set string to the value provided by RHS.
// If RHS is too large, it is silently clipped.
// func:fm.Summary.ch.SetStrptr
void                 ch_SetStrptr(fm::Summary& parent, const algo::strptr& rhs) __attribute__((nothrow));

// func:fm.Summary..Hash
u32                  Summary_Hash(u32 prev, const fm::Summary & rhs) __attribute__((nothrow));
// Read fields of fm::Summary from an ascii string.
// The format of the string is the format of the fm::Summary's only field
// func:fm.Summary..ReadStrptrMaybe
bool                 Summary_ReadStrptrMaybe(fm::Summary &parent, algo::strptr in_str) __attribute__((nothrow));
// func:fm.Summary..Cmp
i32                  Summary_Cmp(fm::Summary& lhs, fm::Summary& rhs) __attribute__((nothrow));
// Set all fields to initial values.
// func:fm.Summary..Init
void                 Summary_Init(fm::Summary& parent);
// func:fm.Summary..Eq
bool                 Summary_Eq(fm::Summary& lhs, fm::Summary& rhs) __attribute__((nothrow));
// func:fm.Summary..EqStrptr
bool                 Summary_EqStrptr(const fm::Summary& lhs, const algo::strptr& rhs) __attribute__((nothrow));
// print string representation of ROW to string STR
// cfmt:fm.Summary.String  printfmt:Raw
// func:fm.Summary..Print
void                 Summary_Print(fm::Summary& row, algo::cstring& str) __attribute__((nothrow));

// --- fm.Description
#pragma pack(push,1)
struct Description { // fm.Description
    enum { ch_max = 128 };
    u8 ch[128];
    inline operator algo::strptr() const;
    bool operator ==(const fm::Description &rhs) const;
    bool operator !=(const fm::Description &rhs) const;
    bool operator ==(const algo::strptr &rhs) const;
    // Copy from strptr (operator=)
    // func:fm.Description.ch.AssignStrptr
    void                 operator =(const algo::strptr &str) __attribute__((nothrow));
    // Copy from same type
    // Copy value from RHS.
    // func:fm.Description.ch.Set
    void                 operator =(const fm::Description& parent) __attribute__((nothrow));
    // func:fm.Description.ch.Ctor
    Description(const fm::Description &rhs) __attribute__((nothrow));
    // func:fm.Description.ch.CtorStrptr
    Description(const algo::strptr &rhs) __attribute__((nothrow));
    Description();
};
#pragma pack(pop)

// Access string as array of chars
// func:fm.Description.ch.Getary
algo::aryptr<char>   ch_Getary(const fm::Description& parent) __attribute__((nothrow));
// func:fm.Description.ch.HashStrptr
u32                  Description_Hash(u32 prev, const algo::strptr &str);
// func:fm.Description.ch.Init
void                 ch_Init(fm::Description &parent) __attribute__((nothrow));
// always return constant 128
// func:fm.Description.ch.Max
int                  ch_Max(fm::Description& parent) __attribute__((nothrow));
// func:fm.Description.ch.N
int                  ch_N(const fm::Description& parent) __attribute__((__warn_unused_result__, nothrow, pure));
// func:fm.Description.ch.Print
void                 ch_Print(fm::Description& parent, algo::cstring &out) __attribute__((nothrow));
// Convert string to field. Return success value
// func:fm.Description.ch.ReadStrptrMaybe
bool                 ch_ReadStrptrMaybe(fm::Description& parent, algo::strptr rhs) __attribute__((nothrow));
// Copy from strptr, clipping length
// Set string to the value provided by RHS.
// If RHS is too large, it is silently clipped.
// func:fm.Description.ch.SetStrptr
void                 ch_SetStrptr(fm::Description& parent, const algo::strptr& rhs) __attribute__((nothrow));

// func:fm.Description..Hash
u32                  Description_Hash(u32 prev, const fm::Description & rhs) __attribute__((nothrow));
// Read fields of fm::Description from an ascii string.
// The format of the string is the format of the fm::Description's only field
// func:fm.Description..ReadStrptrMaybe
bool                 Description_ReadStrptrMaybe(fm::Description &parent, algo::strptr in_str) __attribute__((nothrow));
// func:fm.Description..Cmp
i32                  Description_Cmp(fm::Description& lhs, fm::Description& rhs) __attribute__((nothrow));
// Set all fields to initial values.
// func:fm.Description..Init
void                 Description_Init(fm::Description& parent);
// func:fm.Description..Eq
bool                 Description_Eq(fm::Description& lhs, fm::Description& rhs) __attribute__((nothrow));
// func:fm.Description..EqStrptr
bool                 Description_EqStrptr(const fm::Description& lhs, const algo::strptr& rhs) __attribute__((nothrow));
// print string representation of ROW to string STR
// cfmt:fm.Description.String  printfmt:Raw
// func:fm.Description..Print
void                 Description_Print(fm::Description& row, algo::cstring& str) __attribute__((nothrow));

// --- fm.Source
#pragma pack(push,1)
struct Source { // fm.Source
    enum { ch_max = 32 };
    u8 ch[32];
    inline operator algo::strptr() const;
    bool operator ==(const fm::Source &rhs) const;
    bool operator !=(const fm::Source &rhs) const;
    bool operator ==(const algo::strptr &rhs) const;
    // Copy from strptr (operator=)
    // func:fm.Source.ch.AssignStrptr
    void                 operator =(const algo::strptr &str) __attribute__((nothrow));
    // Copy from same type
    // Copy value from RHS.
    // func:fm.Source.ch.Set
    void                 operator =(const fm::Source& parent) __attribute__((nothrow));
    // func:fm.Source.ch.Ctor
    Source(const fm::Source &rhs) __attribute__((nothrow));
    // func:fm.Source.ch.CtorStrptr
    Source(const algo::strptr &rhs) __attribute__((nothrow));
    Source();
};
#pragma pack(pop)

// Access string as array of chars
// func:fm.Source.ch.Getary
algo::aryptr<char>   ch_Getary(const fm::Source& parent) __attribute__((nothrow));
// func:fm.Source.ch.HashStrptr
u32                  Source_Hash(u32 prev, const algo::strptr &str);
// func:fm.Source.ch.Init
void                 ch_Init(fm::Source &parent) __attribute__((nothrow));
// always return constant 32
// func:fm.Source.ch.Max
int                  ch_Max(fm::Source& parent) __attribute__((nothrow));
// func:fm.Source.ch.N
int                  ch_N(const fm::Source& parent) __attribute__((__warn_unused_result__, nothrow, pure));
// func:fm.Source.ch.Print
void                 ch_Print(fm::Source& parent, algo::cstring &out) __attribute__((nothrow));
// Convert string to field. Return success value
// func:fm.Source.ch.ReadStrptrMaybe
bool                 ch_ReadStrptrMaybe(fm::Source& parent, algo::strptr rhs) __attribute__((nothrow));
// Copy from strptr, clipping length
// Set string to the value provided by RHS.
// If RHS is too large, it is silently clipped.
// func:fm.Source.ch.SetStrptr
void                 ch_SetStrptr(fm::Source& parent, const algo::strptr& rhs) __attribute__((nothrow));

// func:fm.Source..Hash
u32                  Source_Hash(u32 prev, const fm::Source & rhs) __attribute__((nothrow));
// Read fields of fm::Source from an ascii string.
// The format of the string is the format of the fm::Source's only field
// func:fm.Source..ReadStrptrMaybe
bool                 Source_ReadStrptrMaybe(fm::Source &parent, algo::strptr in_str) __attribute__((nothrow));
// func:fm.Source..Cmp
i32                  Source_Cmp(fm::Source& lhs, fm::Source& rhs) __attribute__((nothrow));
// Set all fields to initial values.
// func:fm.Source..Init
void                 Source_Init(fm::Source& parent);
// func:fm.Source..Eq
bool                 Source_Eq(fm::Source& lhs, fm::Source& rhs) __attribute__((nothrow));
// func:fm.Source..EqStrptr
bool                 Source_EqStrptr(const fm::Source& lhs, const algo::strptr& rhs) __attribute__((nothrow));
// print string representation of ROW to string STR
// cfmt:fm.Source.String  printfmt:Raw
// func:fm.Source..Print
void                 Source_Print(fm::Source& row, algo::cstring& str) __attribute__((nothrow));

// --- fm.AlarmMsg
#pragma pack(push,1)
struct AlarmMsg { // fm.AlarmMsg
    u32               type;              //   17
    u32               length;            //   ssizeof(parent) + (0)
    fm::Code          code;              // Alarm code
    fm::Objtype       objtype;           // Alarmed object type
    fm::Objinst       objinst;           // Alarmed object instance
    fm::Flag          flag;              // Flag: raised or cleared
    fm::Severity      severity;          // Perceived severity
    i32               n_occurred;        //   0  How many times the alarm occurred since first_time
    algo::UnTime      first_time;        // Time of first occurrence
    algo::UnTime      last_time;         // Time of last occurrence
    algo::UnTime      clear_time;        // Time when the alarm has beed cleared (only for cleared alarms
    algo::UnTime      update_time;       // Time of last update
    fm::Summary       objtype_summary;   // Object type explained
    fm::Summary       summary;           // Alarm summary from inventory
    fm::Description   description;       // Alarm message from object
    fm::Source        source;            // Subsystem where detected
    AlarmMsg();
};
#pragma pack(pop)

// Copy fields out of row
// func:fm.AlarmMsg.base.CopyOut
void                 parent_CopyOut(fm::AlarmMsg &row, ams::MsgHeader &out) __attribute__((nothrow));
// Check if ams::MsgHeader is an instance of AlarmMsg by checking the type field
// If it is, return the pointer of target type.
// Additionally, check if the length field permits valid instance of AlarmMsg.
// If not successful, quietly return NULL.
// func:fm.AlarmMsg.base.Castdown
fm::AlarmMsg*        AlarmMsg_Castdown(ams::MsgHeader &hdr);
// func:fm.AlarmMsg.base.Castbase
ams::MsgHeader&      Castbase(fm::AlarmMsg& parent);

// func:fm.AlarmMsg..ReadFieldMaybe
bool                 AlarmMsg_ReadFieldMaybe(fm::AlarmMsg& parent, algo::strptr field, algo::strptr strval) __attribute__((nothrow));
// Read fields of fm::AlarmMsg from an ascii string.
// The format of the string is an ssim Tuple
// func:fm.AlarmMsg..ReadStrptrMaybe
bool                 AlarmMsg_ReadStrptrMaybe(fm::AlarmMsg &parent, algo::strptr in_str) __attribute__((nothrow));
// Message length (uses length field)
// func:fm.AlarmMsg..GetMsgLength
i32                  GetMsgLength(const fm::AlarmMsg& parent) __attribute__((nothrow));
// Memptr encompassing the message (uses length field)
// func:fm.AlarmMsg..GetMsgMemptr
algo::memptr         GetMsgMemptr(const fm::AlarmMsg& row) __attribute__((nothrow));
// Set all fields to initial values.
// func:fm.AlarmMsg..Init
void                 AlarmMsg_Init(fm::AlarmMsg& parent);
// print string representation of ROW to string STR
// cfmt:fm.AlarmMsg.String  printfmt:Tuple
// func:fm.AlarmMsg..Print
void                 AlarmMsg_Print(fm::AlarmMsg& row, algo::cstring& str) __attribute__((nothrow));

// --- fm.FieldId
#pragma pack(push,1)
struct FieldId { // fm.FieldId: Field read helper
    i32   value;   //   -1
    inline operator fm_FieldIdEnum() const;
    explicit FieldId(i32                            in_value);
    FieldId(fm_FieldIdEnum arg);
    FieldId();
};
#pragma pack(pop)

// Get value of field as enum type
// func:fm.FieldId.value.GetEnum
fm_FieldIdEnum       value_GetEnum(const fm::FieldId& parent) __attribute__((nothrow));
// Set value of field from enum type.
// func:fm.FieldId.value.SetEnum
void                 value_SetEnum(fm::FieldId& parent, fm_FieldIdEnum rhs) __attribute__((nothrow));
// Convert numeric value of field to one of predefined string constants.
// If string is found, return a static C string. Otherwise, return NULL.
// func:fm.FieldId.value.ToCstr
const char*          value_ToCstr(const fm::FieldId& parent) __attribute__((nothrow));
// Convert value to a string. First, attempt conversion to a known string.
// If no string matches, print value as a numeric value.
// func:fm.FieldId.value.Print
void                 value_Print(const fm::FieldId& parent, algo::cstring &lhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, do not modify field and return false.
// In case of success, return true
// func:fm.FieldId.value.SetStrptrMaybe
bool                 value_SetStrptrMaybe(fm::FieldId& parent, algo::strptr rhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, set numeric value to DFLT
// func:fm.FieldId.value.SetStrptr
void                 value_SetStrptr(fm::FieldId& parent, algo::strptr rhs, fm_FieldIdEnum dflt) __attribute__((nothrow));
// Convert string to field. Return success value
// func:fm.FieldId.value.ReadStrptrMaybe
bool                 value_ReadStrptrMaybe(fm::FieldId& parent, algo::strptr rhs) __attribute__((nothrow));

// Read fields of fm::FieldId from an ascii string.
// The format of the string is the format of the fm::FieldId's only field
// func:fm.FieldId..ReadStrptrMaybe
bool                 FieldId_ReadStrptrMaybe(fm::FieldId &parent, algo::strptr in_str) __attribute__((nothrow));
// Set all fields to initial values.
// func:fm.FieldId..Init
void                 FieldId_Init(fm::FieldId& parent);
// print string representation of ROW to string STR
// cfmt:fm.FieldId.String  printfmt:Raw
// func:fm.FieldId..Print
void                 FieldId_Print(fm::FieldId& row, algo::cstring& str) __attribute__((nothrow));
} // gen:ns_print_struct
namespace fm { // gen:ns_func
// func:fm...StaticCheck
void                 StaticCheck();
} // gen:ns_func
// gen:ns_operators
namespace algo {
inline algo::cstring &operator <<(algo::cstring &str, const fm::Flag &row);// cfmt:fm.Flag.String
inline algo::cstring &operator <<(algo::cstring &str, const fm::Severity &row);// cfmt:fm.Severity.String
inline algo::cstring &operator <<(algo::cstring &str, const fm::AlarmMsg &row);// cfmt:fm.AlarmMsg.String
inline algo::cstring &operator <<(algo::cstring &str, const fm::FieldId &row);// cfmt:fm.FieldId.String
}
