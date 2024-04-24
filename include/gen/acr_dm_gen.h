//
// include/gen/acr_dm_gen.h
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
#include "include/gen/command_gen.h"
//#pragma endinclude
// gen:ns_enums

// --- acr_dm_FieldIdEnum

enum acr_dm_FieldIdEnum {        // acr_dm.FieldId.value
     acr_dm_FieldId_f1      = 0
    ,acr_dm_FieldId_f2      = 1
    ,acr_dm_FieldId_f3      = 2
    ,acr_dm_FieldId_value   = 3
};

enum { acr_dm_FieldIdEnum_N = 4 };

namespace acr_dm { // gen:ns_pkeytypedef
} // gen:ns_pkeytypedef
namespace acr_dm { // gen:ns_field
extern const char *acr_dm_help;
} // gen:ns_field
// gen:ns_fwddecl2
namespace acr_dm { struct FTuple; }
namespace acr_dm { struct FAttr; }
namespace acr_dm { struct attr_zs_value_curs; }
namespace acr_dm { struct _db_tuple_curs; }
namespace acr_dm { struct _db_attr_curs; }
namespace acr_dm { struct _db_value_curs; }
namespace acr_dm { struct _db_bh_tuple_curs; }
namespace acr_dm { struct Source_source_bitcurs; }
namespace acr_dm { struct tuple_zs_attr_curs; }
namespace acr_dm { struct trace; }
namespace acr_dm { struct FDb; }
namespace acr_dm { struct Rowid; }
namespace acr_dm { struct Source; }
namespace acr_dm { struct FValue; }
namespace acr_dm { struct FieldId; }
namespace acr_dm { extern struct acr_dm::FDb _db; }
namespace acr_dm { // gen:ns_print_struct

// --- acr_dm.FAttr
// create: acr_dm.FDb.attr (Lary)
// access: acr_dm.FTuple.zs_attr (Llist)
// access: acr_dm.FValue.p_attr (Upptr)
struct FAttr { // acr_dm.FAttr
    algo::cstring     name;            //
    acr_dm::FTuple*   p_tuple;         // reference to parent row
    acr_dm::FValue*   zs_value_head;   // zero-terminated singly linked list
    i32               zs_value_n;      // zero-terminated singly linked list
    acr_dm::FValue*   zs_value_tail;   // pointer to last element
    acr_dm::FAttr*    zs_attr_next;    // zslist link; -1 means not-in-list
private:
    friend acr_dm::FAttr&       attr_Alloc() __attribute__((__warn_unused_result__, nothrow));
    friend acr_dm::FAttr*       attr_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
    friend void                 attr_RemoveAll() __attribute__((nothrow));
    friend void                 attr_RemoveLast() __attribute__((nothrow));
    FAttr();
    ~FAttr();
    FAttr(const FAttr&){ /*disallow copy constructor */}
    void operator =(const FAttr&){ /*disallow direct assignment */}
};

// Return true if index is empty
// func:acr_dm.FAttr.zs_value.EmptyQ
bool                 zs_value_EmptyQ(acr_dm::FAttr& attr) __attribute__((__warn_unused_result__, nothrow, pure));
// If index empty, return NULL. Otherwise return pointer to first element in index
// func:acr_dm.FAttr.zs_value.First
acr_dm::FValue*      zs_value_First(acr_dm::FAttr& attr) __attribute__((__warn_unused_result__, nothrow, pure));
// Return true if row is in the linked list, false otherwise
// func:acr_dm.FAttr.zs_value.InLlistQ
bool                 zs_value_InLlistQ(acr_dm::FValue& row) __attribute__((__warn_unused_result__, nothrow));
// Insert row into linked list. If row is already in linked list, do nothing.
// func:acr_dm.FAttr.zs_value.Insert
void                 zs_value_Insert(acr_dm::FAttr& attr, acr_dm::FValue& row) __attribute__((nothrow));
// If index empty, return NULL. Otherwise return pointer to last element in index
// func:acr_dm.FAttr.zs_value.Last
acr_dm::FValue*      zs_value_Last(acr_dm::FAttr& attr) __attribute__((__warn_unused_result__, nothrow, pure));
// Return number of items in the linked list
// func:acr_dm.FAttr.zs_value.N
i32                  zs_value_N(const acr_dm::FAttr& attr) __attribute__((__warn_unused_result__, nothrow, pure));
// Return pointer to next element in the list
// func:acr_dm.FAttr.zs_value.Next
acr_dm::FValue*      zs_value_Next(acr_dm::FValue &row) __attribute__((__warn_unused_result__, nothrow));
// Remove element from index. If element is not in index, do nothing.
// Since the list is singly-linked, use linear search to locate the element.
// func:acr_dm.FAttr.zs_value.Remove
void                 zs_value_Remove(acr_dm::FAttr& attr, acr_dm::FValue& row) __attribute__((nothrow));
// Empty the index. (The rows are not deleted)
// func:acr_dm.FAttr.zs_value.RemoveAll
void                 zs_value_RemoveAll(acr_dm::FAttr& attr) __attribute__((nothrow));
// If linked list is empty, return NULL. Otherwise unlink and return pointer to first element.
// func:acr_dm.FAttr.zs_value.RemoveFirst
acr_dm::FValue*      zs_value_RemoveFirst(acr_dm::FAttr& attr) __attribute__((nothrow));
// Return reference to last element in the index. No bounds checking.
// func:acr_dm.FAttr.zs_value.qLast
acr_dm::FValue&      zs_value_qLast(acr_dm::FAttr& attr) __attribute__((__warn_unused_result__, nothrow));

// cursor points to valid item
// func:acr_dm.FAttr.zs_value_curs.Reset
void                 attr_zs_value_curs_Reset(attr_zs_value_curs &curs, acr_dm::FAttr &parent) __attribute__((nothrow));
// cursor points to valid item
// func:acr_dm.FAttr.zs_value_curs.ValidQ
bool                 attr_zs_value_curs_ValidQ(attr_zs_value_curs &curs) __attribute__((nothrow));
// proceed to next item
// func:acr_dm.FAttr.zs_value_curs.Next
void                 attr_zs_value_curs_Next(attr_zs_value_curs &curs) __attribute__((nothrow));
// item access
// func:acr_dm.FAttr.zs_value_curs.Access
acr_dm::FValue&      attr_zs_value_curs_Access(attr_zs_value_curs &curs) __attribute__((nothrow));
// Set all fields to initial values.
// func:acr_dm.FAttr..Init
void                 FAttr_Init(acr_dm::FAttr& attr);
// func:acr_dm.FAttr..Uninit
void                 FAttr_Uninit(acr_dm::FAttr& attr) __attribute__((nothrow));

// --- acr_dm.trace
#pragma pack(push,1)
struct trace { // acr_dm.trace
    trace();
};
#pragma pack(pop)

// print string representation of ROW to string STR
// cfmt:acr_dm.trace.String  printfmt:Tuple
// func:acr_dm.trace..Print
void                 trace_Print(acr_dm::trace& row, algo::cstring& str) __attribute__((nothrow));

// --- acr_dm.FDb
// create: acr_dm.FDb._db (Global)
struct FDb { // acr_dm.FDb: In-memory database for acr_dm
    command::acr_dm    cmdline;                   //
    acr_dm::FTuple*    tuple_lary[32];            // level array
    i32                tuple_n;                   // number of elements in array
    acr_dm::FTuple**   ind_tuple_buckets_elems;   // pointer to bucket array
    i32                ind_tuple_buckets_n;       // number of elements in bucket array
    i32                ind_tuple_n;               // number of elements in the hash table
    acr_dm::FAttr*     attr_lary[32];             // level array
    i32                attr_n;                    // number of elements in array
    acr_dm::FValue*    value_lary[32];            // level array
    i32                value_n;                   // number of elements in array
    acr_dm::FTuple**   bh_tuple_elems;            // binary heap by rowid
    i32                bh_tuple_n;                // number of elements in the heap
    i32                bh_tuple_max;              // max elements in bh_tuple_elems
    acr_dm::trace      trace;                     //
};

// Read argc,argv directly into the fields of the command line(s)
// The following fields are updated:
//     acr_dm.FDb.cmdline
//     algo_lib.FDb.cmdline
// func:acr_dm.FDb._db.ReadArgv
void                 ReadArgv() __attribute__((nothrow));
// Main loop.
// func:acr_dm.FDb._db.MainLoop
void                 MainLoop();
// Main step
// func:acr_dm.FDb._db.Step
void                 Step();
// Main function
// func:acr_dm.FDb._db.Main
// this function is 'extrn' and implemented by user
void                 Main();
// func:acr_dm.FDb._db.StaticCheck
void                 StaticCheck();
// Parse strptr into known type and add to database.
// Return value is true unless an error occurs. If return value is false, algo_lib::_db.errtext has error text
// func:acr_dm.FDb._db.InsertStrptrMaybe
bool                 InsertStrptrMaybe(algo::strptr str);
// Load all finputs from given directory.
// func:acr_dm.FDb._db.LoadTuplesMaybe
bool                 LoadTuplesMaybe(algo::strptr root, bool recursive) __attribute__((nothrow));
// Load all finputs from given file.
// Read tuples from file FNAME into this namespace's in-memory database.
// If RECURSIVE is TRUE, then also load these tuples into any parent namespaces
// It a file referred to by FNAME is missing, no error is reported (it's considered an empty set).
// Function returns TRUE if all records were parsed and inserted without error.
// If the function returns FALSE, use algo_lib::DetachBadTags() for error description
// func:acr_dm.FDb._db.LoadTuplesFile
bool                 LoadTuplesFile(algo::strptr fname, bool recursive) __attribute__((nothrow));
// Load all finputs from given file descriptor.
// func:acr_dm.FDb._db.LoadTuplesFd
bool                 LoadTuplesFd(algo::Fildes fd, algo::strptr fname, bool recursive) __attribute__((nothrow));
// Load specified ssimfile.
// func:acr_dm.FDb._db.LoadSsimfileMaybe
bool                 LoadSsimfileMaybe(algo::strptr fname, bool recursive) __attribute__((nothrow));
// Calls Step function of dependencies
// func:acr_dm.FDb._db.Steps
void                 Steps();
// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Caller must Delete or Unref such row.
// func:acr_dm.FDb._db.XrefMaybe
bool                 _db_XrefMaybe();

// Allocate memory for new default row.
// If out of memory, process is killed.
// func:acr_dm.FDb.tuple.Alloc
acr_dm::FTuple&      tuple_Alloc() __attribute__((__warn_unused_result__, nothrow));
// Allocate memory for new element. If out of memory, return NULL.
// func:acr_dm.FDb.tuple.AllocMaybe
acr_dm::FTuple*      tuple_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
// Allocate space for one element. If no memory available, return NULL.
// func:acr_dm.FDb.tuple.AllocMem
void*                tuple_AllocMem() __attribute__((__warn_unused_result__, nothrow));
// Return true if index is empty
// func:acr_dm.FDb.tuple.EmptyQ
bool                 tuple_EmptyQ() __attribute__((nothrow, pure));
// Look up row by row id. Return NULL if out of range
// func:acr_dm.FDb.tuple.Find
acr_dm::FTuple*      tuple_Find(u64 t) __attribute__((__warn_unused_result__, nothrow, pure));
// Return pointer to last element of array, or NULL if array is empty
// func:acr_dm.FDb.tuple.Last
acr_dm::FTuple*      tuple_Last() __attribute__((nothrow, pure));
// Return number of items in the pool
// func:acr_dm.FDb.tuple.N
i32                  tuple_N() __attribute__((__warn_unused_result__, nothrow, pure));
// Remove all elements from Lary
// func:acr_dm.FDb.tuple.RemoveAll
void                 tuple_RemoveAll() __attribute__((nothrow));
// Delete last element of array. Do nothing if array is empty.
// func:acr_dm.FDb.tuple.RemoveLast
void                 tuple_RemoveLast() __attribute__((nothrow));
// 'quick' Access row by row id. No bounds checking.
// func:acr_dm.FDb.tuple.qFind
acr_dm::FTuple&      tuple_qFind(u64 t) __attribute__((nothrow, pure));
// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Caller must Delete or Unref such row.
// func:acr_dm.FDb.tuple.XrefMaybe
bool                 tuple_XrefMaybe(acr_dm::FTuple &row);

// Return true if hash is empty
// func:acr_dm.FDb.ind_tuple.EmptyQ
bool                 ind_tuple_EmptyQ() __attribute__((nothrow));
// Find row by key. Return NULL if not found.
// func:acr_dm.FDb.ind_tuple.Find
acr_dm::FTuple*      ind_tuple_Find(const algo::strptr& key) __attribute__((__warn_unused_result__, nothrow));
// Look up row by key and return reference. Throw exception if not found
// func:acr_dm.FDb.ind_tuple.FindX
acr_dm::FTuple&      ind_tuple_FindX(const algo::strptr& key);
// Find row by key. If not found, create and x-reference a new row with with this key.
// func:acr_dm.FDb.ind_tuple.GetOrCreate
acr_dm::FTuple&      ind_tuple_GetOrCreate(const algo::strptr& key) __attribute__((nothrow));
// Return number of items in the hash
// func:acr_dm.FDb.ind_tuple.N
i32                  ind_tuple_N() __attribute__((__warn_unused_result__, nothrow, pure));
// Insert row into hash table. Return true if row is reachable through the hash after the function completes.
// func:acr_dm.FDb.ind_tuple.InsertMaybe
bool                 ind_tuple_InsertMaybe(acr_dm::FTuple& row) __attribute__((nothrow));
// Remove reference to element from hash index. If element is not in hash, do nothing
// func:acr_dm.FDb.ind_tuple.Remove
void                 ind_tuple_Remove(acr_dm::FTuple& row) __attribute__((nothrow));
// Reserve enough room in the hash for N more elements. Return success code.
// func:acr_dm.FDb.ind_tuple.Reserve
void                 ind_tuple_Reserve(int n) __attribute__((nothrow));

// Allocate memory for new default row.
// If out of memory, process is killed.
// func:acr_dm.FDb.attr.Alloc
acr_dm::FAttr&       attr_Alloc() __attribute__((__warn_unused_result__, nothrow));
// Allocate memory for new element. If out of memory, return NULL.
// func:acr_dm.FDb.attr.AllocMaybe
acr_dm::FAttr*       attr_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
// Allocate space for one element. If no memory available, return NULL.
// func:acr_dm.FDb.attr.AllocMem
void*                attr_AllocMem() __attribute__((__warn_unused_result__, nothrow));
// Return true if index is empty
// func:acr_dm.FDb.attr.EmptyQ
bool                 attr_EmptyQ() __attribute__((nothrow, pure));
// Look up row by row id. Return NULL if out of range
// func:acr_dm.FDb.attr.Find
acr_dm::FAttr*       attr_Find(u64 t) __attribute__((__warn_unused_result__, nothrow, pure));
// Return pointer to last element of array, or NULL if array is empty
// func:acr_dm.FDb.attr.Last
acr_dm::FAttr*       attr_Last() __attribute__((nothrow, pure));
// Return number of items in the pool
// func:acr_dm.FDb.attr.N
i32                  attr_N() __attribute__((__warn_unused_result__, nothrow, pure));
// Remove all elements from Lary
// func:acr_dm.FDb.attr.RemoveAll
void                 attr_RemoveAll() __attribute__((nothrow));
// Delete last element of array. Do nothing if array is empty.
// func:acr_dm.FDb.attr.RemoveLast
void                 attr_RemoveLast() __attribute__((nothrow));
// 'quick' Access row by row id. No bounds checking.
// func:acr_dm.FDb.attr.qFind
acr_dm::FAttr&       attr_qFind(u64 t) __attribute__((nothrow, pure));
// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Caller must Delete or Unref such row.
// func:acr_dm.FDb.attr.XrefMaybe
bool                 attr_XrefMaybe(acr_dm::FAttr &row);

// Allocate memory for new default row.
// If out of memory, process is killed.
// func:acr_dm.FDb.value.Alloc
acr_dm::FValue&      value_Alloc() __attribute__((__warn_unused_result__, nothrow));
// Allocate memory for new element. If out of memory, return NULL.
// func:acr_dm.FDb.value.AllocMaybe
acr_dm::FValue*      value_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
// Allocate space for one element. If no memory available, return NULL.
// func:acr_dm.FDb.value.AllocMem
void*                value_AllocMem() __attribute__((__warn_unused_result__, nothrow));
// Return true if index is empty
// func:acr_dm.FDb.value.EmptyQ
bool                 value_EmptyQ() __attribute__((nothrow, pure));
// Look up row by row id. Return NULL if out of range
// func:acr_dm.FDb.value.Find
acr_dm::FValue*      value_Find(u64 t) __attribute__((__warn_unused_result__, nothrow, pure));
// Return pointer to last element of array, or NULL if array is empty
// func:acr_dm.FDb.value.Last
acr_dm::FValue*      value_Last() __attribute__((nothrow, pure));
// Return number of items in the pool
// func:acr_dm.FDb.value.N
i32                  value_N() __attribute__((__warn_unused_result__, nothrow, pure));
// Remove all elements from Lary
// func:acr_dm.FDb.value.RemoveAll
void                 value_RemoveAll() __attribute__((nothrow));
// Delete last element of array. Do nothing if array is empty.
// func:acr_dm.FDb.value.RemoveLast
void                 value_RemoveLast() __attribute__((nothrow));
// 'quick' Access row by row id. No bounds checking.
// func:acr_dm.FDb.value.qFind
acr_dm::FValue&      value_qFind(u64 t) __attribute__((nothrow, pure));
// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Caller must Delete or Unref such row.
// func:acr_dm.FDb.value.XrefMaybe
bool                 value_XrefMaybe(acr_dm::FValue &row);

// Remove all elements from heap and free memory used by the array.
// func:acr_dm.FDb.bh_tuple.Dealloc
void                 bh_tuple_Dealloc() __attribute__((nothrow));
// Return true if index is empty
// func:acr_dm.FDb.bh_tuple.EmptyQ
bool                 bh_tuple_EmptyQ() __attribute__((nothrow));
// If index empty, return NULL. Otherwise return pointer to first element in index
// func:acr_dm.FDb.bh_tuple.First
acr_dm::FTuple*      bh_tuple_First() __attribute__((__warn_unused_result__, nothrow, pure));
// Return true if row is in index, false otherwise
// func:acr_dm.FDb.bh_tuple.InBheapQ
bool                 bh_tuple_InBheapQ(acr_dm::FTuple& row) __attribute__((__warn_unused_result__, nothrow));
// Insert row. Row must not already be in index. If row is already in index, do nothing.
// func:acr_dm.FDb.bh_tuple.Insert
void                 bh_tuple_Insert(acr_dm::FTuple& row) __attribute__((nothrow));
// Return number of items in the heap
// func:acr_dm.FDb.bh_tuple.N
i32                  bh_tuple_N() __attribute__((__warn_unused_result__, nothrow, pure));
// If row is in heap, update its position. If row is not in heap, insert it.
// Return new position of item in the heap (0=top)
// func:acr_dm.FDb.bh_tuple.Reheap
i32                  bh_tuple_Reheap(acr_dm::FTuple& row) __attribute__((nothrow));
// Key of first element in the heap changed. Move it.
// This function does not check the insert condition.
// Return new position of item in the heap (0=top).
// Heap must be non-empty or behavior is undefined.
// func:acr_dm.FDb.bh_tuple.ReheapFirst
i32                  bh_tuple_ReheapFirst() __attribute__((nothrow));
// Remove element from index. If element is not in index, do nothing.
// func:acr_dm.FDb.bh_tuple.Remove
void                 bh_tuple_Remove(acr_dm::FTuple& row) __attribute__((nothrow));
// Remove all elements from binary heap
// func:acr_dm.FDb.bh_tuple.RemoveAll
void                 bh_tuple_RemoveAll() __attribute__((nothrow));
// If index is empty, return NULL. Otherwise remove and return first key in index.
//  Call 'head changed' trigger.
// func:acr_dm.FDb.bh_tuple.RemoveFirst
acr_dm::FTuple*      bh_tuple_RemoveFirst() __attribute__((nothrow));
// Reserve space in index for N more elements
// func:acr_dm.FDb.bh_tuple.Reserve
void                 bh_tuple_Reserve(int n) __attribute__((nothrow));

// cursor points to valid item
// func:acr_dm.FDb.tuple_curs.Reset
void                 _db_tuple_curs_Reset(_db_tuple_curs &curs, acr_dm::FDb &parent) __attribute__((nothrow));
// cursor points to valid item
// func:acr_dm.FDb.tuple_curs.ValidQ
bool                 _db_tuple_curs_ValidQ(_db_tuple_curs &curs) __attribute__((nothrow));
// proceed to next item
// func:acr_dm.FDb.tuple_curs.Next
void                 _db_tuple_curs_Next(_db_tuple_curs &curs) __attribute__((nothrow));
// item access
// func:acr_dm.FDb.tuple_curs.Access
acr_dm::FTuple&      _db_tuple_curs_Access(_db_tuple_curs &curs) __attribute__((nothrow));
// cursor points to valid item
// func:acr_dm.FDb.attr_curs.Reset
void                 _db_attr_curs_Reset(_db_attr_curs &curs, acr_dm::FDb &parent) __attribute__((nothrow));
// cursor points to valid item
// func:acr_dm.FDb.attr_curs.ValidQ
bool                 _db_attr_curs_ValidQ(_db_attr_curs &curs) __attribute__((nothrow));
// proceed to next item
// func:acr_dm.FDb.attr_curs.Next
void                 _db_attr_curs_Next(_db_attr_curs &curs) __attribute__((nothrow));
// item access
// func:acr_dm.FDb.attr_curs.Access
acr_dm::FAttr&       _db_attr_curs_Access(_db_attr_curs &curs) __attribute__((nothrow));
// cursor points to valid item
// func:acr_dm.FDb.value_curs.Reset
void                 _db_value_curs_Reset(_db_value_curs &curs, acr_dm::FDb &parent) __attribute__((nothrow));
// cursor points to valid item
// func:acr_dm.FDb.value_curs.ValidQ
bool                 _db_value_curs_ValidQ(_db_value_curs &curs) __attribute__((nothrow));
// proceed to next item
// func:acr_dm.FDb.value_curs.Next
void                 _db_value_curs_Next(_db_value_curs &curs) __attribute__((nothrow));
// item access
// func:acr_dm.FDb.value_curs.Access
acr_dm::FValue&      _db_value_curs_Access(_db_value_curs &curs) __attribute__((nothrow));
// func:acr_dm.FDb.bh_tuple_curs.Reserve
void                 _db_bh_tuple_curs_Reserve(_db_bh_tuple_curs &curs, int n);
// Reset cursor. If HEAP is non-empty, add its top element to CURS.
// func:acr_dm.FDb.bh_tuple_curs.Reset
void                 _db_bh_tuple_curs_Reset(_db_bh_tuple_curs &curs, acr_dm::FDb &parent);
// Advance cursor.
// func:acr_dm.FDb.bh_tuple_curs.Next
void                 _db_bh_tuple_curs_Next(_db_bh_tuple_curs &curs);
// Access current element. If not more elements, return NULL
// func:acr_dm.FDb.bh_tuple_curs.Access
acr_dm::FTuple&      _db_bh_tuple_curs_Access(_db_bh_tuple_curs &curs) __attribute__((nothrow));
// Return true if Access() will return non-NULL.
// func:acr_dm.FDb.bh_tuple_curs.ValidQ
bool                 _db_bh_tuple_curs_ValidQ(_db_bh_tuple_curs &curs) __attribute__((nothrow));
// Set all fields to initial values.
// func:acr_dm.FDb..Init
void                 FDb_Init();
// func:acr_dm.FDb..Uninit
void                 FDb_Uninit() __attribute__((nothrow));

// --- acr_dm.Rowid
struct Rowid { // acr_dm.Rowid
    i32   f1;   //   0
    i32   f2;   //   0
    i32   f3;   //   0
    explicit Rowid(i32                            in_f1
        ,i32                            in_f2
        ,i32                            in_f3);
    bool operator ==(const acr_dm::Rowid &rhs) const;
    bool operator !=(const acr_dm::Rowid &rhs) const;
    bool operator <(const acr_dm::Rowid &rhs) const;
    bool operator >(const acr_dm::Rowid &rhs) const;
    bool operator <=(const acr_dm::Rowid &rhs) const;
    bool operator >=(const acr_dm::Rowid &rhs) const;
    Rowid();
};

// func:acr_dm.Rowid..ReadFieldMaybe
bool                 Rowid_ReadFieldMaybe(acr_dm::Rowid& parent, algo::strptr field, algo::strptr strval) __attribute__((nothrow));
// Read fields of acr_dm::Rowid from an ascii string.
// The format of the string is a string with separated values
// func:acr_dm.Rowid..ReadStrptrMaybe
bool                 Rowid_ReadStrptrMaybe(acr_dm::Rowid &parent, algo::strptr in_str) __attribute__((nothrow));
// func:acr_dm.Rowid..Lt
bool                 Rowid_Lt(acr_dm::Rowid& lhs, acr_dm::Rowid& rhs) __attribute__((nothrow));
// func:acr_dm.Rowid..Cmp
i32                  Rowid_Cmp(acr_dm::Rowid& lhs, acr_dm::Rowid& rhs) __attribute__((nothrow));
// Set all fields to initial values.
// func:acr_dm.Rowid..Init
void                 Rowid_Init(acr_dm::Rowid& parent);
// func:acr_dm.Rowid..Eq
bool                 Rowid_Eq(acr_dm::Rowid& lhs, acr_dm::Rowid& rhs) __attribute__((nothrow));
// Set value. Return true if new value is different from old value.
// func:acr_dm.Rowid..Update
bool                 Rowid_Update(acr_dm::Rowid &lhs, acr_dm::Rowid& rhs) __attribute__((nothrow));
// print string representation of ROW to string STR
// cfmt:acr_dm.Rowid.String  printfmt:Sep
// func:acr_dm.Rowid..Print
void                 Rowid_Print(acr_dm::Rowid& row, algo::cstring& str) __attribute__((nothrow));

// --- acr_dm.Source
struct Source { // acr_dm.Source
    u8   source;   //   0
    Source();
};

// Return constant 1
// func:acr_dm.Source.source.N
int                  source_N(acr_dm::Source& parent) __attribute__((__warn_unused_result__, nothrow, pure));
// Access value
// func:acr_dm.Source.source.qFind
u8&                  source_qFind(acr_dm::Source& parent, int) __attribute__((__warn_unused_result__, nothrow));
// Get max # of bits in the bitset
// Return max. number of bits supported by array
// func:acr_dm.Source.source.NBits
int                  source_Nbits(acr_dm::Source& parent) __attribute__((__warn_unused_result__, nothrow));
// Retrieve value of bit #BIT_IDX in bit set. No bounds checking
// func:acr_dm.Source.source.qGetBit
bool                 source_qGetBit(acr_dm::Source& parent, u32 bit_idx) __attribute__((__warn_unused_result__, nothrow));
// Retrieve value of bit #BIT_IDX in bit set. If bit index is out of bounds, return 0.
// func:acr_dm.Source.source.GetBit
bool                 source_GetBit(acr_dm::Source& parent, u32 bit_idx) __attribute__((__warn_unused_result__, nothrow));
// Check if all the bits in the bitset are equal to zero
// func:acr_dm.Source.source.BitsEmptyQ
bool                 source_BitsEmptyQ(acr_dm::Source& parent) __attribute__((__warn_unused_result__, nothrow));
// func:acr_dm.Source.source.Sum1s
u64                  source_Sum1s(acr_dm::Source& parent) __attribute__((__warn_unused_result__, nothrow));
// Clear bit # BIT_IDX in bit set. No bounds checking
// func:acr_dm.Source.source.qClearBit
void                 source_qClearBit(acr_dm::Source& parent, u32 bit_idx) __attribute__((nothrow));
// Clear bit # BIT_IDX in bit set. If bit index is out of bounds, do nothing
// func:acr_dm.Source.source.ClearBit
void                 source_ClearBit(acr_dm::Source& parent, u32 bit_idx) __attribute__((nothrow));
// Set bit # BIT_IDX in bit set. No bounds checking
// func:acr_dm.Source.source.qSetBit
void                 source_qSetBit(acr_dm::Source& parent, u32 bit_idx) __attribute__((nothrow));
// Set bit # BIT_IDX in bit set. If bit index is out of bounds, do nothing.
// func:acr_dm.Source.source.SetBit
void                 source_SetBit(acr_dm::Source& parent, u32 bit_idx) __attribute__((nothrow));
// Set bit # BIT_IDX in bit set. No bounds checking
// func:acr_dm.Source.source.qSetBitVal
void                 source_qSetBitVal(acr_dm::Source& parent, u32 bit_idx, bool val) __attribute__((nothrow));
// Or bit # BIT_IDX in bit set. No bounds checking
// func:acr_dm.Source.source.qOrBitVal
void                 source_qOrBitVal(acr_dm::Source& parent, u32 bit_idx, bool val) __attribute__((nothrow));
// Set all bits of array to zero.
// Note: this does not change what NBits will return.
// func:acr_dm.Source.source.ClearBitsAll
void                 source_ClearBitsAll(acr_dm::Source& parent) __attribute__((nothrow));
// Zero in PARENT any bits that are set in RHS.
// func:acr_dm.Source.source.ClearBits
void                 source_ClearBits(acr_dm::Source& parent, acr_dm::Source &rhs) __attribute__((nothrow));
// Set PARENT to union of two bitsets.
// (This function is not named Set.. to avoid triple entendre).
// func:acr_dm.Source.source.OrBits
void                 source_OrBits(acr_dm::Source& parent, acr_dm::Source &rhs) __attribute__((nothrow));
// Return smallest number N such that indexes of all 1 bits are below N
// func:acr_dm.Source.source.Sup
i32                  source_Sup(acr_dm::Source& parent) __attribute__((__warn_unused_result__, nothrow));

// proceed to next item
// func:acr_dm.Source.source_bitcurs.Next
void                 Source_source_bitcurs_Next(Source_source_bitcurs &curs);
// func:acr_dm.Source.source_bitcurs.Reset
void                 Source_source_bitcurs_Reset(Source_source_bitcurs &curs, acr_dm::Source &parent) __attribute__((nothrow));
// cursor points to valid item
// func:acr_dm.Source.source_bitcurs.ValidQ
bool                 Source_source_bitcurs_ValidQ(Source_source_bitcurs &curs) __attribute__((nothrow));
// item access
// func:acr_dm.Source.source_bitcurs.Access
int&                 Source_source_bitcurs_Access(Source_source_bitcurs &curs) __attribute__((nothrow));
// Set all fields to initial values.
// func:acr_dm.Source..Init
void                 Source_Init(acr_dm::Source& parent);

// --- acr_dm.FTuple
// create: acr_dm.FDb.tuple (Lary)
// global access: ind_tuple (Thash)
// global access: bh_tuple (Bheap)
// access: acr_dm.FAttr.p_tuple (Upptr)
struct FTuple { // acr_dm.FTuple
    acr_dm::FTuple*   ind_tuple_next;   // hash next
    i32               bh_tuple_idx;     // index in heap; -1 means not-in-heap
    algo::cstring     key;              //
    acr_dm::Rowid     rowid;            //
    acr_dm::FAttr*    zs_attr_head;     // zero-terminated singly linked list
    i32               zs_attr_n;        // zero-terminated singly linked list
    acr_dm::FAttr*    zs_attr_tail;     // pointer to last element
    acr_dm::Source    source;           //
private:
    friend acr_dm::FTuple&      tuple_Alloc() __attribute__((__warn_unused_result__, nothrow));
    friend acr_dm::FTuple*      tuple_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
    friend void                 tuple_RemoveAll() __attribute__((nothrow));
    friend void                 tuple_RemoveLast() __attribute__((nothrow));
    FTuple();
    ~FTuple();
    FTuple(const FTuple&){ /*disallow copy constructor */}
    void operator =(const FTuple&){ /*disallow direct assignment */}
};

// Compare two fields. Comparison is anti-symmetric: if a>b, then !(b>a).
// func:acr_dm.FTuple.rowid.Lt
bool                 rowid_Lt(acr_dm::FTuple& tuple, acr_dm::FTuple &rhs) __attribute__((nothrow));
// Compare two fields.
// func:acr_dm.FTuple.rowid.Cmp
i32                  rowid_Cmp(acr_dm::FTuple& tuple, acr_dm::FTuple &rhs) __attribute__((nothrow));

// Return true if index is empty
// func:acr_dm.FTuple.zs_attr.EmptyQ
bool                 zs_attr_EmptyQ(acr_dm::FTuple& tuple) __attribute__((__warn_unused_result__, nothrow, pure));
// If index empty, return NULL. Otherwise return pointer to first element in index
// func:acr_dm.FTuple.zs_attr.First
acr_dm::FAttr*       zs_attr_First(acr_dm::FTuple& tuple) __attribute__((__warn_unused_result__, nothrow, pure));
// Return true if row is in the linked list, false otherwise
// func:acr_dm.FTuple.zs_attr.InLlistQ
bool                 zs_attr_InLlistQ(acr_dm::FAttr& row) __attribute__((__warn_unused_result__, nothrow));
// Insert row into linked list. If row is already in linked list, do nothing.
// func:acr_dm.FTuple.zs_attr.Insert
void                 zs_attr_Insert(acr_dm::FTuple& tuple, acr_dm::FAttr& row) __attribute__((nothrow));
// If index empty, return NULL. Otherwise return pointer to last element in index
// func:acr_dm.FTuple.zs_attr.Last
acr_dm::FAttr*       zs_attr_Last(acr_dm::FTuple& tuple) __attribute__((__warn_unused_result__, nothrow, pure));
// Return number of items in the linked list
// func:acr_dm.FTuple.zs_attr.N
i32                  zs_attr_N(const acr_dm::FTuple& tuple) __attribute__((__warn_unused_result__, nothrow, pure));
// Return pointer to next element in the list
// func:acr_dm.FTuple.zs_attr.Next
acr_dm::FAttr*       zs_attr_Next(acr_dm::FAttr &row) __attribute__((__warn_unused_result__, nothrow));
// Remove element from index. If element is not in index, do nothing.
// Since the list is singly-linked, use linear search to locate the element.
// func:acr_dm.FTuple.zs_attr.Remove
void                 zs_attr_Remove(acr_dm::FTuple& tuple, acr_dm::FAttr& row) __attribute__((nothrow));
// Empty the index. (The rows are not deleted)
// func:acr_dm.FTuple.zs_attr.RemoveAll
void                 zs_attr_RemoveAll(acr_dm::FTuple& tuple) __attribute__((nothrow));
// If linked list is empty, return NULL. Otherwise unlink and return pointer to first element.
// func:acr_dm.FTuple.zs_attr.RemoveFirst
acr_dm::FAttr*       zs_attr_RemoveFirst(acr_dm::FTuple& tuple) __attribute__((nothrow));
// Return reference to last element in the index. No bounds checking.
// func:acr_dm.FTuple.zs_attr.qLast
acr_dm::FAttr&       zs_attr_qLast(acr_dm::FTuple& tuple) __attribute__((__warn_unused_result__, nothrow));

// Set all fields to initial values.
// func:acr_dm.FTuple..Init
void                 FTuple_Init(acr_dm::FTuple& tuple);
// cursor points to valid item
// func:acr_dm.FTuple.zs_attr_curs.Reset
void                 tuple_zs_attr_curs_Reset(tuple_zs_attr_curs &curs, acr_dm::FTuple &parent) __attribute__((nothrow));
// cursor points to valid item
// func:acr_dm.FTuple.zs_attr_curs.ValidQ
bool                 tuple_zs_attr_curs_ValidQ(tuple_zs_attr_curs &curs) __attribute__((nothrow));
// proceed to next item
// func:acr_dm.FTuple.zs_attr_curs.Next
void                 tuple_zs_attr_curs_Next(tuple_zs_attr_curs &curs) __attribute__((nothrow));
// item access
// func:acr_dm.FTuple.zs_attr_curs.Access
acr_dm::FAttr&       tuple_zs_attr_curs_Access(tuple_zs_attr_curs &curs) __attribute__((nothrow));
// func:acr_dm.FTuple..Uninit
void                 FTuple_Uninit(acr_dm::FTuple& tuple) __attribute__((nothrow));

// --- acr_dm.FValue
// create: acr_dm.FDb.value (Lary)
// access: acr_dm.FAttr.zs_value (Llist)
struct FValue { // acr_dm.FValue
    acr_dm::FValue*   zs_value_next;   // zslist link; -1 means not-in-list
    algo::cstring     value;           //
    acr_dm::FAttr*    p_attr;          // reference to parent row
    acr_dm::Source    source;          //
private:
    friend acr_dm::FValue&      value_Alloc() __attribute__((__warn_unused_result__, nothrow));
    friend acr_dm::FValue*      value_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
    friend void                 value_RemoveAll() __attribute__((nothrow));
    friend void                 value_RemoveLast() __attribute__((nothrow));
    FValue();
    ~FValue();
    FValue(const FValue&){ /*disallow copy constructor */}
    void operator =(const FValue&){ /*disallow direct assignment */}
};

// Set all fields to initial values.
// func:acr_dm.FValue..Init
void                 FValue_Init(acr_dm::FValue& value);
// func:acr_dm.FValue..Uninit
void                 FValue_Uninit(acr_dm::FValue& value) __attribute__((nothrow));

// --- acr_dm.FieldId
#pragma pack(push,1)
struct FieldId { // acr_dm.FieldId: Field read helper
    i32   value;   //   -1
    inline operator acr_dm_FieldIdEnum() const;
    explicit FieldId(i32                            in_value);
    FieldId(acr_dm_FieldIdEnum arg);
    FieldId();
};
#pragma pack(pop)

// Get value of field as enum type
// func:acr_dm.FieldId.value.GetEnum
acr_dm_FieldIdEnum   value_GetEnum(const acr_dm::FieldId& parent) __attribute__((nothrow));
// Set value of field from enum type.
// func:acr_dm.FieldId.value.SetEnum
void                 value_SetEnum(acr_dm::FieldId& parent, acr_dm_FieldIdEnum rhs) __attribute__((nothrow));
// Convert numeric value of field to one of predefined string constants.
// If string is found, return a static C string. Otherwise, return NULL.
// func:acr_dm.FieldId.value.ToCstr
const char*          value_ToCstr(const acr_dm::FieldId& parent) __attribute__((nothrow));
// Convert value to a string. First, attempt conversion to a known string.
// If no string matches, print value as a numeric value.
// func:acr_dm.FieldId.value.Print
void                 value_Print(const acr_dm::FieldId& parent, algo::cstring &lhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, do not modify field and return false.
// In case of success, return true
// func:acr_dm.FieldId.value.SetStrptrMaybe
bool                 value_SetStrptrMaybe(acr_dm::FieldId& parent, algo::strptr rhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, set numeric value to DFLT
// func:acr_dm.FieldId.value.SetStrptr
void                 value_SetStrptr(acr_dm::FieldId& parent, algo::strptr rhs, acr_dm_FieldIdEnum dflt) __attribute__((nothrow));
// Convert string to field. Return success value
// func:acr_dm.FieldId.value.ReadStrptrMaybe
bool                 value_ReadStrptrMaybe(acr_dm::FieldId& parent, algo::strptr rhs) __attribute__((nothrow));

// Read fields of acr_dm::FieldId from an ascii string.
// The format of the string is the format of the acr_dm::FieldId's only field
// func:acr_dm.FieldId..ReadStrptrMaybe
bool                 FieldId_ReadStrptrMaybe(acr_dm::FieldId &parent, algo::strptr in_str) __attribute__((nothrow));
// Set all fields to initial values.
// func:acr_dm.FieldId..Init
void                 FieldId_Init(acr_dm::FieldId& parent);
// print string representation of ROW to string STR
// cfmt:acr_dm.FieldId.String  printfmt:Raw
// func:acr_dm.FieldId..Print
void                 FieldId_Print(acr_dm::FieldId& row, algo::cstring& str) __attribute__((nothrow));
} // gen:ns_print_struct
namespace acr_dm { // gen:ns_curstext

struct attr_zs_value_curs {// fcurs:acr_dm.FAttr.zs_value/curs
    typedef acr_dm::FValue ChildType;
    acr_dm::FValue* row;
    attr_zs_value_curs() {
        row = NULL;
    }
};


struct _db_tuple_curs {// cursor
    typedef acr_dm::FTuple ChildType;
    acr_dm::FDb *parent;
    i64 index;
    _db_tuple_curs(){ parent=NULL; index=0; }
};


struct _db_attr_curs {// cursor
    typedef acr_dm::FAttr ChildType;
    acr_dm::FDb *parent;
    i64 index;
    _db_attr_curs(){ parent=NULL; index=0; }
};


struct _db_value_curs {// cursor
    typedef acr_dm::FValue ChildType;
    acr_dm::FDb *parent;
    i64 index;
    _db_value_curs(){ parent=NULL; index=0; }
};

// Non-destructive heap cursor, returns heap elements in sorted order.
// A running front of potential smallest entries is kept in the helper heap (curs.temp_%)
struct _db_bh_tuple_curs {
    typedef acr_dm::FTuple ChildType;
    acr_dm::FDb      *parent;        // parent
    acr_dm::FTuple*     *temp_elems;    // helper heap
    int            temp_n;        // number of elements heaped in the helper heap
    int            temp_max;      // max number of elements possible in the helper heap
    _db_bh_tuple_curs() : parent(NULL), temp_elems(NULL), temp_n(0), temp_max(0) {}
    ~_db_bh_tuple_curs();
};


struct Source_source_bitcurs {// cursor
    typedef int& ChildType;
    u8* elems;
    int n_elems;
    int bit;
    Source_source_bitcurs() : elems(0), n_elems(0), bit(0) {}
};


struct tuple_zs_attr_curs {// fcurs:acr_dm.FTuple.zs_attr/curs
    typedef acr_dm::FAttr ChildType;
    acr_dm::FAttr* row;
    tuple_zs_attr_curs() {
        row = NULL;
    }
};

} // gen:ns_curstext
namespace acr_dm { // gen:ns_func
} // gen:ns_func
// func:acr_dm...main
int                  main(int argc, char **argv);
#if defined(WIN32)
// func:acr_dm...WinMain
int WINAPI           WinMain(HINSTANCE,HINSTANCE,LPSTR,int);
#endif
// gen:ns_operators
namespace algo {
inline algo::cstring &operator <<(algo::cstring &str, const acr_dm::trace &row);// cfmt:acr_dm.trace.String
inline algo::cstring &operator <<(algo::cstring &str, const acr_dm::Rowid &row);// cfmt:acr_dm.Rowid.String
inline algo::cstring &operator <<(algo::cstring &str, const acr_dm::FieldId &row);// cfmt:acr_dm.FieldId.String
}
