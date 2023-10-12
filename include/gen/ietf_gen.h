//
// include/gen/ietf_gen.h
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

// --- ietf_FieldIdEnum

enum ietf_FieldIdEnum {        // ietf.FieldId.value
     ietf_FieldId_ip      = 0
    ,ietf_FieldId_port    = 1
    ,ietf_FieldId_ipv4    = 2
    ,ietf_FieldId_addr    = 3
    ,ietf_FieldId_value   = 4
};

enum { ietf_FieldIdEnum_N = 5 };

namespace ietf { // gen:ns_pkeytypedef
} // gen:ns_pkeytypedef
namespace ietf { // gen:ns_field
} // gen:ns_field
// gen:ns_fwddecl2
namespace ietf { struct FieldId; }
namespace ietf { struct Ipv4; }
namespace ietf { struct Ipport; }
namespace ietf { struct Ipv4Addr; }
namespace ietf { struct Protocol; }
namespace ietf { // gen:ns_print_struct

// --- ietf.FieldId
#pragma pack(push,1)
struct FieldId { // ietf.FieldId: Field read helper
    i32   value;   //   -1
    inline operator ietf_FieldIdEnum() const;
    explicit FieldId(i32                            in_value);
    FieldId(ietf_FieldIdEnum arg);
    FieldId();
};
#pragma pack(pop)

// Get value of field as enum type
ietf_FieldIdEnum     value_GetEnum(const ietf::FieldId& parent) __attribute__((nothrow));
// Set value of field from enum type.
void                 value_SetEnum(ietf::FieldId& parent, ietf_FieldIdEnum rhs) __attribute__((nothrow));
// Convert numeric value of field to one of predefined string constants.
// If string is found, return a static C string. Otherwise, return NULL.
const char*          value_ToCstr(const ietf::FieldId& parent) __attribute__((nothrow));
// Convert value to a string. First, attempt conversion to a known string.
// If no string matches, print value as a numeric value.
void                 value_Print(const ietf::FieldId& parent, algo::cstring &lhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, do not modify field and return false.
// In case of success, return true
bool                 value_SetStrptrMaybe(ietf::FieldId& parent, algo::strptr rhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, set numeric value to DFLT
void                 value_SetStrptr(ietf::FieldId& parent, algo::strptr rhs, ietf_FieldIdEnum dflt) __attribute__((nothrow));
// Convert string to field. Return success value
bool                 value_ReadStrptrMaybe(ietf::FieldId& parent, algo::strptr rhs) __attribute__((nothrow));

// Read fields of ietf::FieldId from an ascii string.
// The format of the string is the format of the ietf::FieldId's only field
bool                 FieldId_ReadStrptrMaybe(ietf::FieldId &parent, algo::strptr in_str);
// Set all fields to initial values.
void                 FieldId_Init(ietf::FieldId& parent);
// print string representation of ietf::FieldId to string LHS, no header -- cprint:ietf.FieldId.String
void                 FieldId_Print(ietf::FieldId & row, algo::cstring &str) __attribute__((nothrow));

// --- ietf.Ipv4
#pragma pack(push,1)
struct Ipv4 { // ietf.Ipv4
    u32   ipv4;   //   0  IP address. First octet in bits 24..32
    explicit Ipv4(u32                            in_ipv4);
    bool operator ==(const ietf::Ipv4 &rhs) const;
    bool operator !=(const ietf::Ipv4 &rhs) const;
    bool operator <(const ietf::Ipv4 &rhs) const;
    bool operator >(const ietf::Ipv4 &rhs) const;
    bool operator <=(const ietf::Ipv4 &rhs) const;
    bool operator >=(const ietf::Ipv4 &rhs) const;
    Ipv4();
};
#pragma pack(pop)

u32                  Ipv4_Hash(u32 prev, ietf::Ipv4 rhs) __attribute__((nothrow));
// Read fields of ietf::Ipv4 from an ascii string.
// The function is implemented externally.
bool                 Ipv4_ReadStrptrMaybe(ietf::Ipv4 &parent, algo::strptr in_str);
bool                 Ipv4_Lt(ietf::Ipv4 lhs, ietf::Ipv4 rhs) __attribute__((nothrow));
i32                  Ipv4_Cmp(ietf::Ipv4 lhs, ietf::Ipv4 rhs) __attribute__((nothrow));
// Set all fields to initial values.
void                 Ipv4_Init(ietf::Ipv4& parent);
bool                 Ipv4_Eq(ietf::Ipv4 lhs, ietf::Ipv4 rhs) __attribute__((nothrow));
// Set value. Return true if new value is different from old value.
bool                 Ipv4_Update(ietf::Ipv4 &lhs, ietf::Ipv4 rhs) __attribute__((nothrow));
// Convert ietf::Ipv4 to a string (user-implemented function)
void                 Ipv4_Print(ietf::Ipv4 row, algo::cstring &str) __attribute__((nothrow));

// --- ietf.Ipport
#pragma pack(push,1)
struct Ipport { // ietf.Ipport: IP+Port: host format
    ietf::Ipv4   ip;     //
    u16          port;   //   0
    explicit Ipport(ietf::Ipv4                     in_ip
        ,u16                            in_port);
    bool operator ==(const ietf::Ipport &rhs) const;
    bool operator !=(const ietf::Ipport &rhs) const;
    bool operator <(const ietf::Ipport &rhs) const;
    bool operator >(const ietf::Ipport &rhs) const;
    bool operator <=(const ietf::Ipport &rhs) const;
    bool operator >=(const ietf::Ipport &rhs) const;
    Ipport();
};
#pragma pack(pop)

u32                  Ipport_Hash(u32 prev, ietf::Ipport rhs) __attribute__((nothrow));
// Read fields of ietf::Ipport from an ascii string.
// The function is implemented externally.
bool                 Ipport_ReadStrptrMaybe(ietf::Ipport &parent, algo::strptr in_str);
bool                 Ipport_Lt(ietf::Ipport lhs, ietf::Ipport rhs) __attribute__((nothrow));
i32                  Ipport_Cmp(ietf::Ipport lhs, ietf::Ipport rhs) __attribute__((nothrow));
// Set all fields to initial values.
void                 Ipport_Init(ietf::Ipport& parent);
bool                 Ipport_Eq(ietf::Ipport lhs, ietf::Ipport rhs) __attribute__((nothrow));
// Set value. Return true if new value is different from old value.
bool                 Ipport_Update(ietf::Ipport &lhs, ietf::Ipport rhs) __attribute__((nothrow));
// Convert ietf::Ipport to a string (user-implemented function)
void                 Ipport_Print(ietf::Ipport row, algo::cstring &str) __attribute__((nothrow));

// --- ietf.Ipv4Addr
#pragma pack(push,1)
struct Ipv4Addr { // ietf.Ipv4Addr
    u32   addr_be;   //   0
    explicit Ipv4Addr(u32                            in_addr);
    bool operator ==(const ietf::Ipv4Addr &rhs) const;
    bool operator !=(const ietf::Ipv4Addr &rhs) const;
    bool operator <(const ietf::Ipv4Addr &rhs) const;
    bool operator >(const ietf::Ipv4Addr &rhs) const;
    bool operator <=(const ietf::Ipv4Addr &rhs) const;
    bool operator >=(const ietf::Ipv4Addr &rhs) const;
    Ipv4Addr();
};
#pragma pack(pop)

u32                  addr_Get(const ietf::Ipv4Addr& parent) __attribute__((__warn_unused_result__, nothrow));
void                 addr_Set(ietf::Ipv4Addr& parent, u32 rhs) __attribute__((nothrow));

u32                  Ipv4Addr_Hash(u32 prev, ietf::Ipv4Addr rhs) __attribute__((nothrow));
// Read fields of ietf::Ipv4Addr from an ascii string.
// The function is implemented externally.
bool                 Ipv4Addr_ReadStrptrMaybe(ietf::Ipv4Addr &parent, algo::strptr in_str);
bool                 Ipv4Addr_Lt(ietf::Ipv4Addr lhs, ietf::Ipv4Addr rhs) __attribute__((nothrow));
i32                  Ipv4Addr_Cmp(ietf::Ipv4Addr lhs, ietf::Ipv4Addr rhs) __attribute__((nothrow));
// Set all fields to initial values.
void                 Ipv4Addr_Init(ietf::Ipv4Addr& parent);
bool                 Ipv4Addr_Eq(ietf::Ipv4Addr lhs, ietf::Ipv4Addr rhs) __attribute__((nothrow));
// Set value. Return true if new value is different from old value.
bool                 Ipv4Addr_Update(ietf::Ipv4Addr &lhs, ietf::Ipv4Addr rhs) __attribute__((nothrow));
// Convert ietf::Ipv4Addr to a string (user-implemented function)
void                 Ipv4Addr_Print(ietf::Ipv4Addr row, algo::cstring &str) __attribute__((nothrow));

// --- ietf.Protocol
// access: ietf.Protocol.proto (Protocol)
#pragma pack(push,1)
struct Protocol { // ietf.Protocol: amc-generated struct for internal purposes
    Protocol();
};
#pragma pack(pop)

void                 StaticCheck();

} // gen:ns_print_struct
namespace ietf { // gen:ns_func
} // gen:ns_func
// gen:ns_operators
namespace algo {
inline algo::cstring &operator <<(algo::cstring &str, const ietf::FieldId &row);// cfmt:ietf.FieldId.String
inline algo::cstring &operator <<(algo::cstring &str, const ietf::Ipv4 &row);// cfmt:ietf.Ipv4.String
inline algo::cstring &operator <<(algo::cstring &str, const ietf::Ipport &row);// cfmt:ietf.Ipport.String
}
