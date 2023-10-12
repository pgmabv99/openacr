//
// include/gen/acr_my_gen.h
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
#include "include/gen/algo_lib_gen.h"
#include "include/gen/algo_gen.h"
#include "include/gen/command_gen.h"
#include "include/gen/dmmeta_gen.h"
//#pragma endinclude
// gen:ns_enums

// --- acr_my_FieldIdEnum

enum acr_my_FieldIdEnum {        // acr_my.FieldId.value
     acr_my_FieldId_value   = 0
};

enum { acr_my_FieldIdEnum_N = 1 };


// --- acr_my_TableIdEnum

enum acr_my_TableIdEnum {                   // acr_my.TableId.value
     acr_my_TableId_dmmeta_Nsdb       = 0   // dmmeta.Nsdb -> acr_my.FNsdb
    ,acr_my_TableId_dmmeta_nsdb       = 0   // dmmeta.nsdb -> acr_my.FNsdb
    ,acr_my_TableId_dmmeta_Ssimfile   = 1   // dmmeta.Ssimfile -> acr_my.FSsimfile
    ,acr_my_TableId_dmmeta_ssimfile   = 1   // dmmeta.ssimfile -> acr_my.FSsimfile
};

enum { acr_my_TableIdEnum_N = 4 };

namespace acr_my { // gen:ns_pkeytypedef
} // gen:ns_pkeytypedef
namespace acr_my { // gen:ns_field
extern const char *acr_my_help;
} // gen:ns_field
// gen:ns_fwddecl2
namespace dmmeta { struct Nsdb; }
namespace dmmeta { struct Ssimfile; }
namespace acr_my { struct _db_ary_ns_curs; }
namespace acr_my { struct _db_nsdb_curs; }
namespace acr_my { struct _db_ssimfile_curs; }
namespace acr_my { struct trace; }
namespace acr_my { struct FDb; }
namespace acr_my { struct FNsdb; }
namespace acr_my { struct FSsimfile; }
namespace acr_my { struct FieldId; }
namespace acr_my { struct TableId; }
namespace acr_my { extern struct acr_my::FDb _db; }
namespace acr_my { // gen:ns_print_struct

// --- acr_my.trace
#pragma pack(push,1)
struct trace { // acr_my.trace
    trace();
};
#pragma pack(pop)

// print string representation of acr_my::trace to string LHS, no header -- cprint:acr_my.trace.String
void                 trace_Print(acr_my::trace & row, algo::cstring &str) __attribute__((nothrow));

// --- acr_my.FDb
// create: acr_my.FDb._db (Global)
struct FDb { // acr_my.FDb: Function to convert to mysql
    algo_lib::Replscope   R;                   //
    algo::cstring         data_dir;            //
    algo::cstring         data_logdir;         //
    algo::cstring*        ary_ns_elems;        // pointer to elements
    u32                   ary_ns_n;            // number of elements in array
    u32                   ary_ns_max;          // max. capacity of array before realloc
    bool                  started;             //   false
    command::acr_my       cmdline;             //
    acr_my::FNsdb*        nsdb_lary[32];       // level array
    i32                   nsdb_n;              // number of elements in array
    acr_my::FSsimfile*    ssimfile_lary[32];   // level array
    i32                   ssimfile_n;          // number of elements in array
    acr_my::trace         trace;               //
};

// Reserve space. Insert element at the end
// The new element is initialized to a default value
algo::cstring&       ary_ns_Alloc() __attribute__((__warn_unused_result__, nothrow));
// Reserve space for new element, reallocating the array if necessary
// Insert new element at specified index. Index must be in range or a fatal error occurs.
algo::cstring&       ary_ns_AllocAt(int at) __attribute__((__warn_unused_result__, nothrow));
// Reserve space. Insert N elements at the end of the array, return pointer to array
algo::aryptr<algo::cstring> ary_ns_AllocN(int n_elems) __attribute__((__warn_unused_result__, nothrow));
// Return true if index is empty
bool                 ary_ns_EmptyQ() __attribute__((nothrow));
// Look up row by row id. Return NULL if out of range
algo::cstring*       ary_ns_Find(u64 t) __attribute__((__warn_unused_result__, nothrow));
// Return array pointer by value
algo::aryptr<algo::cstring> ary_ns_Getary() __attribute__((nothrow));
// Return pointer to last element of array, or NULL if array is empty
algo::cstring*       ary_ns_Last() __attribute__((nothrow, pure));
// Return max. number of items in the array
i32                  ary_ns_Max() __attribute__((nothrow));
// Return number of items in the array
i32                  ary_ns_N() __attribute__((__warn_unused_result__, nothrow, pure));
// Remove item by index. If index outside of range, do nothing.
void                 ary_ns_Remove(u32 i) __attribute__((nothrow));
void                 ary_ns_RemoveAll() __attribute__((nothrow));
// Delete last element of array. Do nothing if array is empty.
void                 ary_ns_RemoveLast() __attribute__((nothrow));
// Make sure N *more* elements will fit in array. Process dies if out of memory
void                 ary_ns_Reserve(int n) __attribute__((nothrow));
// Make sure N elements fit in array. Process dies if out of memory
void                 ary_ns_AbsReserve(int n) __attribute__((nothrow));
// 'quick' Access row by row id. No bounds checking.
algo::cstring&       ary_ns_qFind(u64 t) __attribute__((nothrow));
// Return reference to last element of array. No bounds checking
algo::cstring&       ary_ns_qLast() __attribute__((nothrow));
// Return row id of specified element
u64                  ary_ns_rowid_Get(algo::cstring &elem) __attribute__((nothrow));
// Reserve space. Insert N elements at the end of the array, return pointer to array
algo::aryptr<algo::cstring> ary_ns_AllocNVal(int n_elems, const algo::cstring& val) __attribute__((__warn_unused_result__, nothrow));

// Read argc,argv directly into the fields of the command line(s)
// The following fields are updated:
//     acr_my.FDb.cmdline
//     algo_lib.FDb.cmdline
void                 ReadArgv() __attribute__((nothrow));
// Main loop.
void                 MainLoop();
// Main step
void                 Step();
// Main function
void                 Main();
void                 StaticCheck();
// Parse strptr into known type and add to database.
// Return value is true unless an error occurs. If return value is false, algo_lib::_db.errtext has error text
bool                 InsertStrptrMaybe(algo::strptr str);
// Load all finputs from given directory.
bool                 LoadTuplesMaybe(algo::strptr root) __attribute__((nothrow));
// Load specified ssimfile.
bool                 LoadSsimfileMaybe(algo::strptr fname) __attribute__((nothrow));
// Calls Step function of dependencies
void                 Steps();
// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Caller must Delete or Unref such row.
bool                 _db_XrefMaybe();

// Allocate memory for new default row.
// If out of memory, process is killed.
acr_my::FNsdb&       nsdb_Alloc() __attribute__((__warn_unused_result__, nothrow));
// Allocate memory for new element. If out of memory, return NULL.
acr_my::FNsdb*       nsdb_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
// Create new row from struct.
// Return pointer to new element, or NULL if insertion failed (due to out-of-memory, duplicate key, etc)
acr_my::FNsdb*       nsdb_InsertMaybe(const dmmeta::Nsdb &value) __attribute__((nothrow));
// Allocate space for one element. If no memory available, return NULL.
void*                nsdb_AllocMem() __attribute__((__warn_unused_result__, nothrow));
// Return true if index is empty
bool                 nsdb_EmptyQ() __attribute__((nothrow, pure));
// Look up row by row id. Return NULL if out of range
acr_my::FNsdb*       nsdb_Find(u64 t) __attribute__((__warn_unused_result__, nothrow, pure));
// Return pointer to last element of array, or NULL if array is empty
acr_my::FNsdb*       nsdb_Last() __attribute__((nothrow, pure));
// Return number of items in the pool
i32                  nsdb_N() __attribute__((__warn_unused_result__, nothrow, pure));
// Delete last element of array. Do nothing if array is empty.
void                 nsdb_RemoveLast() __attribute__((nothrow));
// 'quick' Access row by row id. No bounds checking.
acr_my::FNsdb&       nsdb_qFind(u64 t) __attribute__((nothrow, pure));
// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Caller must Delete or Unref such row.
bool                 nsdb_XrefMaybe(acr_my::FNsdb &row);

// Allocate memory for new default row.
// If out of memory, process is killed.
acr_my::FSsimfile&   ssimfile_Alloc() __attribute__((__warn_unused_result__, nothrow));
// Allocate memory for new element. If out of memory, return NULL.
acr_my::FSsimfile*   ssimfile_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
// Create new row from struct.
// Return pointer to new element, or NULL if insertion failed (due to out-of-memory, duplicate key, etc)
acr_my::FSsimfile*   ssimfile_InsertMaybe(const dmmeta::Ssimfile &value) __attribute__((nothrow));
// Allocate space for one element. If no memory available, return NULL.
void*                ssimfile_AllocMem() __attribute__((__warn_unused_result__, nothrow));
// Return true if index is empty
bool                 ssimfile_EmptyQ() __attribute__((nothrow, pure));
// Look up row by row id. Return NULL if out of range
acr_my::FSsimfile*   ssimfile_Find(u64 t) __attribute__((__warn_unused_result__, nothrow, pure));
// Return pointer to last element of array, or NULL if array is empty
acr_my::FSsimfile*   ssimfile_Last() __attribute__((nothrow, pure));
// Return number of items in the pool
i32                  ssimfile_N() __attribute__((__warn_unused_result__, nothrow, pure));
// Delete last element of array. Do nothing if array is empty.
void                 ssimfile_RemoveLast() __attribute__((nothrow));
// 'quick' Access row by row id. No bounds checking.
acr_my::FSsimfile&   ssimfile_qFind(u64 t) __attribute__((nothrow, pure));
// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Caller must Delete or Unref such row.
bool                 ssimfile_XrefMaybe(acr_my::FSsimfile &row);

// proceed to next item
void                 _db_ary_ns_curs_Next(_db_ary_ns_curs &curs);
void                 _db_ary_ns_curs_Reset(_db_ary_ns_curs &curs, acr_my::FDb &parent);
// cursor points to valid item
bool                 _db_ary_ns_curs_ValidQ(_db_ary_ns_curs &curs);
// item access
algo::cstring&       _db_ary_ns_curs_Access(_db_ary_ns_curs &curs);
// cursor points to valid item
void                 _db_nsdb_curs_Reset(_db_nsdb_curs &curs, acr_my::FDb &parent);
// cursor points to valid item
bool                 _db_nsdb_curs_ValidQ(_db_nsdb_curs &curs);
// proceed to next item
void                 _db_nsdb_curs_Next(_db_nsdb_curs &curs);
// item access
acr_my::FNsdb&       _db_nsdb_curs_Access(_db_nsdb_curs &curs);
// cursor points to valid item
void                 _db_ssimfile_curs_Reset(_db_ssimfile_curs &curs, acr_my::FDb &parent);
// cursor points to valid item
bool                 _db_ssimfile_curs_ValidQ(_db_ssimfile_curs &curs);
// proceed to next item
void                 _db_ssimfile_curs_Next(_db_ssimfile_curs &curs);
// item access
acr_my::FSsimfile&   _db_ssimfile_curs_Access(_db_ssimfile_curs &curs);
// Set all fields to initial values.
void                 FDb_Init();
void                 FDb_Uninit() __attribute__((nothrow));

// --- acr_my.FNsdb
// create: acr_my.FDb.nsdb (Lary)
struct FNsdb { // acr_my.FNsdb
    algo::Smallstr16   ns;        //
    algo::Comment      comment;   //
    bool               select;    //   false
private:
    friend acr_my::FNsdb&       nsdb_Alloc() __attribute__((__warn_unused_result__, nothrow));
    friend acr_my::FNsdb*       nsdb_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
    friend void                 nsdb_RemoveLast() __attribute__((nothrow));
    FNsdb();
};

// Copy fields out of row
void                 nsdb_CopyOut(acr_my::FNsdb &row, dmmeta::Nsdb &out) __attribute__((nothrow));
// Copy fields in to row
void                 nsdb_CopyIn(acr_my::FNsdb &row, dmmeta::Nsdb &in) __attribute__((nothrow));

// Set all fields to initial values.
void                 FNsdb_Init(acr_my::FNsdb& nsdb);

// --- acr_my.FSsimfile
// create: acr_my.FDb.ssimfile (Lary)
struct FSsimfile { // acr_my.FSsimfile
    algo::Smallstr50   ssimfile;   //
    algo::Smallstr50   ctype;      //
private:
    friend acr_my::FSsimfile&   ssimfile_Alloc() __attribute__((__warn_unused_result__, nothrow));
    friend acr_my::FSsimfile*   ssimfile_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
    friend void                 ssimfile_RemoveLast() __attribute__((nothrow));
    FSsimfile();
};

// Copy fields out of row
void                 ssimfile_CopyOut(acr_my::FSsimfile &row, dmmeta::Ssimfile &out) __attribute__((nothrow));
// Copy fields in to row
void                 ssimfile_CopyIn(acr_my::FSsimfile &row, dmmeta::Ssimfile &in) __attribute__((nothrow));

algo::Smallstr16     ssimns_Get(acr_my::FSsimfile& ssimfile) __attribute__((__warn_unused_result__, nothrow));

algo::Smallstr16     ns_Get(acr_my::FSsimfile& ssimfile) __attribute__((__warn_unused_result__, nothrow));

algo::Smallstr50     name_Get(acr_my::FSsimfile& ssimfile) __attribute__((__warn_unused_result__, nothrow));


// --- acr_my.FieldId
#pragma pack(push,1)
struct FieldId { // acr_my.FieldId: Field read helper
    i32   value;   //   -1
    inline operator acr_my_FieldIdEnum() const;
    explicit FieldId(i32                            in_value);
    FieldId(acr_my_FieldIdEnum arg);
    FieldId();
};
#pragma pack(pop)

// Get value of field as enum type
acr_my_FieldIdEnum   value_GetEnum(const acr_my::FieldId& parent) __attribute__((nothrow));
// Set value of field from enum type.
void                 value_SetEnum(acr_my::FieldId& parent, acr_my_FieldIdEnum rhs) __attribute__((nothrow));
// Convert numeric value of field to one of predefined string constants.
// If string is found, return a static C string. Otherwise, return NULL.
const char*          value_ToCstr(const acr_my::FieldId& parent) __attribute__((nothrow));
// Convert value to a string. First, attempt conversion to a known string.
// If no string matches, print value as a numeric value.
void                 value_Print(const acr_my::FieldId& parent, algo::cstring &lhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, do not modify field and return false.
// In case of success, return true
bool                 value_SetStrptrMaybe(acr_my::FieldId& parent, algo::strptr rhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, set numeric value to DFLT
void                 value_SetStrptr(acr_my::FieldId& parent, algo::strptr rhs, acr_my_FieldIdEnum dflt) __attribute__((nothrow));
// Convert string to field. Return success value
bool                 value_ReadStrptrMaybe(acr_my::FieldId& parent, algo::strptr rhs) __attribute__((nothrow));

// Read fields of acr_my::FieldId from an ascii string.
// The format of the string is the format of the acr_my::FieldId's only field
bool                 FieldId_ReadStrptrMaybe(acr_my::FieldId &parent, algo::strptr in_str);
// Set all fields to initial values.
void                 FieldId_Init(acr_my::FieldId& parent);
// print string representation of acr_my::FieldId to string LHS, no header -- cprint:acr_my.FieldId.String
void                 FieldId_Print(acr_my::FieldId & row, algo::cstring &str) __attribute__((nothrow));

// --- acr_my.TableId
struct TableId { // acr_my.TableId: Index of table in this namespace
    i32   value;   //   -1  index of table
    inline operator acr_my_TableIdEnum() const;
    explicit TableId(i32                            in_value);
    TableId(acr_my_TableIdEnum arg);
    TableId();
};

// Get value of field as enum type
acr_my_TableIdEnum   value_GetEnum(const acr_my::TableId& parent) __attribute__((nothrow));
// Set value of field from enum type.
void                 value_SetEnum(acr_my::TableId& parent, acr_my_TableIdEnum rhs) __attribute__((nothrow));
// Convert numeric value of field to one of predefined string constants.
// If string is found, return a static C string. Otherwise, return NULL.
const char*          value_ToCstr(const acr_my::TableId& parent) __attribute__((nothrow));
// Convert value to a string. First, attempt conversion to a known string.
// If no string matches, print value as a numeric value.
void                 value_Print(const acr_my::TableId& parent, algo::cstring &lhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, do not modify field and return false.
// In case of success, return true
bool                 value_SetStrptrMaybe(acr_my::TableId& parent, algo::strptr rhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, set numeric value to DFLT
void                 value_SetStrptr(acr_my::TableId& parent, algo::strptr rhs, acr_my_TableIdEnum dflt) __attribute__((nothrow));
// Convert string to field. Return success value
bool                 value_ReadStrptrMaybe(acr_my::TableId& parent, algo::strptr rhs) __attribute__((nothrow));

// Read fields of acr_my::TableId from an ascii string.
// The format of the string is the format of the acr_my::TableId's only field
bool                 TableId_ReadStrptrMaybe(acr_my::TableId &parent, algo::strptr in_str);
// Set all fields to initial values.
void                 TableId_Init(acr_my::TableId& parent);
// print string representation of acr_my::TableId to string LHS, no header -- cprint:acr_my.TableId.String
void                 TableId_Print(acr_my::TableId & row, algo::cstring &str) __attribute__((nothrow));
} // gen:ns_print_struct
namespace acr_my { // gen:ns_curstext

struct _db_ary_ns_curs {// cursor
    typedef algo::cstring ChildType;
    algo::cstring* elems;
    int n_elems;
    int index;
    _db_ary_ns_curs() { elems=NULL; n_elems=0; index=0; }
};


struct _db_nsdb_curs {// cursor
    typedef acr_my::FNsdb ChildType;
    acr_my::FDb *parent;
    i64 index;
    _db_nsdb_curs(){ parent=NULL; index=0; }
};


struct _db_ssimfile_curs {// cursor
    typedef acr_my::FSsimfile ChildType;
    acr_my::FDb *parent;
    i64 index;
    _db_ssimfile_curs(){ parent=NULL; index=0; }
};

} // gen:ns_curstext
namespace acr_my { // gen:ns_func
} // gen:ns_func
int                  main(int argc, char **argv);
#if defined(WIN32)
int WINAPI           WinMain(HINSTANCE,HINSTANCE,LPSTR,int);
#endif
// gen:ns_operators
namespace algo {
inline algo::cstring &operator <<(algo::cstring &str, const acr_my::trace &row);// cfmt:acr_my.trace.String
inline algo::cstring &operator <<(algo::cstring &str, const acr_my::FieldId &row);// cfmt:acr_my.FieldId.String
inline algo::cstring &operator <<(algo::cstring &str, const acr_my::TableId &row);// cfmt:acr_my.TableId.String
}
