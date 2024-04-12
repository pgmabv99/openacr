//
// include/gen/orgfile_gen.h
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
#include "include/gen/command_gen.h"
#include "include/gen/algo_gen.h"
#include "include/gen/dev_gen.h"
//#pragma endinclude
// gen:ns_enums

// --- orgfile_FieldIdEnum

enum orgfile_FieldIdEnum {            // orgfile.FieldId.value
     orgfile_FieldId_original    = 0
    ,orgfile_FieldId_duplicate   = 1
    ,orgfile_FieldId_comment     = 2
    ,orgfile_FieldId_pathname    = 3
    ,orgfile_FieldId_tgtfile     = 4
    ,orgfile_FieldId_value       = 5
};

enum { orgfile_FieldIdEnum_N = 6 };


// --- orgfile_TableIdEnum

enum orgfile_TableIdEnum {               // orgfile.TableId.value
     orgfile_TableId_dev_Timefmt   = 0   // dev.Timefmt -> orgfile.FTimefmt
    ,orgfile_TableId_dev_timefmt   = 0   // dev.timefmt -> orgfile.FTimefmt
};

enum { orgfile_TableIdEnum_N = 2 };

namespace orgfile { // gen:ns_pkeytypedef
    typedef algo::Smallstr40 FFilehashPkey;
} // gen:ns_pkeytypedef
namespace orgfile { // gen:ns_field
extern const char *orgfile_help;
} // gen:ns_field
// gen:ns_fwddecl2
namespace orgfile { struct FFilehash; }
namespace orgfile { struct _db_filehash_curs; }
namespace orgfile { struct _db_timefmt_curs; }
namespace orgfile { struct filehash_c_filename_curs; }
namespace orgfile { struct trace; }
namespace orgfile { struct FDb; }
namespace orgfile { struct FFilename; }
namespace orgfile { struct FTimefmt; }
namespace orgfile { struct FieldId; }
namespace orgfile { struct TableId; }
namespace orgfile { struct dedup; }
namespace orgfile { struct move; }
namespace orgfile { extern struct orgfile::FDb _db; }
namespace orgfile { // gen:ns_print_struct

// --- orgfile.trace
#pragma pack(push,1)
struct trace { // orgfile.trace
    trace();
};
#pragma pack(pop)

// print string representation of ROW to string STR
// cfmt:orgfile.trace.String  printfmt:Tuple
// func:orgfile.trace..Print
void                 trace_Print(orgfile::trace& row, algo::cstring& str) __attribute__((nothrow));

// --- orgfile.FDb
// create: orgfile.FDb._db (Global)
struct FDb { // orgfile.FDb: In-memory database for orgfile
    command::orgfile       cmdline;                      //
    u64                    filename_blocksize;           // # bytes per block
    orgfile::FFilename*    filename_free;                //
    orgfile::FFilename**   ind_filename_buckets_elems;   // pointer to bucket array
    i32                    ind_filename_buckets_n;       // number of elements in bucket array
    i32                    ind_filename_n;               // number of elements in the hash table
    orgfile::FFilehash*    filehash_lary[32];            // level array
    i32                    filehash_n;                   // number of elements in array
    orgfile::FFilehash**   ind_filehash_buckets_elems;   // pointer to bucket array
    i32                    ind_filehash_buckets_n;       // number of elements in bucket array
    i32                    ind_filehash_n;               // number of elements in the hash table
    orgfile::FTimefmt*     timefmt_lary[32];             // level array
    i32                    timefmt_n;                    // number of elements in array
    orgfile::trace         trace;                        //
};

// Read argc,argv directly into the fields of the command line(s)
// The following fields are updated:
//     orgfile.FDb.cmdline
//     algo_lib.FDb.cmdline
// func:orgfile.FDb._db.ReadArgv
void                 ReadArgv() __attribute__((nothrow));
// Main loop.
// func:orgfile.FDb._db.MainLoop
void                 MainLoop();
// Main step
// func:orgfile.FDb._db.Step
void                 Step();
// Main function
// func:orgfile.FDb._db.Main
// this function is 'extrn' and implemented by user
void                 Main();
// func:orgfile.FDb._db.StaticCheck
void                 StaticCheck();
// Parse strptr into known type and add to database.
// Return value is true unless an error occurs. If return value is false, algo_lib::_db.errtext has error text
// func:orgfile.FDb._db.InsertStrptrMaybe
bool                 InsertStrptrMaybe(algo::strptr str);
// Load all finputs from given directory.
// func:orgfile.FDb._db.LoadTuplesMaybe
bool                 LoadTuplesMaybe(algo::strptr root, bool recursive) __attribute__((nothrow));
// Load all finputs from given file.
// Read tuples from file FNAME into this namespace's in-memory database.
// If RECURSIVE is TRUE, then also load these tuples into any parent namespaces
// It a file referred to by FNAME is missing, no error is reported (it's considered an empty set).
// Function returns TRUE if all records were parsed and inserted without error.
// If the function returns FALSE, use algo_lib::DetachBadTags() for error description
// func:orgfile.FDb._db.LoadTuplesFile
bool                 LoadTuplesFile(algo::strptr fname, bool recursive) __attribute__((nothrow));
// Load all finputs from given file descriptor.
// func:orgfile.FDb._db.LoadTuplesFd
bool                 LoadTuplesFd(algo::Fildes fd, algo::strptr fname, bool recursive) __attribute__((nothrow));
// Load specified ssimfile.
// func:orgfile.FDb._db.LoadSsimfileMaybe
bool                 LoadSsimfileMaybe(algo::strptr fname, bool recursive) __attribute__((nothrow));
// Calls Step function of dependencies
// func:orgfile.FDb._db.Steps
void                 Steps();
// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Caller must Delete or Unref such row.
// func:orgfile.FDb._db.XrefMaybe
bool                 _db_XrefMaybe();

// Allocate memory for new default row.
// If out of memory, process is killed.
// func:orgfile.FDb.filename.Alloc
orgfile::FFilename&  filename_Alloc() __attribute__((__warn_unused_result__, nothrow));
// Allocate memory for new element. If out of memory, return NULL.
// func:orgfile.FDb.filename.AllocMaybe
orgfile::FFilename*  filename_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
// Remove row from all global and cross indices, then deallocate row
// func:orgfile.FDb.filename.Delete
void                 filename_Delete(orgfile::FFilename &row) __attribute__((nothrow));
// Allocate space for one element
// If no memory available, return NULL.
// func:orgfile.FDb.filename.AllocMem
void*                filename_AllocMem() __attribute__((__warn_unused_result__, nothrow));
// Remove mem from all global and cross indices, then deallocate mem
// func:orgfile.FDb.filename.FreeMem
void                 filename_FreeMem(orgfile::FFilename &row) __attribute__((nothrow));
// Preallocate memory for N more elements
// Return number of elements actually reserved.
// func:orgfile.FDb.filename.Reserve
u64                  filename_Reserve(u64 n_elems) __attribute__((nothrow));
// Allocate block of given size, break up into small elements and append to free list.
// Return number of elements reserved.
// func:orgfile.FDb.filename.ReserveMem
u64                  filename_ReserveMem(u64 size) __attribute__((nothrow));
// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Caller must Delete or Unref such row.
// func:orgfile.FDb.filename.XrefMaybe
bool                 filename_XrefMaybe(orgfile::FFilename &row);

// Return true if hash is empty
// func:orgfile.FDb.ind_filename.EmptyQ
bool                 ind_filename_EmptyQ() __attribute__((nothrow));
// Find row by key. Return NULL if not found.
// func:orgfile.FDb.ind_filename.Find
orgfile::FFilename*  ind_filename_Find(const algo::strptr& key) __attribute__((__warn_unused_result__, nothrow));
// Look up row by key and return reference. Throw exception if not found
// func:orgfile.FDb.ind_filename.FindX
orgfile::FFilename&  ind_filename_FindX(const algo::strptr& key);
// Return number of items in the hash
// func:orgfile.FDb.ind_filename.N
i32                  ind_filename_N() __attribute__((__warn_unused_result__, nothrow, pure));
// Insert row into hash table. Return true if row is reachable through the hash after the function completes.
// func:orgfile.FDb.ind_filename.InsertMaybe
bool                 ind_filename_InsertMaybe(orgfile::FFilename& row) __attribute__((nothrow));
// Remove reference to element from hash index. If element is not in hash, do nothing
// func:orgfile.FDb.ind_filename.Remove
void                 ind_filename_Remove(orgfile::FFilename& row) __attribute__((nothrow));
// Reserve enough room in the hash for N more elements. Return success code.
// func:orgfile.FDb.ind_filename.Reserve
void                 ind_filename_Reserve(int n) __attribute__((nothrow));

// Allocate memory for new default row.
// If out of memory, process is killed.
// func:orgfile.FDb.filehash.Alloc
orgfile::FFilehash&  filehash_Alloc() __attribute__((__warn_unused_result__, nothrow));
// Allocate memory for new element. If out of memory, return NULL.
// func:orgfile.FDb.filehash.AllocMaybe
orgfile::FFilehash*  filehash_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
// Allocate space for one element. If no memory available, return NULL.
// func:orgfile.FDb.filehash.AllocMem
void*                filehash_AllocMem() __attribute__((__warn_unused_result__, nothrow));
// Return true if index is empty
// func:orgfile.FDb.filehash.EmptyQ
bool                 filehash_EmptyQ() __attribute__((nothrow, pure));
// Look up row by row id. Return NULL if out of range
// func:orgfile.FDb.filehash.Find
orgfile::FFilehash*  filehash_Find(u64 t) __attribute__((__warn_unused_result__, nothrow, pure));
// Return pointer to last element of array, or NULL if array is empty
// func:orgfile.FDb.filehash.Last
orgfile::FFilehash*  filehash_Last() __attribute__((nothrow, pure));
// Return number of items in the pool
// func:orgfile.FDb.filehash.N
i32                  filehash_N() __attribute__((__warn_unused_result__, nothrow, pure));
// Remove all elements from Lary
// func:orgfile.FDb.filehash.RemoveAll
void                 filehash_RemoveAll() __attribute__((nothrow));
// Delete last element of array. Do nothing if array is empty.
// func:orgfile.FDb.filehash.RemoveLast
void                 filehash_RemoveLast() __attribute__((nothrow));
// 'quick' Access row by row id. No bounds checking.
// func:orgfile.FDb.filehash.qFind
orgfile::FFilehash&  filehash_qFind(u64 t) __attribute__((nothrow, pure));
// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Caller must Delete or Unref such row.
// func:orgfile.FDb.filehash.XrefMaybe
bool                 filehash_XrefMaybe(orgfile::FFilehash &row);

// Return true if hash is empty
// func:orgfile.FDb.ind_filehash.EmptyQ
bool                 ind_filehash_EmptyQ() __attribute__((nothrow));
// Find row by key. Return NULL if not found.
// func:orgfile.FDb.ind_filehash.Find
orgfile::FFilehash*  ind_filehash_Find(const algo::strptr& key) __attribute__((__warn_unused_result__, nothrow));
// Look up row by key and return reference. Throw exception if not found
// func:orgfile.FDb.ind_filehash.FindX
orgfile::FFilehash&  ind_filehash_FindX(const algo::strptr& key);
// Find row by key. If not found, create and x-reference a new row with with this key.
// func:orgfile.FDb.ind_filehash.GetOrCreate
orgfile::FFilehash&  ind_filehash_GetOrCreate(const algo::strptr& key) __attribute__((nothrow));
// Return number of items in the hash
// func:orgfile.FDb.ind_filehash.N
i32                  ind_filehash_N() __attribute__((__warn_unused_result__, nothrow, pure));
// Insert row into hash table. Return true if row is reachable through the hash after the function completes.
// func:orgfile.FDb.ind_filehash.InsertMaybe
bool                 ind_filehash_InsertMaybe(orgfile::FFilehash& row) __attribute__((nothrow));
// Remove reference to element from hash index. If element is not in hash, do nothing
// func:orgfile.FDb.ind_filehash.Remove
void                 ind_filehash_Remove(orgfile::FFilehash& row) __attribute__((nothrow));
// Reserve enough room in the hash for N more elements. Return success code.
// func:orgfile.FDb.ind_filehash.Reserve
void                 ind_filehash_Reserve(int n) __attribute__((nothrow));

// Allocate memory for new default row.
// If out of memory, process is killed.
// func:orgfile.FDb.timefmt.Alloc
orgfile::FTimefmt&   timefmt_Alloc() __attribute__((__warn_unused_result__, nothrow));
// Allocate memory for new element. If out of memory, return NULL.
// func:orgfile.FDb.timefmt.AllocMaybe
orgfile::FTimefmt*   timefmt_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
// Create new row from struct.
// Return pointer to new element, or NULL if insertion failed (due to out-of-memory, duplicate key, etc)
// func:orgfile.FDb.timefmt.InsertMaybe
orgfile::FTimefmt*   timefmt_InsertMaybe(const dev::Timefmt &value) __attribute__((nothrow));
// Allocate space for one element. If no memory available, return NULL.
// func:orgfile.FDb.timefmt.AllocMem
void*                timefmt_AllocMem() __attribute__((__warn_unused_result__, nothrow));
// Return true if index is empty
// func:orgfile.FDb.timefmt.EmptyQ
bool                 timefmt_EmptyQ() __attribute__((nothrow, pure));
// Look up row by row id. Return NULL if out of range
// func:orgfile.FDb.timefmt.Find
orgfile::FTimefmt*   timefmt_Find(u64 t) __attribute__((__warn_unused_result__, nothrow, pure));
// Return pointer to last element of array, or NULL if array is empty
// func:orgfile.FDb.timefmt.Last
orgfile::FTimefmt*   timefmt_Last() __attribute__((nothrow, pure));
// Return number of items in the pool
// func:orgfile.FDb.timefmt.N
i32                  timefmt_N() __attribute__((__warn_unused_result__, nothrow, pure));
// Remove all elements from Lary
// func:orgfile.FDb.timefmt.RemoveAll
void                 timefmt_RemoveAll() __attribute__((nothrow));
// Delete last element of array. Do nothing if array is empty.
// func:orgfile.FDb.timefmt.RemoveLast
void                 timefmt_RemoveLast() __attribute__((nothrow));
// 'quick' Access row by row id. No bounds checking.
// func:orgfile.FDb.timefmt.qFind
orgfile::FTimefmt&   timefmt_qFind(u64 t) __attribute__((nothrow, pure));
// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Caller must Delete or Unref such row.
// func:orgfile.FDb.timefmt.XrefMaybe
bool                 timefmt_XrefMaybe(orgfile::FTimefmt &row);

// cursor points to valid item
// func:orgfile.FDb.filehash_curs.Reset
void                 _db_filehash_curs_Reset(_db_filehash_curs &curs, orgfile::FDb &parent) __attribute__((nothrow));
// cursor points to valid item
// func:orgfile.FDb.filehash_curs.ValidQ
bool                 _db_filehash_curs_ValidQ(_db_filehash_curs &curs) __attribute__((nothrow));
// proceed to next item
// func:orgfile.FDb.filehash_curs.Next
void                 _db_filehash_curs_Next(_db_filehash_curs &curs) __attribute__((nothrow));
// item access
// func:orgfile.FDb.filehash_curs.Access
orgfile::FFilehash&  _db_filehash_curs_Access(_db_filehash_curs &curs) __attribute__((nothrow));
// cursor points to valid item
// func:orgfile.FDb.timefmt_curs.Reset
void                 _db_timefmt_curs_Reset(_db_timefmt_curs &curs, orgfile::FDb &parent) __attribute__((nothrow));
// cursor points to valid item
// func:orgfile.FDb.timefmt_curs.ValidQ
bool                 _db_timefmt_curs_ValidQ(_db_timefmt_curs &curs) __attribute__((nothrow));
// proceed to next item
// func:orgfile.FDb.timefmt_curs.Next
void                 _db_timefmt_curs_Next(_db_timefmt_curs &curs) __attribute__((nothrow));
// item access
// func:orgfile.FDb.timefmt_curs.Access
orgfile::FTimefmt&   _db_timefmt_curs_Access(_db_timefmt_curs &curs) __attribute__((nothrow));
// Set all fields to initial values.
// func:orgfile.FDb..Init
void                 FDb_Init();
// func:orgfile.FDb..Uninit
void                 FDb_Uninit() __attribute__((nothrow));

// --- orgfile.FFilehash
// create: orgfile.FDb.filehash (Lary)
// global access: ind_filehash (Thash)
// access: orgfile.FFilename.p_filehash (Upptr)
struct FFilehash { // orgfile.FFilehash
    orgfile::FFilehash*    ind_filehash_next;   // hash next
    algo::Smallstr40       filehash;            //
    orgfile::FFilename**   c_filename_elems;    // array of pointers
    u32                    c_filename_n;        // array of pointers
    u32                    c_filename_max;      // capacity of allocated array
private:
    friend orgfile::FFilehash&  filehash_Alloc() __attribute__((__warn_unused_result__, nothrow));
    friend orgfile::FFilehash*  filehash_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
    friend void                 filehash_RemoveAll() __attribute__((nothrow));
    friend void                 filehash_RemoveLast() __attribute__((nothrow));
    FFilehash();
    ~FFilehash();
    FFilehash(const FFilehash&){ /*disallow copy constructor */}
    void operator =(const FFilehash&){ /*disallow direct assignment */}
};

// Return true if index is empty
// func:orgfile.FFilehash.c_filename.EmptyQ
bool                 c_filename_EmptyQ(orgfile::FFilehash& filehash) __attribute__((nothrow));
// Look up row by row id. Return NULL if out of range
// func:orgfile.FFilehash.c_filename.Find
orgfile::FFilename*  c_filename_Find(orgfile::FFilehash& filehash, u32 t) __attribute__((__warn_unused_result__, nothrow));
// Return array of pointers
// func:orgfile.FFilehash.c_filename.Getary
algo::aryptr<orgfile::FFilename*> c_filename_Getary(orgfile::FFilehash& filehash) __attribute__((nothrow));
// Insert pointer to row into array. Row must not already be in array.
// If pointer is already in the array, it may be inserted twice.
// func:orgfile.FFilehash.c_filename.Insert
void                 c_filename_Insert(orgfile::FFilehash& filehash, orgfile::FFilename& row) __attribute__((nothrow));
// Insert pointer to row in array.
// If row is already in the array, do nothing.
// Return value: whether element was inserted into array.
// func:orgfile.FFilehash.c_filename.InsertMaybe
bool                 c_filename_InsertMaybe(orgfile::FFilehash& filehash, orgfile::FFilename& row) __attribute__((nothrow));
// Return number of items in the pointer array
// func:orgfile.FFilehash.c_filename.N
i32                  c_filename_N(const orgfile::FFilehash& filehash) __attribute__((__warn_unused_result__, nothrow, pure));
// Find element using linear scan. If element is in array, remove, otherwise do nothing
// func:orgfile.FFilehash.c_filename.Remove
void                 c_filename_Remove(orgfile::FFilehash& filehash, orgfile::FFilename& row) __attribute__((nothrow));
// Empty the index. (The rows are not deleted)
// func:orgfile.FFilehash.c_filename.RemoveAll
void                 c_filename_RemoveAll(orgfile::FFilehash& filehash) __attribute__((nothrow));
// Reserve space in index for N more elements;
// func:orgfile.FFilehash.c_filename.Reserve
void                 c_filename_Reserve(orgfile::FFilehash& filehash, u32 n) __attribute__((nothrow));
// Return reference without bounds checking
// func:orgfile.FFilehash.c_filename.qFind
orgfile::FFilename&  c_filename_qFind(orgfile::FFilehash& filehash, u32 idx) __attribute__((nothrow));
// True if row is in any ptrary instance
// func:orgfile.FFilehash.c_filename.InAryQ
bool                 filehash_c_filename_InAryQ(orgfile::FFilename& row) __attribute__((nothrow));
// Reference to last element without bounds checking
// func:orgfile.FFilehash.c_filename.qLast
orgfile::FFilename&  c_filename_qLast(orgfile::FFilehash& filehash) __attribute__((nothrow));

// Set all fields to initial values.
// func:orgfile.FFilehash..Init
void                 FFilehash_Init(orgfile::FFilehash& filehash);
// func:orgfile.FFilehash.c_filename_curs.Reset
void                 filehash_c_filename_curs_Reset(filehash_c_filename_curs &curs, orgfile::FFilehash &parent) __attribute__((nothrow));
// cursor points to valid item
// func:orgfile.FFilehash.c_filename_curs.ValidQ
bool                 filehash_c_filename_curs_ValidQ(filehash_c_filename_curs &curs) __attribute__((nothrow));
// proceed to next item
// func:orgfile.FFilehash.c_filename_curs.Next
void                 filehash_c_filename_curs_Next(filehash_c_filename_curs &curs) __attribute__((nothrow));
// item access
// func:orgfile.FFilehash.c_filename_curs.Access
orgfile::FFilename&  filehash_c_filename_curs_Access(filehash_c_filename_curs &curs) __attribute__((nothrow));
// func:orgfile.FFilehash..Uninit
void                 FFilehash_Uninit(orgfile::FFilehash& filehash) __attribute__((nothrow));

// --- orgfile.FFilename
// create: orgfile.FDb.filename (Tpool)
// global access: ind_filename (Thash)
// access: orgfile.FFilehash.c_filename (Ptrary)
struct FFilename { // orgfile.FFilename
    orgfile::FFilename*   filename_next;                // Pointer to next free element int tpool
    orgfile::FFilename*   ind_filename_next;            // hash next
    algo::cstring         filename;                     //
    algo::Smallstr40      filehash;                     //
    orgfile::FFilehash*   p_filehash;                   // reference to parent row
    bool                  filehash_c_filename_in_ary;   //   false  membership flag
private:
    friend orgfile::FFilename&  filename_Alloc() __attribute__((__warn_unused_result__, nothrow));
    friend orgfile::FFilename*  filename_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
    friend void                 filename_Delete(orgfile::FFilename &row) __attribute__((nothrow));
    FFilename();
    ~FFilename();
    FFilename(const FFilename&){ /*disallow copy constructor */}
    void operator =(const FFilename&){ /*disallow direct assignment */}
};

// Set all fields to initial values.
// func:orgfile.FFilename..Init
void                 FFilename_Init(orgfile::FFilename& filename);
// func:orgfile.FFilename..Uninit
void                 FFilename_Uninit(orgfile::FFilename& filename) __attribute__((nothrow));

// --- orgfile.FTimefmt
// create: orgfile.FDb.timefmt (Lary)
struct FTimefmt { // orgfile.FTimefmt
    algo::Smallstr100   timefmt;   //
    bool                dirname;   //   false
    algo::Comment       comment;   //
private:
    friend orgfile::FTimefmt&   timefmt_Alloc() __attribute__((__warn_unused_result__, nothrow));
    friend orgfile::FTimefmt*   timefmt_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
    friend void                 timefmt_RemoveAll() __attribute__((nothrow));
    friend void                 timefmt_RemoveLast() __attribute__((nothrow));
    FTimefmt();
};

// Copy fields out of row
// func:orgfile.FTimefmt.base.CopyOut
void                 timefmt_CopyOut(orgfile::FTimefmt &row, dev::Timefmt &out) __attribute__((nothrow));
// Copy fields in to row
// func:orgfile.FTimefmt.base.CopyIn
void                 timefmt_CopyIn(orgfile::FTimefmt &row, dev::Timefmt &in) __attribute__((nothrow));

// Set all fields to initial values.
// func:orgfile.FTimefmt..Init
void                 FTimefmt_Init(orgfile::FTimefmt& timefmt);

// --- orgfile.FieldId
#pragma pack(push,1)
struct FieldId { // orgfile.FieldId: Field read helper
    i32   value;   //   -1
    inline operator orgfile_FieldIdEnum() const;
    explicit FieldId(i32                            in_value);
    FieldId(orgfile_FieldIdEnum arg);
    FieldId();
};
#pragma pack(pop)

// Get value of field as enum type
// func:orgfile.FieldId.value.GetEnum
orgfile_FieldIdEnum  value_GetEnum(const orgfile::FieldId& parent) __attribute__((nothrow));
// Set value of field from enum type.
// func:orgfile.FieldId.value.SetEnum
void                 value_SetEnum(orgfile::FieldId& parent, orgfile_FieldIdEnum rhs) __attribute__((nothrow));
// Convert numeric value of field to one of predefined string constants.
// If string is found, return a static C string. Otherwise, return NULL.
// func:orgfile.FieldId.value.ToCstr
const char*          value_ToCstr(const orgfile::FieldId& parent) __attribute__((nothrow));
// Convert value to a string. First, attempt conversion to a known string.
// If no string matches, print value as a numeric value.
// func:orgfile.FieldId.value.Print
void                 value_Print(const orgfile::FieldId& parent, algo::cstring &lhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, do not modify field and return false.
// In case of success, return true
// func:orgfile.FieldId.value.SetStrptrMaybe
bool                 value_SetStrptrMaybe(orgfile::FieldId& parent, algo::strptr rhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, set numeric value to DFLT
// func:orgfile.FieldId.value.SetStrptr
void                 value_SetStrptr(orgfile::FieldId& parent, algo::strptr rhs, orgfile_FieldIdEnum dflt) __attribute__((nothrow));
// Convert string to field. Return success value
// func:orgfile.FieldId.value.ReadStrptrMaybe
bool                 value_ReadStrptrMaybe(orgfile::FieldId& parent, algo::strptr rhs) __attribute__((nothrow));

// Read fields of orgfile::FieldId from an ascii string.
// The format of the string is the format of the orgfile::FieldId's only field
// func:orgfile.FieldId..ReadStrptrMaybe
bool                 FieldId_ReadStrptrMaybe(orgfile::FieldId &parent, algo::strptr in_str);
// Set all fields to initial values.
// func:orgfile.FieldId..Init
void                 FieldId_Init(orgfile::FieldId& parent);
// print string representation of ROW to string STR
// cfmt:orgfile.FieldId.String  printfmt:Raw
// func:orgfile.FieldId..Print
void                 FieldId_Print(orgfile::FieldId& row, algo::cstring& str) __attribute__((nothrow));

// --- orgfile.TableId
struct TableId { // orgfile.TableId: Index of table in this namespace
    i32   value;   //   -1  index of table
    inline operator orgfile_TableIdEnum() const;
    explicit TableId(i32                            in_value);
    TableId(orgfile_TableIdEnum arg);
    TableId();
};

// Get value of field as enum type
// func:orgfile.TableId.value.GetEnum
orgfile_TableIdEnum  value_GetEnum(const orgfile::TableId& parent) __attribute__((nothrow));
// Set value of field from enum type.
// func:orgfile.TableId.value.SetEnum
void                 value_SetEnum(orgfile::TableId& parent, orgfile_TableIdEnum rhs) __attribute__((nothrow));
// Convert numeric value of field to one of predefined string constants.
// If string is found, return a static C string. Otherwise, return NULL.
// func:orgfile.TableId.value.ToCstr
const char*          value_ToCstr(const orgfile::TableId& parent) __attribute__((nothrow));
// Convert value to a string. First, attempt conversion to a known string.
// If no string matches, print value as a numeric value.
// func:orgfile.TableId.value.Print
void                 value_Print(const orgfile::TableId& parent, algo::cstring &lhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, do not modify field and return false.
// In case of success, return true
// func:orgfile.TableId.value.SetStrptrMaybe
bool                 value_SetStrptrMaybe(orgfile::TableId& parent, algo::strptr rhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, set numeric value to DFLT
// func:orgfile.TableId.value.SetStrptr
void                 value_SetStrptr(orgfile::TableId& parent, algo::strptr rhs, orgfile_TableIdEnum dflt) __attribute__((nothrow));
// Convert string to field. Return success value
// func:orgfile.TableId.value.ReadStrptrMaybe
bool                 value_ReadStrptrMaybe(orgfile::TableId& parent, algo::strptr rhs) __attribute__((nothrow));

// Read fields of orgfile::TableId from an ascii string.
// The format of the string is the format of the orgfile::TableId's only field
// func:orgfile.TableId..ReadStrptrMaybe
bool                 TableId_ReadStrptrMaybe(orgfile::TableId &parent, algo::strptr in_str);
// Set all fields to initial values.
// func:orgfile.TableId..Init
void                 TableId_Init(orgfile::TableId& parent);
// print string representation of ROW to string STR
// cfmt:orgfile.TableId.String  printfmt:Raw
// func:orgfile.TableId..Print
void                 TableId_Print(orgfile::TableId& row, algo::cstring& str) __attribute__((nothrow));

// --- orgfile.dedup
struct dedup { // orgfile.dedup
    algo::cstring   original;    //
    algo::cstring   duplicate;   //
    algo::cstring   comment;     //
    dedup();
};

// func:orgfile.dedup..ReadFieldMaybe
bool                 dedup_ReadFieldMaybe(orgfile::dedup& parent, algo::strptr field, algo::strptr strval) __attribute__((nothrow));
// Read fields of orgfile::dedup from an ascii string.
// The format of the string is an ssim Tuple
// func:orgfile.dedup..ReadStrptrMaybe
bool                 dedup_ReadStrptrMaybe(orgfile::dedup &parent, algo::strptr in_str);
// print string representation of ROW to string STR
// cfmt:orgfile.dedup.String  printfmt:Tuple
// func:orgfile.dedup..Print
void                 dedup_Print(orgfile::dedup& row, algo::cstring& str) __attribute__((nothrow));

// --- orgfile.move
struct move { // orgfile.move
    algo::cstring   pathname;   //
    algo::cstring   tgtfile;    //
    algo::cstring   comment;    //
    move();
};

// func:orgfile.move..ReadFieldMaybe
bool                 move_ReadFieldMaybe(orgfile::move& parent, algo::strptr field, algo::strptr strval) __attribute__((nothrow));
// Read fields of orgfile::move from an ascii string.
// The format of the string is an ssim Tuple
// func:orgfile.move..ReadStrptrMaybe
bool                 move_ReadStrptrMaybe(orgfile::move &parent, algo::strptr in_str);
// print string representation of ROW to string STR
// cfmt:orgfile.move.String  printfmt:Tuple
// func:orgfile.move..Print
void                 move_Print(orgfile::move& row, algo::cstring& str) __attribute__((nothrow));
} // gen:ns_print_struct
namespace orgfile { // gen:ns_curstext

struct _db_filehash_curs {// cursor
    typedef orgfile::FFilehash ChildType;
    orgfile::FDb *parent;
    i64 index;
    _db_filehash_curs(){ parent=NULL; index=0; }
};


struct _db_timefmt_curs {// cursor
    typedef orgfile::FTimefmt ChildType;
    orgfile::FDb *parent;
    i64 index;
    _db_timefmt_curs(){ parent=NULL; index=0; }
};


struct filehash_c_filename_curs {// fcurs:orgfile.FFilehash.c_filename/curs
    typedef orgfile::FFilename ChildType;
    orgfile::FFilename** elems;
    u32 n_elems;
    u32 index;
    filehash_c_filename_curs() { elems=NULL; n_elems=0; index=0; }
};

} // gen:ns_curstext
namespace orgfile { // gen:ns_func
} // gen:ns_func
// func:orgfile...main
int                  main(int argc, char **argv);
#if defined(WIN32)
// func:orgfile...WinMain
int WINAPI           WinMain(HINSTANCE,HINSTANCE,LPSTR,int);
#endif
// gen:ns_operators
namespace algo {
inline algo::cstring &operator <<(algo::cstring &str, const orgfile::trace &row);// cfmt:orgfile.trace.String
inline algo::cstring &operator <<(algo::cstring &str, const orgfile::FieldId &row);// cfmt:orgfile.FieldId.String
inline algo::cstring &operator <<(algo::cstring &str, const orgfile::TableId &row);// cfmt:orgfile.TableId.String
inline algo::cstring &operator <<(algo::cstring &str, const orgfile::dedup &row);// cfmt:orgfile.dedup.String
inline algo::cstring &operator <<(algo::cstring &str, const orgfile::move &row);// cfmt:orgfile.move.String
}
