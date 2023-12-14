//
// include/gen/gcache_gen.inl.h
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
#include "include/gen/report_gen.inl.h"
#include "include/gen/command_gen.inl.h"
#include "include/gen/algo_gen.inl.h"
#include "include/gen/algo_lib_gen.inl.h"
//#pragma endinclude
inline gcache::cleanreport::cleanreport(i32                            in_n_cachefile
        ,i32                            in_n_cachefile_del
        ,i32                            in_n_cachefile_recent
        ,i32                            in_n_logline
        ,i32                            in_n_logline_del
        ,i64                            in_new_cachesize_mb)
    : n_cachefile(in_n_cachefile)
    , n_cachefile_del(in_n_cachefile_del)
    , n_cachefile_recent(in_n_cachefile_recent)
    , n_logline(in_n_logline)
    , n_logline_del(in_n_logline_del)
    , new_cachesize_mb(in_new_cachesize_mb)
{
}
inline gcache::cleanreport::cleanreport() {
    gcache::cleanreport_Init(*this);
}


// --- gcache.cleanreport..Init
// Set all fields to initial values.
inline void gcache::cleanreport_Init(gcache::cleanreport& parent) {
    parent.n_cachefile = i32(0);
    parent.n_cachefile_del = i32(0);
    parent.n_cachefile_recent = i32(0);
    parent.n_logline = i32(0);
    parent.n_logline_del = i32(0);
    parent.new_cachesize_mb = i64(0);
}
inline gcache::trace::trace() {
}


// --- gcache.FDb.header.EmptyQ
// Return true if index is empty
inline bool gcache::header_EmptyQ() {
    return _db.header_n == 0;
}

// --- gcache.FDb.header.Find
// Look up row by row id. Return NULL if out of range
inline gcache::FHeader* gcache::header_Find(u64 t) {
    gcache::FHeader *retval = NULL;
    if (LIKELY(u64(t) < u64(_db.header_n))) {
        u64 x = t + 1;
        u64 bsr   = algo::u64_BitScanReverse(x);
        u64 base  = u64(1)<<bsr;
        u64 index = x-base;
        retval = &_db.header_lary[bsr][index];
    }
    return retval;
}

// --- gcache.FDb.header.Last
// Return pointer to last element of array, or NULL if array is empty
inline gcache::FHeader* gcache::header_Last() {
    return header_Find(u64(_db.header_n-1));
}

// --- gcache.FDb.header.N
// Return number of items in the pool
inline i32 gcache::header_N() {
    return _db.header_n;
}

// --- gcache.FDb.header.qFind
// 'quick' Access row by row id. No bounds checking.
inline gcache::FHeader& gcache::header_qFind(u64 t) {
    u64 x = t + 1;
    u64 bsr   = algo::u64_BitScanReverse(x);
    u64 base  = u64(1)<<bsr;
    u64 index = x-base;
    return _db.header_lary[bsr][index];
}

// --- gcache.FDb.header_curs.Reset
// cursor points to valid item
inline void gcache::_db_header_curs_Reset(_db_header_curs &curs, gcache::FDb &parent) {
    curs.parent = &parent;
    curs.index = 0;
}

// --- gcache.FDb.header_curs.ValidQ
// cursor points to valid item
inline bool gcache::_db_header_curs_ValidQ(_db_header_curs &curs) {
    return curs.index < _db.header_n;
}

// --- gcache.FDb.header_curs.Next
// proceed to next item
inline void gcache::_db_header_curs_Next(_db_header_curs &curs) {
    curs.index++;
}

// --- gcache.FDb.header_curs.Access
// item access
inline gcache::FHeader& gcache::_db_header_curs_Access(_db_header_curs &curs) {
    return header_qFind(u64(curs.index));
}
inline gcache::FHeader::FHeader() {
    gcache::FHeader_Init(*this);
}


// --- gcache.FHeader..Init
// Set all fields to initial values.
inline void gcache::FHeader_Init(gcache::FHeader& header) {
    header.parent = NULL;
    header.begin = i32(0);
    header.inner_end = i32(0);
    header.outer_end = i32(0);
    header.mlines_before = bool(false);
}
inline gcache::FieldId::FieldId(i32                            in_value)
    : value(in_value)
{
}
inline gcache::FieldId::FieldId(gcache_FieldIdEnum arg) { this->value = i32(arg); }
inline gcache::FieldId::FieldId() {
    gcache::FieldId_Init(*this);
}


// --- gcache.FieldId.value.GetEnum
// Get value of field as enum type
inline gcache_FieldIdEnum gcache::value_GetEnum(const gcache::FieldId& parent) {
    return gcache_FieldIdEnum(parent.value);
}

// --- gcache.FieldId.value.SetEnum
// Set value of field from enum type.
inline void gcache::value_SetEnum(gcache::FieldId& parent, gcache_FieldIdEnum rhs) {
    parent.value = i32(rhs);
}

// --- gcache.FieldId.value.Cast
inline gcache::FieldId::operator gcache_FieldIdEnum () const {
    return gcache_FieldIdEnum((*this).value);
}

// --- gcache.FieldId..Init
// Set all fields to initial values.
inline void gcache::FieldId_Init(gcache::FieldId& parent) {
    parent.value = i32(-1);
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const gcache::cleanreport &row) {// cfmt:gcache.cleanreport.String
    gcache::cleanreport_Print(const_cast<gcache::cleanreport&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const gcache::trace &row) {// cfmt:gcache.trace.String
    gcache::trace_Print(const_cast<gcache::trace&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const gcache::FHeader &row) {// cfmt:gcache.FHeader.String
    gcache::FHeader_Print(const_cast<gcache::FHeader&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const gcache::FieldId &row) {// cfmt:gcache.FieldId.String
    gcache::FieldId_Print(const_cast<gcache::FieldId&>(row), str);
    return str;
}
