//
// include/gen/mdbg_gen.h
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
#include "include/gen/dev_gen.h"
#include "include/gen/algo_gen.h"
#include "include/gen/command_gen.h"
//#pragma endinclude
// gen:ns_enums

// --- mdbg_FieldIdEnum

enum mdbg_FieldIdEnum {        // mdbg.FieldId.value
     mdbg_FieldId_value   = 0
};

enum { mdbg_FieldIdEnum_N = 1 };


// --- mdbg_TableIdEnum

enum mdbg_TableIdEnum {                // mdbg.TableId.value
     mdbg_TableId_dev_Builddir   = 0   // dev.Builddir -> mdbg.FBuilddir
    ,mdbg_TableId_dev_builddir   = 0   // dev.builddir -> mdbg.FBuilddir
    ,mdbg_TableId_dev_Cfg        = 1   // dev.Cfg -> mdbg.FCfg
    ,mdbg_TableId_dev_cfg        = 1   // dev.cfg -> mdbg.FCfg
};

enum { mdbg_TableIdEnum_N = 4 };

namespace mdbg { // gen:ns_pkeytypedef
} // gen:ns_pkeytypedef
namespace mdbg { // gen:ns_field
struct lpool_Lpblock {
    lpool_Lpblock* next;
};
extern const char *mdbg_help;
} // gen:ns_field
// gen:ns_fwddecl2
namespace mdbg { struct cfg_c_builddir_curs; }
namespace mdbg { struct _db_cfg_curs; }
namespace mdbg { struct _db_builddir_curs; }
namespace mdbg { struct FBuilddir; }
namespace mdbg { struct FCfg; }
namespace mdbg { struct trace; }
namespace mdbg { struct FDb; }
namespace mdbg { struct FieldId; }
namespace mdbg { struct TableId; }
namespace mdbg { extern struct mdbg::FDb _db; }
namespace mdbg { // gen:ns_print_struct

// --- mdbg.FBuilddir
// create: mdbg.FDb.builddir (Lary)
// access: mdbg.FCfg.c_builddir (Ptrary)
struct FBuilddir { // mdbg.FBuilddir
    algo::Smallstr50   builddir;                // Primary key - uname.compiler.cfg-arch
    algo::Comment      comment;                 //
    bool               cfg_c_builddir_in_ary;   //   false  membership flag
private:
    friend mdbg::FBuilddir&     builddir_Alloc() __attribute__((__warn_unused_result__, nothrow));
    friend mdbg::FBuilddir*     builddir_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
    friend void                 builddir_RemoveAll() __attribute__((nothrow));
    friend void                 builddir_RemoveLast() __attribute__((nothrow));
    FBuilddir();
    ~FBuilddir();
    FBuilddir(const FBuilddir&){ /*disallow copy constructor */}
    void operator =(const FBuilddir&){ /*disallow direct assignment */}
};

// Copy fields out of row
// func:mdbg.FBuilddir.base.CopyOut
void                 builddir_CopyOut(mdbg::FBuilddir &row, dev::Builddir &out) __attribute__((nothrow));
// Copy fields in to row
// func:mdbg.FBuilddir.base.CopyIn
void                 builddir_CopyIn(mdbg::FBuilddir &row, dev::Builddir &in) __attribute__((nothrow));

// func:mdbg.FBuilddir.uname.Get
algo::Smallstr50     uname_Get(mdbg::FBuilddir& builddir) __attribute__((__warn_unused_result__, nothrow));

// func:mdbg.FBuilddir.compiler.Get
algo::Smallstr50     compiler_Get(mdbg::FBuilddir& builddir) __attribute__((__warn_unused_result__, nothrow));

// func:mdbg.FBuilddir.cfg.Get
algo::Smallstr50     cfg_Get(mdbg::FBuilddir& builddir) __attribute__((__warn_unused_result__, nothrow));

// func:mdbg.FBuilddir.arch.Get
algo::Smallstr50     arch_Get(mdbg::FBuilddir& builddir) __attribute__((__warn_unused_result__, nothrow));

// Set all fields to initial values.
// func:mdbg.FBuilddir..Init
void                 FBuilddir_Init(mdbg::FBuilddir& builddir);
// func:mdbg.FBuilddir..Uninit
void                 FBuilddir_Uninit(mdbg::FBuilddir& builddir) __attribute__((nothrow));

// --- mdbg.FCfg
// create: mdbg.FDb.cfg (Lary)
// global access: ind_cfg (Thash)
struct FCfg { // mdbg.FCfg
    algo::Smallstr50    cfg;                //
    algo::Smallstr5     suffix;             //
    algo::Comment       comment;            //
    mdbg::FBuilddir**   c_builddir_elems;   // array of pointers
    u32                 c_builddir_n;       // array of pointers
    u32                 c_builddir_max;     // capacity of allocated array
    mdbg::FCfg*         ind_cfg_next;       // hash next
private:
    friend mdbg::FCfg&          cfg_Alloc() __attribute__((__warn_unused_result__, nothrow));
    friend mdbg::FCfg*          cfg_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
    friend void                 cfg_RemoveAll() __attribute__((nothrow));
    friend void                 cfg_RemoveLast() __attribute__((nothrow));
    FCfg();
    ~FCfg();
    FCfg(const FCfg&){ /*disallow copy constructor */}
    void operator =(const FCfg&){ /*disallow direct assignment */}
};

// Copy fields out of row
// func:mdbg.FCfg.base.CopyOut
void                 cfg_CopyOut(mdbg::FCfg &row, dev::Cfg &out) __attribute__((nothrow));
// Copy fields in to row
// func:mdbg.FCfg.base.CopyIn
void                 cfg_CopyIn(mdbg::FCfg &row, dev::Cfg &in) __attribute__((nothrow));

// Return true if index is empty
// func:mdbg.FCfg.c_builddir.EmptyQ
bool                 c_builddir_EmptyQ(mdbg::FCfg& cfg) __attribute__((nothrow));
// Look up row by row id. Return NULL if out of range
// func:mdbg.FCfg.c_builddir.Find
mdbg::FBuilddir*     c_builddir_Find(mdbg::FCfg& cfg, u32 t) __attribute__((__warn_unused_result__, nothrow));
// Return array of pointers
// func:mdbg.FCfg.c_builddir.Getary
algo::aryptr<mdbg::FBuilddir*> c_builddir_Getary(mdbg::FCfg& cfg) __attribute__((nothrow));
// Insert pointer to row into array. Row must not already be in array.
// If pointer is already in the array, it may be inserted twice.
// func:mdbg.FCfg.c_builddir.Insert
void                 c_builddir_Insert(mdbg::FCfg& cfg, mdbg::FBuilddir& row) __attribute__((nothrow));
// Insert pointer to row in array.
// If row is already in the array, do nothing.
// Return value: whether element was inserted into array.
// func:mdbg.FCfg.c_builddir.InsertMaybe
bool                 c_builddir_InsertMaybe(mdbg::FCfg& cfg, mdbg::FBuilddir& row) __attribute__((nothrow));
// Return number of items in the pointer array
// func:mdbg.FCfg.c_builddir.N
i32                  c_builddir_N(const mdbg::FCfg& cfg) __attribute__((__warn_unused_result__, nothrow, pure));
// Find element using linear scan. If element is in array, remove, otherwise do nothing
// func:mdbg.FCfg.c_builddir.Remove
void                 c_builddir_Remove(mdbg::FCfg& cfg, mdbg::FBuilddir& row) __attribute__((nothrow));
// Empty the index. (The rows are not deleted)
// func:mdbg.FCfg.c_builddir.RemoveAll
void                 c_builddir_RemoveAll(mdbg::FCfg& cfg) __attribute__((nothrow));
// Reserve space in index for N more elements;
// func:mdbg.FCfg.c_builddir.Reserve
void                 c_builddir_Reserve(mdbg::FCfg& cfg, u32 n) __attribute__((nothrow));
// Return reference without bounds checking
// func:mdbg.FCfg.c_builddir.qFind
mdbg::FBuilddir&     c_builddir_qFind(mdbg::FCfg& cfg, u32 idx) __attribute__((nothrow));
// True if row is in any ptrary instance
// func:mdbg.FCfg.c_builddir.InAryQ
bool                 cfg_c_builddir_InAryQ(mdbg::FBuilddir& row) __attribute__((nothrow));
// Reference to last element without bounds checking
// func:mdbg.FCfg.c_builddir.qLast
mdbg::FBuilddir&     c_builddir_qLast(mdbg::FCfg& cfg) __attribute__((nothrow));

// func:mdbg.FCfg.c_builddir_curs.Reset
void                 cfg_c_builddir_curs_Reset(cfg_c_builddir_curs &curs, mdbg::FCfg &parent) __attribute__((nothrow));
// cursor points to valid item
// func:mdbg.FCfg.c_builddir_curs.ValidQ
bool                 cfg_c_builddir_curs_ValidQ(cfg_c_builddir_curs &curs) __attribute__((nothrow));
// proceed to next item
// func:mdbg.FCfg.c_builddir_curs.Next
void                 cfg_c_builddir_curs_Next(cfg_c_builddir_curs &curs) __attribute__((nothrow));
// item access
// func:mdbg.FCfg.c_builddir_curs.Access
mdbg::FBuilddir&     cfg_c_builddir_curs_Access(cfg_c_builddir_curs &curs) __attribute__((nothrow));
// Set all fields to initial values.
// func:mdbg.FCfg..Init
void                 FCfg_Init(mdbg::FCfg& cfg);
// func:mdbg.FCfg..Uninit
void                 FCfg_Uninit(mdbg::FCfg& cfg) __attribute__((nothrow));

// --- mdbg.trace
#pragma pack(push,1)
struct trace { // mdbg.trace
    trace();
};
#pragma pack(pop)

// print string representation of ROW to string STR
// cfmt:mdbg.trace.String  printfmt:Tuple
// func:mdbg.trace..Print
void                 trace_Print(mdbg::trace& row, algo::cstring& str) __attribute__((nothrow));

// --- mdbg.FDb
// create: mdbg.FDb._db (Global)
struct FDb { // mdbg.FDb: In-memory database for mdbg
    lpool_Lpblock*     lpool_free[31];          // Lpool levels
    u32                lpool_lock;              // Lpool lock
    command::mdbg      cmdline;                 //
    algo::cstring      script;                  // Output script
    algo::cstring      gdbscript;               // GDB script
    mdbg::FCfg*        cfg_lary[32];            // level array
    i32                cfg_n;                   // number of elements in array
    mdbg::FCfg**       ind_cfg_buckets_elems;   // pointer to bucket array
    i32                ind_cfg_buckets_n;       // number of elements in bucket array
    i32                ind_cfg_n;               // number of elements in the hash table
    mdbg::FBuilddir*   builddir_lary[32];       // level array
    i32                builddir_n;              // number of elements in array
    bool               break_main;              //   false  Breakpoint in main was requested at command line
    i32                bnum;                    //   1  Breakpoint number for gdb
    mdbg::trace        trace;                   //
};

// Free block of memory previously returned by Lpool.
// func:mdbg.FDb.lpool.FreeMem
void                 lpool_FreeMem(void *mem, u64 size) __attribute__((nothrow));
// Allocate new piece of memory at least SIZE bytes long.
// If not successful, return NULL
// The allocated block is 16-byte aligned
// func:mdbg.FDb.lpool.AllocMem
void*                lpool_AllocMem(u64 size) __attribute__((__warn_unused_result__, nothrow));
// Add N buffers of some size to the free store
// func:mdbg.FDb.lpool.ReserveBuffers
bool                 lpool_ReserveBuffers(int nbuf, u64 bufsize) __attribute__((nothrow));
// Allocate new block, copy old to new, delete old.
// New memory is always allocated (i.e. size reduction is not a no-op)
// If no memory, return NULL: old memory untouched
// func:mdbg.FDb.lpool.ReallocMem
void*                lpool_ReallocMem(void *oldmem, u64 old_size, u64 new_size) __attribute__((nothrow));

// Read argc,argv directly into the fields of the command line(s)
// The following fields are updated:
//     mdbg.FDb.cmdline
//     algo_lib.FDb.cmdline
// func:mdbg.FDb._db.ReadArgv
void                 ReadArgv() __attribute__((nothrow));
// Main loop.
// func:mdbg.FDb._db.MainLoop
void                 MainLoop();
// Main step
// func:mdbg.FDb._db.Step
void                 Step();
// Main function
// func:mdbg.FDb._db.Main
// this function is 'extrn' and implemented by user
void                 Main();
// func:mdbg.FDb._db.StaticCheck
void                 StaticCheck();
// Parse strptr into known type and add to database.
// Return value is true unless an error occurs. If return value is false, algo_lib::_db.errtext has error text
// func:mdbg.FDb._db.InsertStrptrMaybe
bool                 InsertStrptrMaybe(algo::strptr str);
// Load all finputs from given directory.
// func:mdbg.FDb._db.LoadTuplesMaybe
bool                 LoadTuplesMaybe(algo::strptr root, bool recursive) __attribute__((nothrow));
// Load all finputs from given file.
// Read tuples from file FNAME into this namespace's in-memory database.
// If RECURSIVE is TRUE, then also load these tuples into any parent namespaces
// It a file referred to by FNAME is missing, no error is reported (it's considered an empty set).
// Function returns TRUE if all records were parsed and inserted without error.
// If the function returns FALSE, use algo_lib::DetachBadTags() for error description
// func:mdbg.FDb._db.LoadTuplesFile
bool                 LoadTuplesFile(algo::strptr fname, bool recursive) __attribute__((nothrow));
// Load all finputs from given file descriptor.
// func:mdbg.FDb._db.LoadTuplesFd
bool                 LoadTuplesFd(algo::Fildes fd, algo::strptr fname, bool recursive) __attribute__((nothrow));
// Load specified ssimfile.
// func:mdbg.FDb._db.LoadSsimfileMaybe
bool                 LoadSsimfileMaybe(algo::strptr fname, bool recursive) __attribute__((nothrow));
// Calls Step function of dependencies
// func:mdbg.FDb._db.Steps
void                 Steps();
// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Caller must Delete or Unref such row.
// func:mdbg.FDb._db.XrefMaybe
bool                 _db_XrefMaybe();

// Allocate memory for new default row.
// If out of memory, process is killed.
// func:mdbg.FDb.cfg.Alloc
mdbg::FCfg&          cfg_Alloc() __attribute__((__warn_unused_result__, nothrow));
// Allocate memory for new element. If out of memory, return NULL.
// func:mdbg.FDb.cfg.AllocMaybe
mdbg::FCfg*          cfg_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
// Create new row from struct.
// Return pointer to new element, or NULL if insertion failed (due to out-of-memory, duplicate key, etc)
// func:mdbg.FDb.cfg.InsertMaybe
mdbg::FCfg*          cfg_InsertMaybe(const dev::Cfg &value) __attribute__((nothrow));
// Allocate space for one element. If no memory available, return NULL.
// func:mdbg.FDb.cfg.AllocMem
void*                cfg_AllocMem() __attribute__((__warn_unused_result__, nothrow));
// Return true if index is empty
// func:mdbg.FDb.cfg.EmptyQ
bool                 cfg_EmptyQ() __attribute__((nothrow, pure));
// Look up row by row id. Return NULL if out of range
// func:mdbg.FDb.cfg.Find
mdbg::FCfg*          cfg_Find(u64 t) __attribute__((__warn_unused_result__, nothrow, pure));
// Return pointer to last element of array, or NULL if array is empty
// func:mdbg.FDb.cfg.Last
mdbg::FCfg*          cfg_Last() __attribute__((nothrow, pure));
// Return number of items in the pool
// func:mdbg.FDb.cfg.N
i32                  cfg_N() __attribute__((__warn_unused_result__, nothrow, pure));
// Remove all elements from Lary
// func:mdbg.FDb.cfg.RemoveAll
void                 cfg_RemoveAll() __attribute__((nothrow));
// Delete last element of array. Do nothing if array is empty.
// func:mdbg.FDb.cfg.RemoveLast
void                 cfg_RemoveLast() __attribute__((nothrow));
// 'quick' Access row by row id. No bounds checking.
// func:mdbg.FDb.cfg.qFind
mdbg::FCfg&          cfg_qFind(u64 t) __attribute__((nothrow, pure));
// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Caller must Delete or Unref such row.
// func:mdbg.FDb.cfg.XrefMaybe
bool                 cfg_XrefMaybe(mdbg::FCfg &row);

// Return true if hash is empty
// func:mdbg.FDb.ind_cfg.EmptyQ
bool                 ind_cfg_EmptyQ() __attribute__((nothrow));
// Find row by key. Return NULL if not found.
// func:mdbg.FDb.ind_cfg.Find
mdbg::FCfg*          ind_cfg_Find(const algo::strptr& key) __attribute__((__warn_unused_result__, nothrow));
// Find row by key. If not found, create and x-reference a new row with with this key.
// func:mdbg.FDb.ind_cfg.GetOrCreate
mdbg::FCfg&          ind_cfg_GetOrCreate(const algo::strptr& key) __attribute__((nothrow));
// Return number of items in the hash
// func:mdbg.FDb.ind_cfg.N
i32                  ind_cfg_N() __attribute__((__warn_unused_result__, nothrow, pure));
// Insert row into hash table. Return true if row is reachable through the hash after the function completes.
// func:mdbg.FDb.ind_cfg.InsertMaybe
bool                 ind_cfg_InsertMaybe(mdbg::FCfg& row) __attribute__((nothrow));
// Remove reference to element from hash index. If element is not in hash, do nothing
// func:mdbg.FDb.ind_cfg.Remove
void                 ind_cfg_Remove(mdbg::FCfg& row) __attribute__((nothrow));
// Reserve enough room in the hash for N more elements. Return success code.
// func:mdbg.FDb.ind_cfg.Reserve
void                 ind_cfg_Reserve(int n) __attribute__((nothrow));

// Allocate memory for new default row.
// If out of memory, process is killed.
// func:mdbg.FDb.builddir.Alloc
mdbg::FBuilddir&     builddir_Alloc() __attribute__((__warn_unused_result__, nothrow));
// Allocate memory for new element. If out of memory, return NULL.
// func:mdbg.FDb.builddir.AllocMaybe
mdbg::FBuilddir*     builddir_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
// Create new row from struct.
// Return pointer to new element, or NULL if insertion failed (due to out-of-memory, duplicate key, etc)
// func:mdbg.FDb.builddir.InsertMaybe
mdbg::FBuilddir*     builddir_InsertMaybe(const dev::Builddir &value) __attribute__((nothrow));
// Allocate space for one element. If no memory available, return NULL.
// func:mdbg.FDb.builddir.AllocMem
void*                builddir_AllocMem() __attribute__((__warn_unused_result__, nothrow));
// Return true if index is empty
// func:mdbg.FDb.builddir.EmptyQ
bool                 builddir_EmptyQ() __attribute__((nothrow, pure));
// Look up row by row id. Return NULL if out of range
// func:mdbg.FDb.builddir.Find
mdbg::FBuilddir*     builddir_Find(u64 t) __attribute__((__warn_unused_result__, nothrow, pure));
// Return pointer to last element of array, or NULL if array is empty
// func:mdbg.FDb.builddir.Last
mdbg::FBuilddir*     builddir_Last() __attribute__((nothrow, pure));
// Return number of items in the pool
// func:mdbg.FDb.builddir.N
i32                  builddir_N() __attribute__((__warn_unused_result__, nothrow, pure));
// Remove all elements from Lary
// func:mdbg.FDb.builddir.RemoveAll
void                 builddir_RemoveAll() __attribute__((nothrow));
// Delete last element of array. Do nothing if array is empty.
// func:mdbg.FDb.builddir.RemoveLast
void                 builddir_RemoveLast() __attribute__((nothrow));
// 'quick' Access row by row id. No bounds checking.
// func:mdbg.FDb.builddir.qFind
mdbg::FBuilddir&     builddir_qFind(u64 t) __attribute__((nothrow, pure));
// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Caller must Delete or Unref such row.
// func:mdbg.FDb.builddir.XrefMaybe
bool                 builddir_XrefMaybe(mdbg::FBuilddir &row);

// cursor points to valid item
// func:mdbg.FDb.cfg_curs.Reset
void                 _db_cfg_curs_Reset(_db_cfg_curs &curs, mdbg::FDb &parent) __attribute__((nothrow));
// cursor points to valid item
// func:mdbg.FDb.cfg_curs.ValidQ
bool                 _db_cfg_curs_ValidQ(_db_cfg_curs &curs) __attribute__((nothrow));
// proceed to next item
// func:mdbg.FDb.cfg_curs.Next
void                 _db_cfg_curs_Next(_db_cfg_curs &curs) __attribute__((nothrow));
// item access
// func:mdbg.FDb.cfg_curs.Access
mdbg::FCfg&          _db_cfg_curs_Access(_db_cfg_curs &curs) __attribute__((nothrow));
// cursor points to valid item
// func:mdbg.FDb.builddir_curs.Reset
void                 _db_builddir_curs_Reset(_db_builddir_curs &curs, mdbg::FDb &parent) __attribute__((nothrow));
// cursor points to valid item
// func:mdbg.FDb.builddir_curs.ValidQ
bool                 _db_builddir_curs_ValidQ(_db_builddir_curs &curs) __attribute__((nothrow));
// proceed to next item
// func:mdbg.FDb.builddir_curs.Next
void                 _db_builddir_curs_Next(_db_builddir_curs &curs) __attribute__((nothrow));
// item access
// func:mdbg.FDb.builddir_curs.Access
mdbg::FBuilddir&     _db_builddir_curs_Access(_db_builddir_curs &curs) __attribute__((nothrow));
// Set all fields to initial values.
// func:mdbg.FDb..Init
void                 FDb_Init();
// func:mdbg.FDb..Uninit
void                 FDb_Uninit() __attribute__((nothrow));

// --- mdbg.FieldId
#pragma pack(push,1)
struct FieldId { // mdbg.FieldId: Field read helper
    i32   value;   //   -1
    inline operator mdbg_FieldIdEnum() const;
    explicit FieldId(i32                            in_value);
    FieldId(mdbg_FieldIdEnum arg);
    FieldId();
};
#pragma pack(pop)

// Get value of field as enum type
// func:mdbg.FieldId.value.GetEnum
mdbg_FieldIdEnum     value_GetEnum(const mdbg::FieldId& parent) __attribute__((nothrow));
// Set value of field from enum type.
// func:mdbg.FieldId.value.SetEnum
void                 value_SetEnum(mdbg::FieldId& parent, mdbg_FieldIdEnum rhs) __attribute__((nothrow));
// Convert numeric value of field to one of predefined string constants.
// If string is found, return a static C string. Otherwise, return NULL.
// func:mdbg.FieldId.value.ToCstr
const char*          value_ToCstr(const mdbg::FieldId& parent) __attribute__((nothrow));
// Convert value to a string. First, attempt conversion to a known string.
// If no string matches, print value as a numeric value.
// func:mdbg.FieldId.value.Print
void                 value_Print(const mdbg::FieldId& parent, algo::cstring &lhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, do not modify field and return false.
// In case of success, return true
// func:mdbg.FieldId.value.SetStrptrMaybe
bool                 value_SetStrptrMaybe(mdbg::FieldId& parent, algo::strptr rhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, set numeric value to DFLT
// func:mdbg.FieldId.value.SetStrptr
void                 value_SetStrptr(mdbg::FieldId& parent, algo::strptr rhs, mdbg_FieldIdEnum dflt) __attribute__((nothrow));
// Convert string to field. Return success value
// func:mdbg.FieldId.value.ReadStrptrMaybe
bool                 value_ReadStrptrMaybe(mdbg::FieldId& parent, algo::strptr rhs) __attribute__((nothrow));

// Read fields of mdbg::FieldId from an ascii string.
// The format of the string is the format of the mdbg::FieldId's only field
// func:mdbg.FieldId..ReadStrptrMaybe
bool                 FieldId_ReadStrptrMaybe(mdbg::FieldId &parent, algo::strptr in_str);
// Set all fields to initial values.
// func:mdbg.FieldId..Init
void                 FieldId_Init(mdbg::FieldId& parent);
// print string representation of ROW to string STR
// cfmt:mdbg.FieldId.String  printfmt:Raw
// func:mdbg.FieldId..Print
void                 FieldId_Print(mdbg::FieldId& row, algo::cstring& str) __attribute__((nothrow));

// --- mdbg.TableId
struct TableId { // mdbg.TableId: Index of table in this namespace
    i32   value;   //   -1  index of table
    inline operator mdbg_TableIdEnum() const;
    explicit TableId(i32                            in_value);
    TableId(mdbg_TableIdEnum arg);
    TableId();
};

// Get value of field as enum type
// func:mdbg.TableId.value.GetEnum
mdbg_TableIdEnum     value_GetEnum(const mdbg::TableId& parent) __attribute__((nothrow));
// Set value of field from enum type.
// func:mdbg.TableId.value.SetEnum
void                 value_SetEnum(mdbg::TableId& parent, mdbg_TableIdEnum rhs) __attribute__((nothrow));
// Convert numeric value of field to one of predefined string constants.
// If string is found, return a static C string. Otherwise, return NULL.
// func:mdbg.TableId.value.ToCstr
const char*          value_ToCstr(const mdbg::TableId& parent) __attribute__((nothrow));
// Convert value to a string. First, attempt conversion to a known string.
// If no string matches, print value as a numeric value.
// func:mdbg.TableId.value.Print
void                 value_Print(const mdbg::TableId& parent, algo::cstring &lhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, do not modify field and return false.
// In case of success, return true
// func:mdbg.TableId.value.SetStrptrMaybe
bool                 value_SetStrptrMaybe(mdbg::TableId& parent, algo::strptr rhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, set numeric value to DFLT
// func:mdbg.TableId.value.SetStrptr
void                 value_SetStrptr(mdbg::TableId& parent, algo::strptr rhs, mdbg_TableIdEnum dflt) __attribute__((nothrow));
// Convert string to field. Return success value
// func:mdbg.TableId.value.ReadStrptrMaybe
bool                 value_ReadStrptrMaybe(mdbg::TableId& parent, algo::strptr rhs) __attribute__((nothrow));

// Read fields of mdbg::TableId from an ascii string.
// The format of the string is the format of the mdbg::TableId's only field
// func:mdbg.TableId..ReadStrptrMaybe
bool                 TableId_ReadStrptrMaybe(mdbg::TableId &parent, algo::strptr in_str);
// Set all fields to initial values.
// func:mdbg.TableId..Init
void                 TableId_Init(mdbg::TableId& parent);
// print string representation of ROW to string STR
// cfmt:mdbg.TableId.String  printfmt:Raw
// func:mdbg.TableId..Print
void                 TableId_Print(mdbg::TableId& row, algo::cstring& str) __attribute__((nothrow));
} // gen:ns_print_struct
namespace mdbg { // gen:ns_curstext

struct cfg_c_builddir_curs {// fcurs:mdbg.FCfg.c_builddir/curs
    typedef mdbg::FBuilddir ChildType;
    mdbg::FBuilddir** elems;
    u32 n_elems;
    u32 index;
    cfg_c_builddir_curs() { elems=NULL; n_elems=0; index=0; }
};


struct _db_cfg_curs {// cursor
    typedef mdbg::FCfg ChildType;
    mdbg::FDb *parent;
    i64 index;
    _db_cfg_curs(){ parent=NULL; index=0; }
};


struct _db_builddir_curs {// cursor
    typedef mdbg::FBuilddir ChildType;
    mdbg::FDb *parent;
    i64 index;
    _db_builddir_curs(){ parent=NULL; index=0; }
};

} // gen:ns_curstext
namespace mdbg { // gen:ns_func
} // gen:ns_func
// func:mdbg...main
int                  main(int argc, char **argv);
#if defined(WIN32)
// func:mdbg...WinMain
int WINAPI           WinMain(HINSTANCE,HINSTANCE,LPSTR,int);
#endif
// gen:ns_operators
namespace algo {
inline algo::cstring &operator <<(algo::cstring &str, const mdbg::trace &row);// cfmt:mdbg.trace.String
inline algo::cstring &operator <<(algo::cstring &str, const mdbg::FieldId &row);// cfmt:mdbg.FieldId.String
inline algo::cstring &operator <<(algo::cstring &str, const mdbg::TableId &row);// cfmt:mdbg.TableId.String
}
