//
// include/gen/bash2html_gen.inl.h
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
#include "include/gen/command_gen.inl.h"
//#pragma endinclude
inline bash2html::trace::trace() {
}

inline bash2html::FieldId::FieldId(i32                            in_value)
    : value(in_value)
{
}
inline bash2html::FieldId::FieldId(bash2html_FieldIdEnum arg) { this->value = i32(arg); }
inline bash2html::FieldId::FieldId() {
    bash2html::FieldId_Init(*this);
}


// --- bash2html.FieldId.value.GetEnum
// Get value of field as enum type
inline bash2html_FieldIdEnum bash2html::value_GetEnum(const bash2html::FieldId& parent) {
    return bash2html_FieldIdEnum(parent.value);
}

// --- bash2html.FieldId.value.SetEnum
// Set value of field from enum type.
inline void bash2html::value_SetEnum(bash2html::FieldId& parent, bash2html_FieldIdEnum rhs) {
    parent.value = i32(rhs);
}

// --- bash2html.FieldId.value.Cast
inline bash2html::FieldId::operator bash2html_FieldIdEnum () const {
    return bash2html_FieldIdEnum((*this).value);
}

// --- bash2html.FieldId..Init
// Set all fields to initial values.
inline void bash2html::FieldId_Init(bash2html::FieldId& parent) {
    parent.value = i32(-1);
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const bash2html::trace &row) {// cfmt:bash2html.trace.String
    bash2html::trace_Print(const_cast<bash2html::trace&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const bash2html::FieldId &row) {// cfmt:bash2html.FieldId.String
    bash2html::FieldId_Print(const_cast<bash2html::FieldId&>(row), str);
    return str;
}
