//
// include/gen/sandbox_gen.inl.h
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
#include "include/gen/dev_gen.inl.h"
#include "include/gen/algo_gen.inl.h"
//#pragma endinclude
inline sandbox::trace::trace() {
}


// --- sandbox.FDb.sandbox.EmptyQ
// Return true if index is empty
inline bool sandbox::sandbox_EmptyQ() {
    return _db.sandbox_n == 0;
}

// --- sandbox.FDb.sandbox.Find
// Look up row by row id. Return NULL if out of range
inline sandbox::FSandbox* sandbox::sandbox_Find(u64 t) {
    sandbox::FSandbox *retval = NULL;
    if (LIKELY(u64(t) < u64(_db.sandbox_n))) {
        u64 x = t + 1;
        u64 bsr   = algo::u64_BitScanReverse(x);
        u64 base  = u64(1)<<bsr;
        u64 index = x-base;
        retval = &_db.sandbox_lary[bsr][index];
    }
    return retval;
}

// --- sandbox.FDb.sandbox.Last
// Return pointer to last element of array, or NULL if array is empty
inline sandbox::FSandbox* sandbox::sandbox_Last() {
    return sandbox_Find(u64(_db.sandbox_n-1));
}

// --- sandbox.FDb.sandbox.N
// Return number of items in the pool
inline i32 sandbox::sandbox_N() {
    return _db.sandbox_n;
}

// --- sandbox.FDb.sandbox.qFind
// 'quick' Access row by row id. No bounds checking.
inline sandbox::FSandbox& sandbox::sandbox_qFind(u64 t) {
    u64 x = t + 1;
    u64 bsr   = algo::u64_BitScanReverse(x);
    u64 base  = u64(1)<<bsr;
    u64 index = x-base;
    return _db.sandbox_lary[bsr][index];
}

// --- sandbox.FDb.ind_sandbox.EmptyQ
// Return true if hash is empty
inline bool sandbox::ind_sandbox_EmptyQ() {
    return _db.ind_sandbox_n == 0;
}

// --- sandbox.FDb.ind_sandbox.N
// Return number of items in the hash
inline i32 sandbox::ind_sandbox_N() {
    return _db.ind_sandbox_n;
}

// --- sandbox.FDb.sbpath.EmptyQ
// Return true if index is empty
inline bool sandbox::sbpath_EmptyQ() {
    return _db.sbpath_n == 0;
}

// --- sandbox.FDb.sbpath.Find
// Look up row by row id. Return NULL if out of range
inline sandbox::FSbpath* sandbox::sbpath_Find(u64 t) {
    sandbox::FSbpath *retval = NULL;
    if (LIKELY(u64(t) < u64(_db.sbpath_n))) {
        u64 x = t + 1;
        u64 bsr   = algo::u64_BitScanReverse(x);
        u64 base  = u64(1)<<bsr;
        u64 index = x-base;
        retval = &_db.sbpath_lary[bsr][index];
    }
    return retval;
}

// --- sandbox.FDb.sbpath.Last
// Return pointer to last element of array, or NULL if array is empty
inline sandbox::FSbpath* sandbox::sbpath_Last() {
    return sbpath_Find(u64(_db.sbpath_n-1));
}

// --- sandbox.FDb.sbpath.N
// Return number of items in the pool
inline i32 sandbox::sbpath_N() {
    return _db.sbpath_n;
}

// --- sandbox.FDb.sbpath.qFind
// 'quick' Access row by row id. No bounds checking.
inline sandbox::FSbpath& sandbox::sbpath_qFind(u64 t) {
    u64 x = t + 1;
    u64 bsr   = algo::u64_BitScanReverse(x);
    u64 base  = u64(1)<<bsr;
    u64 index = x-base;
    return _db.sbpath_lary[bsr][index];
}

// --- sandbox.FDb.sandbox_curs.Reset
// cursor points to valid item
inline void sandbox::_db_sandbox_curs_Reset(_db_sandbox_curs &curs, sandbox::FDb &parent) {
    curs.parent = &parent;
    curs.index = 0;
}

// --- sandbox.FDb.sandbox_curs.ValidQ
// cursor points to valid item
inline bool sandbox::_db_sandbox_curs_ValidQ(_db_sandbox_curs &curs) {
    return curs.index < _db.sandbox_n;
}

// --- sandbox.FDb.sandbox_curs.Next
// proceed to next item
inline void sandbox::_db_sandbox_curs_Next(_db_sandbox_curs &curs) {
    curs.index++;
}

// --- sandbox.FDb.sandbox_curs.Access
// item access
inline sandbox::FSandbox& sandbox::_db_sandbox_curs_Access(_db_sandbox_curs &curs) {
    return sandbox_qFind(u64(curs.index));
}

// --- sandbox.FDb.sbpath_curs.Reset
// cursor points to valid item
inline void sandbox::_db_sbpath_curs_Reset(_db_sbpath_curs &curs, sandbox::FDb &parent) {
    curs.parent = &parent;
    curs.index = 0;
}

// --- sandbox.FDb.sbpath_curs.ValidQ
// cursor points to valid item
inline bool sandbox::_db_sbpath_curs_ValidQ(_db_sbpath_curs &curs) {
    return curs.index < _db.sbpath_n;
}

// --- sandbox.FDb.sbpath_curs.Next
// proceed to next item
inline void sandbox::_db_sbpath_curs_Next(_db_sbpath_curs &curs) {
    curs.index++;
}

// --- sandbox.FDb.sbpath_curs.Access
// item access
inline sandbox::FSbpath& sandbox::_db_sbpath_curs_Access(_db_sbpath_curs &curs) {
    return sbpath_qFind(u64(curs.index));
}
inline sandbox::FSandbox::FSandbox() {
    sandbox::FSandbox_Init(*this);
}

inline sandbox::FSandbox::~FSandbox() {
    sandbox::FSandbox_Uninit(*this);
}


// --- sandbox.FSandbox..Init
// Set all fields to initial values.
inline void sandbox::FSandbox_Init(sandbox::FSandbox& sandbox) {
    sandbox.select = bool(false);
    sandbox.ind_sandbox_next = (sandbox::FSandbox*)-1; // (sandbox.FDb.ind_sandbox) not-in-hash
}
inline sandbox::FSbpath::FSbpath() {
}

inline sandbox::FieldId::FieldId(i32                            in_value)
    : value(in_value)
{
}
inline sandbox::FieldId::FieldId(sandbox_FieldIdEnum arg) { this->value = i32(arg); }
inline sandbox::FieldId::FieldId() {
    sandbox::FieldId_Init(*this);
}


// --- sandbox.FieldId.value.GetEnum
// Get value of field as enum type
inline sandbox_FieldIdEnum sandbox::value_GetEnum(const sandbox::FieldId& parent) {
    return sandbox_FieldIdEnum(parent.value);
}

// --- sandbox.FieldId.value.SetEnum
// Set value of field from enum type.
inline void sandbox::value_SetEnum(sandbox::FieldId& parent, sandbox_FieldIdEnum rhs) {
    parent.value = i32(rhs);
}

// --- sandbox.FieldId.value.Cast
inline sandbox::FieldId::operator sandbox_FieldIdEnum () const {
    return sandbox_FieldIdEnum((*this).value);
}

// --- sandbox.FieldId..Init
// Set all fields to initial values.
inline void sandbox::FieldId_Init(sandbox::FieldId& parent) {
    parent.value = i32(-1);
}
inline sandbox::TableId::TableId(i32                            in_value)
    : value(in_value)
{
}
inline sandbox::TableId::TableId(sandbox_TableIdEnum arg) { this->value = i32(arg); }
inline sandbox::TableId::TableId() {
    sandbox::TableId_Init(*this);
}


// --- sandbox.TableId.value.GetEnum
// Get value of field as enum type
inline sandbox_TableIdEnum sandbox::value_GetEnum(const sandbox::TableId& parent) {
    return sandbox_TableIdEnum(parent.value);
}

// --- sandbox.TableId.value.SetEnum
// Set value of field from enum type.
inline void sandbox::value_SetEnum(sandbox::TableId& parent, sandbox_TableIdEnum rhs) {
    parent.value = i32(rhs);
}

// --- sandbox.TableId.value.Cast
inline sandbox::TableId::operator sandbox_TableIdEnum () const {
    return sandbox_TableIdEnum((*this).value);
}

// --- sandbox.TableId..Init
// Set all fields to initial values.
inline void sandbox::TableId_Init(sandbox::TableId& parent) {
    parent.value = i32(-1);
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const sandbox::trace &row) {// cfmt:sandbox.trace.String
    sandbox::trace_Print(const_cast<sandbox::trace&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const sandbox::FieldId &row) {// cfmt:sandbox.FieldId.String
    sandbox::FieldId_Print(const_cast<sandbox::FieldId&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const sandbox::TableId &row) {// cfmt:sandbox.TableId.String
    sandbox::TableId_Print(const_cast<sandbox::TableId&>(row), str);
    return str;
}
