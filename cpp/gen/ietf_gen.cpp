//
// cpp/gen/ietf_gen.cpp
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
#include "include/gen/ietf_gen.h"
#include "include/gen/ietf_gen.inl.h"
//#pragma endinclude
namespace ietf { // gen:ns_print_proto
    // func:ietf.Ipv4Addr.addr.ReadStrptrMaybe
    static bool          addr_ReadStrptrMaybe(ietf::Ipv4Addr &parent, algo::strptr in_str) __attribute__((nothrow));
    // func:ietf...SizeCheck
    static void          SizeCheck();
} // gen:ns_print_proto

// --- ietf.FieldId.value.ToCstr
// Convert numeric value of field to one of predefined string constants.
// If string is found, return a static C string. Otherwise, return NULL.
const char* ietf::value_ToCstr(const ietf::FieldId& parent) {
    const char *ret = NULL;
    switch(value_GetEnum(parent)) {
        case ietf_FieldId_ip               : ret = "ip";  break;
        case ietf_FieldId_port             : ret = "port";  break;
        case ietf_FieldId_ipv4             : ret = "ipv4";  break;
        case ietf_FieldId_addr             : ret = "addr";  break;
        case ietf_FieldId_value            : ret = "value";  break;
    }
    return ret;
}

// --- ietf.FieldId.value.Print
// Convert value to a string. First, attempt conversion to a known string.
// If no string matches, print value as a numeric value.
void ietf::value_Print(const ietf::FieldId& parent, algo::cstring &lhs) {
    const char *strval = value_ToCstr(parent);
    if (strval) {
        lhs << strval;
    } else {
        lhs << parent.value;
    }
}

// --- ietf.FieldId.value.SetStrptrMaybe
// Convert string to field.
// If the string is invalid, do not modify field and return false.
// In case of success, return true
bool ietf::value_SetStrptrMaybe(ietf::FieldId& parent, algo::strptr rhs) {
    bool ret = false;
    switch (elems_N(rhs)) {
        case 2: {
            switch (u64(algo::ReadLE16(rhs.elems))) {
                case LE_STR2('i','p'): {
                    value_SetEnum(parent,ietf_FieldId_ip); ret = true; break;
                }
            }
            break;
        }
        case 4: {
            switch (u64(algo::ReadLE32(rhs.elems))) {
                case LE_STR4('a','d','d','r'): {
                    value_SetEnum(parent,ietf_FieldId_addr); ret = true; break;
                }
                case LE_STR4('i','p','v','4'): {
                    value_SetEnum(parent,ietf_FieldId_ipv4); ret = true; break;
                }
                case LE_STR4('p','o','r','t'): {
                    value_SetEnum(parent,ietf_FieldId_port); ret = true; break;
                }
            }
            break;
        }
        case 5: {
            switch (u64(algo::ReadLE32(rhs.elems))|(u64(rhs[4])<<32)) {
                case LE_STR5('v','a','l','u','e'): {
                    value_SetEnum(parent,ietf_FieldId_value); ret = true; break;
                }
            }
            break;
        }
    }
    return ret;
}

// --- ietf.FieldId.value.SetStrptr
// Convert string to field.
// If the string is invalid, set numeric value to DFLT
void ietf::value_SetStrptr(ietf::FieldId& parent, algo::strptr rhs, ietf_FieldIdEnum dflt) {
    if (!value_SetStrptrMaybe(parent,rhs)) value_SetEnum(parent,dflt);
}

// --- ietf.FieldId.value.ReadStrptrMaybe
// Convert string to field. Return success value
bool ietf::value_ReadStrptrMaybe(ietf::FieldId& parent, algo::strptr rhs) {
    bool retval = false;
    retval = value_SetStrptrMaybe(parent,rhs); // try symbol conversion
    if (!retval) { // didn't work? try reading as underlying type
        retval = i32_ReadStrptrMaybe(parent.value,rhs);
    }
    return retval;
}

// --- ietf.FieldId..ReadStrptrMaybe
// Read fields of ietf::FieldId from an ascii string.
// The format of the string is the format of the ietf::FieldId's only field
bool ietf::FieldId_ReadStrptrMaybe(ietf::FieldId &parent, algo::strptr in_str) {
    bool retval = true;
    retval = retval && value_ReadStrptrMaybe(parent, in_str);
    return retval;
}

// --- ietf.FieldId..Print
// print string representation of ROW to string STR
// cfmt:ietf.FieldId.String  printfmt:Raw
void ietf::FieldId_Print(ietf::FieldId& row, algo::cstring& str) {
    ietf::value_Print(row, str);
}

// --- ietf.Ipv4Addr.addr.ReadStrptrMaybe
inline static bool ietf::addr_ReadStrptrMaybe(ietf::Ipv4Addr &parent, algo::strptr in_str) {
    bool retval = true;
    u32 addr_tmp;
    retval = u32_ReadStrptrMaybe(addr_tmp, in_str);
    if (retval) {
        addr_Set(parent, addr_tmp);
    }
    return retval;
}

// --- ietf.Protocol.proto.StaticCheck
void ietf::StaticCheck() {
    algo_assert(_offset_of(ietf::FieldId, value) + sizeof(((ietf::FieldId*)0)->value) == sizeof(ietf::FieldId));
    algo_assert(_offset_of(ietf::Ipv4, ipv4) + sizeof(((ietf::Ipv4*)0)->ipv4) == sizeof(ietf::Ipv4));
    algo_assert(_offset_of(ietf::Ipport, port) + sizeof(((ietf::Ipport*)0)->port) == sizeof(ietf::Ipport));
    algo_assert(_offset_of(ietf::Ipv4Addr, addr_be) + sizeof(((ietf::Ipv4Addr*)0)->addr_be) == sizeof(ietf::Ipv4Addr));
}

// --- ietf...SizeCheck
inline static void ietf::SizeCheck() {
    algo_assert(_offset_of(ietf::Ipv4,ipv4) == 0);
    algo_assert(sizeof(ietf::Ipv4) == 4);
    algo_assert(_offset_of(ietf::Ipport,ip) == 0);
    algo_assert(_offset_of(ietf::Ipport,port) == 4);
    algo_assert(sizeof(ietf::Ipport) == 6);
    algo_assert(_offset_of(ietf::Ipv4Addr,addr_be) == 0);
    algo_assert(sizeof(ietf::Ipv4Addr) == 4);
}
