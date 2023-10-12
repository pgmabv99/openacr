//
// cpp/gen/fm_gen.cpp
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
#include "include/gen/fm_gen.h"
#include "include/gen/fm_gen.inl.h"
#include "include/gen/ams_gen.h"
#include "include/gen/ams_gen.inl.h"
#include "include/gen/algo_gen.h"
#include "include/gen/algo_gen.inl.h"
//#pragma endinclude
namespace fm { // gen:ns_print_proto
    static void          SizeCheck();
} // gen:ns_print_proto

// --- fm.Code.ch.Print
void fm::ch_Print(fm::Code& parent, algo::cstring &out) {
    ch_Addary(out, ch_Getary(parent));
}

// --- fm.Code.ch.ReadStrptrMaybe
// Convert string to field. Return success value
bool fm::ch_ReadStrptrMaybe(fm::Code& parent, algo::strptr rhs) {
    bool retval = false;
    if (rhs.n_elems <= 32) {
        ch_SetStrptr(parent, rhs);
        retval = true;
    } else {
        algo_lib::SaveBadTag("comment","text too long, limit 32");
    }
    return retval;
}

// --- fm.Code.ch.SetStrptr
// Copy from strptr, clipping length
// Set string to the value provided by RHS.
// If RHS is too large, it is silently clipped.
void fm::ch_SetStrptr(fm::Code& parent, const algo::strptr &rhs) {
    int len = i32_Min(rhs.n_elems, 32);
    char *rhs_elems = rhs.elems;
    int i = 0;
    int j = 0;
    for (; i < len; i++, j++) {
        parent.ch[j] = rhs_elems[i];
    }
    for (; j < 32; j++) {
        parent.ch[j] = ' ';
    }
}

// --- fm.Code..Hash
u32 fm::Code_Hash(u32 prev, const fm::Code & rhs) {
    algo::strptr ch_strptr = ch_Getary(rhs);
    prev = ::strptr_Hash(prev, ch_strptr);
    return prev;
}

// --- fm.Code..ReadStrptrMaybe
// Read fields of fm::Code from an ascii string.
// The format of the string is the format of the fm::Code's only field
bool fm::Code_ReadStrptrMaybe(fm::Code &parent, algo::strptr in_str) {
    bool retval = true;
    retval = retval && ch_ReadStrptrMaybe(parent, in_str);
    return retval;
}

// --- fm.Code..Print
// print string representation of fm::Code to string LHS, no header -- cprint:fm.Code.String
void fm::Code_Print(fm::Code & row, algo::cstring &str) {
    fm::ch_Print(row, str);
}

// --- fm.Objtype.ch.Print
void fm::ch_Print(fm::Objtype& parent, algo::cstring &out) {
    ch_Addary(out, ch_Getary(parent));
}

// --- fm.Objtype.ch.ReadStrptrMaybe
// Convert string to field. Return success value
bool fm::ch_ReadStrptrMaybe(fm::Objtype& parent, algo::strptr rhs) {
    bool retval = false;
    if (rhs.n_elems <= 15) {
        ch_SetStrptr(parent, rhs);
        retval = true;
    } else {
        algo_lib::SaveBadTag("comment","text too long, limit 15");
    }
    return retval;
}

// --- fm.Objtype.ch.SetStrptr
// Copy from strptr, clipping length
// Set string to the value provided by RHS.
// If RHS is too large, it is silently clipped.
void fm::ch_SetStrptr(fm::Objtype& parent, const algo::strptr &rhs) {
    int len = i32_Min(rhs.n_elems, 15);
    char *rhs_elems = rhs.elems;
    int i = 0;
    int j = 0;
    for (; i < len; i++, j++) {
        parent.ch[j] = rhs_elems[i];
    }
    for (; j < 15; j++) {
        parent.ch[j] = ' ';
    }
}

// --- fm.Objtype..Hash
u32 fm::Objtype_Hash(u32 prev, const fm::Objtype & rhs) {
    algo::strptr ch_strptr = ch_Getary(rhs);
    prev = ::strptr_Hash(prev, ch_strptr);
    return prev;
}

// --- fm.Objtype..ReadStrptrMaybe
// Read fields of fm::Objtype from an ascii string.
// The format of the string is the format of the fm::Objtype's only field
bool fm::Objtype_ReadStrptrMaybe(fm::Objtype &parent, algo::strptr in_str) {
    bool retval = true;
    retval = retval && ch_ReadStrptrMaybe(parent, in_str);
    return retval;
}

// --- fm.Objtype..Print
// print string representation of fm::Objtype to string LHS, no header -- cprint:fm.Objtype.String
void fm::Objtype_Print(fm::Objtype & row, algo::cstring &str) {
    fm::ch_Print(row, str);
}

// --- fm.Objinst.ch.Print
void fm::ch_Print(fm::Objinst& parent, algo::cstring &out) {
    ch_Addary(out, ch_Getary(parent));
}

// --- fm.Objinst.ch.ReadStrptrMaybe
// Convert string to field. Return success value
bool fm::ch_ReadStrptrMaybe(fm::Objinst& parent, algo::strptr rhs) {
    bool retval = false;
    if (rhs.n_elems <= 79) {
        ch_SetStrptr(parent, rhs);
        retval = true;
    } else {
        algo_lib::SaveBadTag("comment","text too long, limit 79");
    }
    return retval;
}

// --- fm.Objinst.ch.SetStrptr
// Copy from strptr, clipping length
// Set string to the value provided by RHS.
// If RHS is too large, it is silently clipped.
void fm::ch_SetStrptr(fm::Objinst& parent, const algo::strptr &rhs) {
    int len = i32_Min(rhs.n_elems, 79);
    char *rhs_elems = rhs.elems;
    int i = 0;
    int j = 0;
    for (; i < len; i++, j++) {
        parent.ch[j] = rhs_elems[i];
    }
    for (; j < 79; j++) {
        parent.ch[j] = ' ';
    }
}

// --- fm.Objinst..Hash
u32 fm::Objinst_Hash(u32 prev, const fm::Objinst & rhs) {
    algo::strptr ch_strptr = ch_Getary(rhs);
    prev = ::strptr_Hash(prev, ch_strptr);
    return prev;
}

// --- fm.Objinst..ReadStrptrMaybe
// Read fields of fm::Objinst from an ascii string.
// The format of the string is the format of the fm::Objinst's only field
bool fm::Objinst_ReadStrptrMaybe(fm::Objinst &parent, algo::strptr in_str) {
    bool retval = true;
    retval = retval && ch_ReadStrptrMaybe(parent, in_str);
    return retval;
}

// --- fm.Objinst..Print
// print string representation of fm::Objinst to string LHS, no header -- cprint:fm.Objinst.String
void fm::Objinst_Print(fm::Objinst & row, algo::cstring &str) {
    fm::ch_Print(row, str);
}

// --- fm.Flag.value.ToCstr
// Convert numeric value of field to one of predefined string constants.
// If string is found, return a static C string. Otherwise, return NULL.
const char* fm::value_ToCstr(const fm::Flag& parent) {
    const char *ret = NULL;
    switch(value_GetEnum(parent)) {
        case fm_Flag_value_cleared         : ret = "cleared";  break;
        case fm_Flag_value_raised          : ret = "raised";  break;
    }
    return ret;
}

// --- fm.Flag.value.Print
// Convert value to a string. First, attempt conversion to a known string.
// If no string matches, print value as a numeric value.
void fm::value_Print(const fm::Flag& parent, algo::cstring &lhs) {
    const char *strval = value_ToCstr(parent);
    if (strval) {
        lhs << strval;
    } else {
        lhs << parent.value;
    }
}

// --- fm.Flag.value.SetStrptrMaybe
// Convert string to field.
// If the string is invalid, do not modify field and return false.
// In case of success, return true
bool fm::value_SetStrptrMaybe(fm::Flag& parent, algo::strptr rhs) {
    bool ret = false;
    switch (elems_N(rhs)) {
        case 6: {
            switch (u64(algo::ReadLE32(rhs.elems))|(u64(algo::ReadLE16(rhs.elems+4))<<32)) {
                case LE_STR6('r','a','i','s','e','d'): {
                    value_SetEnum(parent,fm_Flag_value_raised); ret = true; break;
                }
            }
            break;
        }
        case 7: {
            switch (u64(algo::ReadLE32(rhs.elems))|(u64(algo::ReadLE16(rhs.elems+4))<<32)|(u64(rhs[6])<<48)) {
                case LE_STR7('c','l','e','a','r','e','d'): {
                    value_SetEnum(parent,fm_Flag_value_cleared); ret = true; break;
                }
            }
            break;
        }
    }
    return ret;
}

// --- fm.Flag.value.SetStrptr
// Convert string to field.
// If the string is invalid, set numeric value to DFLT
void fm::value_SetStrptr(fm::Flag& parent, algo::strptr rhs, fm_Flag_value_Enum dflt) {
    if (!value_SetStrptrMaybe(parent,rhs)) value_SetEnum(parent,dflt);
}

// --- fm.Flag.value.ReadStrptrMaybe
// Convert string to field. Return success value
bool fm::value_ReadStrptrMaybe(fm::Flag& parent, algo::strptr rhs) {
    bool retval = false;
    retval = value_SetStrptrMaybe(parent,rhs); // try symbol conversion
    if (!retval) { // didn't work? try reading as underlying type
        retval = char_ReadStrptrMaybe(parent.value,rhs);
    }
    return retval;
}

// --- fm.Flag..ReadStrptrMaybe
// Read fields of fm::Flag from an ascii string.
// The format of the string is the format of the fm::Flag's only field
bool fm::Flag_ReadStrptrMaybe(fm::Flag &parent, algo::strptr in_str) {
    bool retval = true;
    retval = retval && value_ReadStrptrMaybe(parent, in_str);
    return retval;
}

// --- fm.Flag..Print
// print string representation of fm::Flag to string LHS, no header -- cprint:fm.Flag.String
void fm::Flag_Print(fm::Flag row, algo::cstring &str) {
    fm::value_Print(row, str);
}

// --- fm.Severity.value.ToCstr
// Convert numeric value of field to one of predefined string constants.
// If string is found, return a static C string. Otherwise, return NULL.
const char* fm::value_ToCstr(const fm::Severity& parent) {
    const char *ret = NULL;
    switch(value_GetEnum(parent)) {
        case fm_Severity_value_critical    : ret = "critical";  break;
        case fm_Severity_value_major       : ret = "major";  break;
        case fm_Severity_value_minor       : ret = "minor";  break;
    }
    return ret;
}

// --- fm.Severity.value.Print
// Convert value to a string. First, attempt conversion to a known string.
// If no string matches, print value as a numeric value.
void fm::value_Print(const fm::Severity& parent, algo::cstring &lhs) {
    const char *strval = value_ToCstr(parent);
    if (strval) {
        lhs << strval;
    } else {
        lhs << parent.value;
    }
}

// --- fm.Severity.value.SetStrptrMaybe
// Convert string to field.
// If the string is invalid, do not modify field and return false.
// In case of success, return true
bool fm::value_SetStrptrMaybe(fm::Severity& parent, algo::strptr rhs) {
    bool ret = false;
    switch (elems_N(rhs)) {
        case 5: {
            switch (u64(algo::ReadLE32(rhs.elems))|(u64(rhs[4])<<32)) {
                case LE_STR5('m','a','j','o','r'): {
                    value_SetEnum(parent,fm_Severity_value_major); ret = true; break;
                }
                case LE_STR5('m','i','n','o','r'): {
                    value_SetEnum(parent,fm_Severity_value_minor); ret = true; break;
                }
            }
            break;
        }
        case 8: {
            switch (algo::ReadLE64(rhs.elems)) {
                case LE_STR8('c','r','i','t','i','c','a','l'): {
                    value_SetEnum(parent,fm_Severity_value_critical); ret = true; break;
                }
            }
            break;
        }
    }
    return ret;
}

// --- fm.Severity.value.SetStrptr
// Convert string to field.
// If the string is invalid, set numeric value to DFLT
void fm::value_SetStrptr(fm::Severity& parent, algo::strptr rhs, fm_Severity_value_Enum dflt) {
    if (!value_SetStrptrMaybe(parent,rhs)) value_SetEnum(parent,dflt);
}

// --- fm.Severity.value.ReadStrptrMaybe
// Convert string to field. Return success value
bool fm::value_ReadStrptrMaybe(fm::Severity& parent, algo::strptr rhs) {
    bool retval = false;
    retval = value_SetStrptrMaybe(parent,rhs); // try symbol conversion
    if (!retval) { // didn't work? try reading as underlying type
        retval = char_ReadStrptrMaybe(parent.value,rhs);
    }
    return retval;
}

// --- fm.Severity..ReadStrptrMaybe
// Read fields of fm::Severity from an ascii string.
// The format of the string is the format of the fm::Severity's only field
bool fm::Severity_ReadStrptrMaybe(fm::Severity &parent, algo::strptr in_str) {
    bool retval = true;
    retval = retval && value_ReadStrptrMaybe(parent, in_str);
    return retval;
}

// --- fm.Severity..Print
// print string representation of fm::Severity to string LHS, no header -- cprint:fm.Severity.String
void fm::Severity_Print(fm::Severity row, algo::cstring &str) {
    fm::value_Print(row, str);
}

// --- fm.Summary.ch.Print
void fm::ch_Print(fm::Summary& parent, algo::cstring &out) {
    ch_Addary(out, ch_Getary(parent));
}

// --- fm.Summary.ch.ReadStrptrMaybe
// Convert string to field. Return success value
bool fm::ch_ReadStrptrMaybe(fm::Summary& parent, algo::strptr rhs) {
    bool retval = false;
    if (rhs.n_elems <= 64) {
        ch_SetStrptr(parent, rhs);
        retval = true;
    } else {
        algo_lib::SaveBadTag("comment","text too long, limit 64");
    }
    return retval;
}

// --- fm.Summary.ch.SetStrptr
// Copy from strptr, clipping length
// Set string to the value provided by RHS.
// If RHS is too large, it is silently clipped.
void fm::ch_SetStrptr(fm::Summary& parent, const algo::strptr &rhs) {
    int len = i32_Min(rhs.n_elems, 64);
    char *rhs_elems = rhs.elems;
    int i = 0;
    int j = 0;
    for (; i < len; i++, j++) {
        parent.ch[j] = rhs_elems[i];
    }
    for (; j < 64; j++) {
        parent.ch[j] = ' ';
    }
}

// --- fm.Summary..Hash
u32 fm::Summary_Hash(u32 prev, const fm::Summary & rhs) {
    algo::strptr ch_strptr = ch_Getary(rhs);
    prev = ::strptr_Hash(prev, ch_strptr);
    return prev;
}

// --- fm.Summary..ReadStrptrMaybe
// Read fields of fm::Summary from an ascii string.
// The format of the string is the format of the fm::Summary's only field
bool fm::Summary_ReadStrptrMaybe(fm::Summary &parent, algo::strptr in_str) {
    bool retval = true;
    retval = retval && ch_ReadStrptrMaybe(parent, in_str);
    return retval;
}

// --- fm.Summary..Print
// print string representation of fm::Summary to string LHS, no header -- cprint:fm.Summary.String
void fm::Summary_Print(fm::Summary & row, algo::cstring &str) {
    fm::ch_Print(row, str);
}

// --- fm.Description.ch.Print
void fm::ch_Print(fm::Description& parent, algo::cstring &out) {
    ch_Addary(out, ch_Getary(parent));
}

// --- fm.Description.ch.ReadStrptrMaybe
// Convert string to field. Return success value
bool fm::ch_ReadStrptrMaybe(fm::Description& parent, algo::strptr rhs) {
    bool retval = false;
    if (rhs.n_elems <= 128) {
        ch_SetStrptr(parent, rhs);
        retval = true;
    } else {
        algo_lib::SaveBadTag("comment","text too long, limit 128");
    }
    return retval;
}

// --- fm.Description.ch.SetStrptr
// Copy from strptr, clipping length
// Set string to the value provided by RHS.
// If RHS is too large, it is silently clipped.
void fm::ch_SetStrptr(fm::Description& parent, const algo::strptr &rhs) {
    int len = i32_Min(rhs.n_elems, 128);
    char *rhs_elems = rhs.elems;
    int i = 0;
    int j = 0;
    for (; i < len; i++, j++) {
        parent.ch[j] = rhs_elems[i];
    }
    for (; j < 128; j++) {
        parent.ch[j] = ' ';
    }
}

// --- fm.Description..Hash
u32 fm::Description_Hash(u32 prev, const fm::Description & rhs) {
    algo::strptr ch_strptr = ch_Getary(rhs);
    prev = ::strptr_Hash(prev, ch_strptr);
    return prev;
}

// --- fm.Description..ReadStrptrMaybe
// Read fields of fm::Description from an ascii string.
// The format of the string is the format of the fm::Description's only field
bool fm::Description_ReadStrptrMaybe(fm::Description &parent, algo::strptr in_str) {
    bool retval = true;
    retval = retval && ch_ReadStrptrMaybe(parent, in_str);
    return retval;
}

// --- fm.Description..Print
// print string representation of fm::Description to string LHS, no header -- cprint:fm.Description.String
void fm::Description_Print(fm::Description & row, algo::cstring &str) {
    fm::ch_Print(row, str);
}

// --- fm.Source.ch.Print
void fm::ch_Print(fm::Source& parent, algo::cstring &out) {
    ch_Addary(out, ch_Getary(parent));
}

// --- fm.Source.ch.ReadStrptrMaybe
// Convert string to field. Return success value
bool fm::ch_ReadStrptrMaybe(fm::Source& parent, algo::strptr rhs) {
    bool retval = false;
    if (rhs.n_elems <= 32) {
        ch_SetStrptr(parent, rhs);
        retval = true;
    } else {
        algo_lib::SaveBadTag("comment","text too long, limit 32");
    }
    return retval;
}

// --- fm.Source.ch.SetStrptr
// Copy from strptr, clipping length
// Set string to the value provided by RHS.
// If RHS is too large, it is silently clipped.
void fm::ch_SetStrptr(fm::Source& parent, const algo::strptr &rhs) {
    int len = i32_Min(rhs.n_elems, 32);
    char *rhs_elems = rhs.elems;
    int i = 0;
    int j = 0;
    for (; i < len; i++, j++) {
        parent.ch[j] = rhs_elems[i];
    }
    for (; j < 32; j++) {
        parent.ch[j] = ' ';
    }
}

// --- fm.Source..Hash
u32 fm::Source_Hash(u32 prev, const fm::Source & rhs) {
    algo::strptr ch_strptr = ch_Getary(rhs);
    prev = ::strptr_Hash(prev, ch_strptr);
    return prev;
}

// --- fm.Source..ReadStrptrMaybe
// Read fields of fm::Source from an ascii string.
// The format of the string is the format of the fm::Source's only field
bool fm::Source_ReadStrptrMaybe(fm::Source &parent, algo::strptr in_str) {
    bool retval = true;
    retval = retval && ch_ReadStrptrMaybe(parent, in_str);
    return retval;
}

// --- fm.Source..Print
// print string representation of fm::Source to string LHS, no header -- cprint:fm.Source.String
void fm::Source_Print(fm::Source & row, algo::cstring &str) {
    fm::ch_Print(row, str);
}

// --- fm.AlarmMsg.base.CopyOut
// Copy fields out of row
void fm::parent_CopyOut(fm::AlarmMsg &row, ams::MsgHeader &out) {
    // type: field value is computed
    // length: field value is computed
    (void)row;//only to avoid -Wunused-parameter
    (void)out;//only to avoid -Wunused-parameter
}

// --- fm.AlarmMsg..ReadFieldMaybe
bool fm::AlarmMsg_ReadFieldMaybe(fm::AlarmMsg &parent, algo::strptr field, algo::strptr strval) {
    fm::FieldId field_id;
    (void)value_SetStrptrMaybe(field_id,field);
    bool retval = true; // default is no error
    switch(field_id) {
        case fm_FieldId_base: retval = false; break;
        case fm_FieldId_type: retval = false; break;
        case fm_FieldId_length: retval = false; break;
        case fm_FieldId_code: retval = fm::Code_ReadStrptrMaybe(parent.code, strval); break;
        case fm_FieldId_objtype: retval = fm::Objtype_ReadStrptrMaybe(parent.objtype, strval); break;
        case fm_FieldId_objinst: retval = fm::Objinst_ReadStrptrMaybe(parent.objinst, strval); break;
        case fm_FieldId_flag: retval = fm::Flag_ReadStrptrMaybe(parent.flag, strval); break;
        case fm_FieldId_severity: retval = fm::Severity_ReadStrptrMaybe(parent.severity, strval); break;
        case fm_FieldId_n_occurred: retval = i32_ReadStrptrMaybe(parent.n_occurred, strval); break;
        case fm_FieldId_first_time: retval = algo::UnTime_ReadStrptrMaybe(parent.first_time, strval); break;
        case fm_FieldId_last_time: retval = algo::UnTime_ReadStrptrMaybe(parent.last_time, strval); break;
        case fm_FieldId_clear_time: retval = algo::UnTime_ReadStrptrMaybe(parent.clear_time, strval); break;
        case fm_FieldId_update_time: retval = algo::UnTime_ReadStrptrMaybe(parent.update_time, strval); break;
        case fm_FieldId_objtype_summary: retval = fm::Summary_ReadStrptrMaybe(parent.objtype_summary, strval); break;
        case fm_FieldId_summary: retval = fm::Summary_ReadStrptrMaybe(parent.summary, strval); break;
        case fm_FieldId_description: retval = fm::Description_ReadStrptrMaybe(parent.description, strval); break;
        case fm_FieldId_source: retval = fm::Source_ReadStrptrMaybe(parent.source, strval); break;
        default: break;
    }
    if (!retval) {
        algo_lib::AppendErrtext("attr",field);
    }
    return retval;
}

// --- fm.AlarmMsg..ReadStrptrMaybe
// Read fields of fm::AlarmMsg from an ascii string.
// The format of the string is an ssim Tuple
bool fm::AlarmMsg_ReadStrptrMaybe(fm::AlarmMsg &parent, algo::strptr in_str) {
    bool retval = true;
    retval = algo::StripTypeTag(in_str, "fm.AlarmMsg");
    ind_beg(algo::Attr_curs, attr, in_str) {
        retval = retval && AlarmMsg_ReadFieldMaybe(parent, attr.name, attr.value);
    }ind_end;
    return retval;
}

// --- fm.AlarmMsg..Init
// Set all fields to initial values.
void fm::AlarmMsg_Init(fm::AlarmMsg& parent) {
    parent.type = u32(17);
    parent.length = u32(ssizeof(parent) + (0));
    parent.n_occurred = i32(0);
}

// --- fm.AlarmMsg..Print
// print string representation of fm::AlarmMsg to string LHS, no header -- cprint:fm.AlarmMsg.String
void fm::AlarmMsg_Print(fm::AlarmMsg & row, algo::cstring &str) {
    algo::tempstr temp;
    str << "fm.AlarmMsg";

    fm::Code_Print(row.code, temp);
    PrintAttrSpaceReset(str,"code", temp);

    fm::Objtype_Print(row.objtype, temp);
    PrintAttrSpaceReset(str,"objtype", temp);

    fm::Objinst_Print(row.objinst, temp);
    PrintAttrSpaceReset(str,"objinst", temp);

    fm::Flag_Print(row.flag, temp);
    PrintAttrSpaceReset(str,"flag", temp);

    fm::Severity_Print(row.severity, temp);
    PrintAttrSpaceReset(str,"severity", temp);

    i32_Print(row.n_occurred, temp);
    PrintAttrSpaceReset(str,"n_occurred", temp);

    algo::UnTime_Print(row.first_time, temp);
    PrintAttrSpaceReset(str,"first_time", temp);

    algo::UnTime_Print(row.last_time, temp);
    PrintAttrSpaceReset(str,"last_time", temp);

    algo::UnTime_Print(row.clear_time, temp);
    PrintAttrSpaceReset(str,"clear_time", temp);

    algo::UnTime_Print(row.update_time, temp);
    PrintAttrSpaceReset(str,"update_time", temp);

    fm::Summary_Print(row.objtype_summary, temp);
    PrintAttrSpaceReset(str,"objtype_summary", temp);

    fm::Summary_Print(row.summary, temp);
    PrintAttrSpaceReset(str,"summary", temp);

    fm::Description_Print(row.description, temp);
    PrintAttrSpaceReset(str,"description", temp);

    fm::Source_Print(row.source, temp);
    PrintAttrSpaceReset(str,"source", temp);
}

// --- fm.FieldId.value.ToCstr
// Convert numeric value of field to one of predefined string constants.
// If string is found, return a static C string. Otherwise, return NULL.
const char* fm::value_ToCstr(const fm::FieldId& parent) {
    const char *ret = NULL;
    switch(value_GetEnum(parent)) {
        case fm_FieldId_base               : ret = "base";  break;
        case fm_FieldId_type               : ret = "type";  break;
        case fm_FieldId_length             : ret = "length";  break;
        case fm_FieldId_code               : ret = "code";  break;
        case fm_FieldId_objtype            : ret = "objtype";  break;
        case fm_FieldId_objinst            : ret = "objinst";  break;
        case fm_FieldId_flag               : ret = "flag";  break;
        case fm_FieldId_severity           : ret = "severity";  break;
        case fm_FieldId_n_occurred         : ret = "n_occurred";  break;
        case fm_FieldId_first_time         : ret = "first_time";  break;
        case fm_FieldId_last_time          : ret = "last_time";  break;
        case fm_FieldId_clear_time         : ret = "clear_time";  break;
        case fm_FieldId_update_time        : ret = "update_time";  break;
        case fm_FieldId_objtype_summary    : ret = "objtype_summary";  break;
        case fm_FieldId_summary            : ret = "summary";  break;
        case fm_FieldId_description        : ret = "description";  break;
        case fm_FieldId_source             : ret = "source";  break;
        case fm_FieldId_ch                 : ret = "ch";  break;
        case fm_FieldId_value              : ret = "value";  break;
    }
    return ret;
}

// --- fm.FieldId.value.Print
// Convert value to a string. First, attempt conversion to a known string.
// If no string matches, print value as a numeric value.
void fm::value_Print(const fm::FieldId& parent, algo::cstring &lhs) {
    const char *strval = value_ToCstr(parent);
    if (strval) {
        lhs << strval;
    } else {
        lhs << parent.value;
    }
}

// --- fm.FieldId.value.SetStrptrMaybe
// Convert string to field.
// If the string is invalid, do not modify field and return false.
// In case of success, return true
bool fm::value_SetStrptrMaybe(fm::FieldId& parent, algo::strptr rhs) {
    bool ret = false;
    switch (elems_N(rhs)) {
        case 2: {
            switch (u64(algo::ReadLE16(rhs.elems))) {
                case LE_STR2('c','h'): {
                    value_SetEnum(parent,fm_FieldId_ch); ret = true; break;
                }
            }
            break;
        }
        case 4: {
            switch (u64(algo::ReadLE32(rhs.elems))) {
                case LE_STR4('b','a','s','e'): {
                    value_SetEnum(parent,fm_FieldId_base); ret = true; break;
                }
                case LE_STR4('c','o','d','e'): {
                    value_SetEnum(parent,fm_FieldId_code); ret = true; break;
                }
                case LE_STR4('f','l','a','g'): {
                    value_SetEnum(parent,fm_FieldId_flag); ret = true; break;
                }
                case LE_STR4('t','y','p','e'): {
                    value_SetEnum(parent,fm_FieldId_type); ret = true; break;
                }
            }
            break;
        }
        case 5: {
            switch (u64(algo::ReadLE32(rhs.elems))|(u64(rhs[4])<<32)) {
                case LE_STR5('v','a','l','u','e'): {
                    value_SetEnum(parent,fm_FieldId_value); ret = true; break;
                }
            }
            break;
        }
        case 6: {
            switch (u64(algo::ReadLE32(rhs.elems))|(u64(algo::ReadLE16(rhs.elems+4))<<32)) {
                case LE_STR6('l','e','n','g','t','h'): {
                    value_SetEnum(parent,fm_FieldId_length); ret = true; break;
                }
                case LE_STR6('s','o','u','r','c','e'): {
                    value_SetEnum(parent,fm_FieldId_source); ret = true; break;
                }
            }
            break;
        }
        case 7: {
            switch (u64(algo::ReadLE32(rhs.elems))|(u64(algo::ReadLE16(rhs.elems+4))<<32)|(u64(rhs[6])<<48)) {
                case LE_STR7('o','b','j','i','n','s','t'): {
                    value_SetEnum(parent,fm_FieldId_objinst); ret = true; break;
                }
                case LE_STR7('o','b','j','t','y','p','e'): {
                    value_SetEnum(parent,fm_FieldId_objtype); ret = true; break;
                }
                case LE_STR7('s','u','m','m','a','r','y'): {
                    value_SetEnum(parent,fm_FieldId_summary); ret = true; break;
                }
            }
            break;
        }
        case 8: {
            switch (algo::ReadLE64(rhs.elems)) {
                case LE_STR8('s','e','v','e','r','i','t','y'): {
                    value_SetEnum(parent,fm_FieldId_severity); ret = true; break;
                }
            }
            break;
        }
        case 9: {
            switch (algo::ReadLE64(rhs.elems)) {
                case LE_STR8('l','a','s','t','_','t','i','m'): {
                    if (memcmp(rhs.elems+8,"e",1)==0) { value_SetEnum(parent,fm_FieldId_last_time); ret = true; break; }
                    break;
                }
            }
            break;
        }
        case 10: {
            switch (algo::ReadLE64(rhs.elems)) {
                case LE_STR8('c','l','e','a','r','_','t','i'): {
                    if (memcmp(rhs.elems+8,"me",2)==0) { value_SetEnum(parent,fm_FieldId_clear_time); ret = true; break; }
                    break;
                }
                case LE_STR8('f','i','r','s','t','_','t','i'): {
                    if (memcmp(rhs.elems+8,"me",2)==0) { value_SetEnum(parent,fm_FieldId_first_time); ret = true; break; }
                    break;
                }
                case LE_STR8('n','_','o','c','c','u','r','r'): {
                    if (memcmp(rhs.elems+8,"ed",2)==0) { value_SetEnum(parent,fm_FieldId_n_occurred); ret = true; break; }
                    break;
                }
            }
            break;
        }
        case 11: {
            switch (algo::ReadLE64(rhs.elems)) {
                case LE_STR8('d','e','s','c','r','i','p','t'): {
                    if (memcmp(rhs.elems+8,"ion",3)==0) { value_SetEnum(parent,fm_FieldId_description); ret = true; break; }
                    break;
                }
                case LE_STR8('u','p','d','a','t','e','_','t'): {
                    if (memcmp(rhs.elems+8,"ime",3)==0) { value_SetEnum(parent,fm_FieldId_update_time); ret = true; break; }
                    break;
                }
            }
            break;
        }
        case 15: {
            switch (algo::ReadLE64(rhs.elems)) {
                case LE_STR8('o','b','j','t','y','p','e','_'): {
                    if (memcmp(rhs.elems+8,"summary",7)==0) { value_SetEnum(parent,fm_FieldId_objtype_summary); ret = true; break; }
                    break;
                }
            }
            break;
        }
    }
    return ret;
}

// --- fm.FieldId.value.SetStrptr
// Convert string to field.
// If the string is invalid, set numeric value to DFLT
void fm::value_SetStrptr(fm::FieldId& parent, algo::strptr rhs, fm_FieldIdEnum dflt) {
    if (!value_SetStrptrMaybe(parent,rhs)) value_SetEnum(parent,dflt);
}

// --- fm.FieldId.value.ReadStrptrMaybe
// Convert string to field. Return success value
bool fm::value_ReadStrptrMaybe(fm::FieldId& parent, algo::strptr rhs) {
    bool retval = false;
    retval = value_SetStrptrMaybe(parent,rhs); // try symbol conversion
    if (!retval) { // didn't work? try reading as underlying type
        retval = i32_ReadStrptrMaybe(parent.value,rhs);
    }
    return retval;
}

// --- fm.FieldId..ReadStrptrMaybe
// Read fields of fm::FieldId from an ascii string.
// The format of the string is the format of the fm::FieldId's only field
bool fm::FieldId_ReadStrptrMaybe(fm::FieldId &parent, algo::strptr in_str) {
    bool retval = true;
    retval = retval && value_ReadStrptrMaybe(parent, in_str);
    return retval;
}

// --- fm.FieldId..Print
// print string representation of fm::FieldId to string LHS, no header -- cprint:fm.FieldId.String
void fm::FieldId_Print(fm::FieldId & row, algo::cstring &str) {
    fm::value_Print(row, str);
}

// --- fm.Protocol.proto.StaticCheck
void fm::StaticCheck() {
    algo_assert(_offset_of(fm::Flag, value) + sizeof(((fm::Flag*)0)->value) == sizeof(fm::Flag));
    algo_assert(_offset_of(fm::Severity, value) + sizeof(((fm::Severity*)0)->value) == sizeof(fm::Severity));
    algo_assert(_offset_of(fm::AlarmMsg, source) + sizeof(((fm::AlarmMsg*)0)->source) == sizeof(fm::AlarmMsg));
    algo_assert(_offset_of(fm::FieldId, value) + sizeof(((fm::FieldId*)0)->value) == sizeof(fm::FieldId));
}

// --- fm...SizeCheck
inline static void fm::SizeCheck() {
}
