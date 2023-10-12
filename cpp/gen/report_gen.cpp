//
// cpp/gen/report_gen.cpp
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
#include "include/gen/report_gen.h"
#include "include/gen/report_gen.inl.h"
#include "include/gen/algo_gen.h"
#include "include/gen/algo_gen.inl.h"
//#pragma endinclude
namespace report { // gen:ns_print_proto
    static void          SizeCheck();
} // gen:ns_print_proto

// --- report.FieldId.value.ToCstr
// Convert numeric value of field to one of predefined string constants.
// If string is found, return a static C string. Otherwise, return NULL.
const char* report::value_ToCstr(const report::FieldId& parent) {
    const char *ret = NULL;
    switch(value_GetEnum(parent)) {
        case report_FieldId_n_target       : ret = "n_target";  break;
        case report_FieldId_time           : ret = "time";  break;
        case report_FieldId_n_warn         : ret = "n_warn";  break;
        case report_FieldId_n_err          : ret = "n_err";  break;
        case report_FieldId_n_install      : ret = "n_install";  break;
        case report_FieldId_n_select       : ret = "n_select";  break;
        case report_FieldId_n_insert       : ret = "n_insert";  break;
        case report_FieldId_n_delete       : ret = "n_delete";  break;
        case report_FieldId_n_update       : ret = "n_update";  break;
        case report_FieldId_n_file_mod     : ret = "n_file_mod";  break;
        case report_FieldId_records        : ret = "records";  break;
        case report_FieldId_errors         : ret = "errors";  break;
        case report_FieldId_n_cppfile      : ret = "n_cppfile";  break;
        case report_FieldId_n_cppline      : ret = "n_cppline";  break;
        case report_FieldId_n_ctype        : ret = "n_ctype";  break;
        case report_FieldId_n_func         : ret = "n_func";  break;
        case report_FieldId_n_xref         : ret = "n_xref";  break;
        case report_FieldId_n_filemod      : ret = "n_filemod";  break;
        case report_FieldId_ntest          : ret = "ntest";  break;
        case report_FieldId_nselect        : ret = "nselect";  break;
        case report_FieldId_npass          : ret = "npass";  break;
        case report_FieldId_nskip          : ret = "nskip";  break;
        case report_FieldId_nrun           : ret = "nrun";  break;
        case report_FieldId_nwrite         : ret = "nwrite";  break;
        case report_FieldId_nerr           : ret = "nerr";  break;
        case report_FieldId_ninsert        : ret = "ninsert";  break;
        case report_FieldId_success        : ret = "success";  break;
        case report_FieldId_n_test_total   : ret = "n_test_total";  break;
        case report_FieldId_n_test_run     : ret = "n_test_run";  break;
        case report_FieldId_n_line         : ret = "n_line";  break;
        case report_FieldId_n_static       : ret = "n_static";  break;
        case report_FieldId_n_inline       : ret = "n_inline";  break;
        case report_FieldId_n_mysteryfunc  : ret = "n_mysteryfunc";  break;
        case report_FieldId_n_baddecl      : ret = "n_baddecl";  break;
        case report_FieldId_comment        : ret = "comment";  break;
        case report_FieldId_value          : ret = "value";  break;
    }
    return ret;
}

// --- report.FieldId.value.Print
// Convert value to a string. First, attempt conversion to a known string.
// If no string matches, print value as a numeric value.
void report::value_Print(const report::FieldId& parent, algo::cstring &lhs) {
    const char *strval = value_ToCstr(parent);
    if (strval) {
        lhs << strval;
    } else {
        lhs << parent.value;
    }
}

// --- report.FieldId.value.SetStrptrMaybe
// Convert string to field.
// If the string is invalid, do not modify field and return false.
// In case of success, return true
bool report::value_SetStrptrMaybe(report::FieldId& parent, algo::strptr rhs) {
    bool ret = false;
    switch (elems_N(rhs)) {
        case 4: {
            switch (u64(algo::ReadLE32(rhs.elems))) {
                case LE_STR4('n','e','r','r'): {
                    value_SetEnum(parent,report_FieldId_nerr); ret = true; break;
                }
                case LE_STR4('n','r','u','n'): {
                    value_SetEnum(parent,report_FieldId_nrun); ret = true; break;
                }
                case LE_STR4('t','i','m','e'): {
                    value_SetEnum(parent,report_FieldId_time); ret = true; break;
                }
            }
            break;
        }
        case 5: {
            switch (u64(algo::ReadLE32(rhs.elems))|(u64(rhs[4])<<32)) {
                case LE_STR5('n','_','e','r','r'): {
                    value_SetEnum(parent,report_FieldId_n_err); ret = true; break;
                }
                case LE_STR5('n','p','a','s','s'): {
                    value_SetEnum(parent,report_FieldId_npass); ret = true; break;
                }
                case LE_STR5('n','s','k','i','p'): {
                    value_SetEnum(parent,report_FieldId_nskip); ret = true; break;
                }
                case LE_STR5('n','t','e','s','t'): {
                    value_SetEnum(parent,report_FieldId_ntest); ret = true; break;
                }
                case LE_STR5('v','a','l','u','e'): {
                    value_SetEnum(parent,report_FieldId_value); ret = true; break;
                }
            }
            break;
        }
        case 6: {
            switch (u64(algo::ReadLE32(rhs.elems))|(u64(algo::ReadLE16(rhs.elems+4))<<32)) {
                case LE_STR6('e','r','r','o','r','s'): {
                    value_SetEnum(parent,report_FieldId_errors); ret = true; break;
                }
                case LE_STR6('n','_','f','u','n','c'): {
                    value_SetEnum(parent,report_FieldId_n_func); ret = true; break;
                }
                case LE_STR6('n','_','l','i','n','e'): {
                    value_SetEnum(parent,report_FieldId_n_line); ret = true; break;
                }
                case LE_STR6('n','_','w','a','r','n'): {
                    value_SetEnum(parent,report_FieldId_n_warn); ret = true; break;
                }
                case LE_STR6('n','_','x','r','e','f'): {
                    value_SetEnum(parent,report_FieldId_n_xref); ret = true; break;
                }
                case LE_STR6('n','w','r','i','t','e'): {
                    value_SetEnum(parent,report_FieldId_nwrite); ret = true; break;
                }
            }
            break;
        }
        case 7: {
            switch (u64(algo::ReadLE32(rhs.elems))|(u64(algo::ReadLE16(rhs.elems+4))<<32)|(u64(rhs[6])<<48)) {
                case LE_STR7('c','o','m','m','e','n','t'): {
                    value_SetEnum(parent,report_FieldId_comment); ret = true; break;
                }
                case LE_STR7('n','_','c','t','y','p','e'): {
                    value_SetEnum(parent,report_FieldId_n_ctype); ret = true; break;
                }
                case LE_STR7('n','i','n','s','e','r','t'): {
                    value_SetEnum(parent,report_FieldId_ninsert); ret = true; break;
                }
                case LE_STR7('n','s','e','l','e','c','t'): {
                    value_SetEnum(parent,report_FieldId_nselect); ret = true; break;
                }
                case LE_STR7('r','e','c','o','r','d','s'): {
                    value_SetEnum(parent,report_FieldId_records); ret = true; break;
                }
                case LE_STR7('s','u','c','c','e','s','s'): {
                    value_SetEnum(parent,report_FieldId_success); ret = true; break;
                }
            }
            break;
        }
        case 8: {
            switch (algo::ReadLE64(rhs.elems)) {
                case LE_STR8('n','_','d','e','l','e','t','e'): {
                    value_SetEnum(parent,report_FieldId_n_delete); ret = true; break;
                }
                case LE_STR8('n','_','i','n','l','i','n','e'): {
                    value_SetEnum(parent,report_FieldId_n_inline); ret = true; break;
                }
                case LE_STR8('n','_','i','n','s','e','r','t'): {
                    value_SetEnum(parent,report_FieldId_n_insert); ret = true; break;
                }
                case LE_STR8('n','_','s','e','l','e','c','t'): {
                    value_SetEnum(parent,report_FieldId_n_select); ret = true; break;
                }
                case LE_STR8('n','_','s','t','a','t','i','c'): {
                    value_SetEnum(parent,report_FieldId_n_static); ret = true; break;
                }
                case LE_STR8('n','_','t','a','r','g','e','t'): {
                    value_SetEnum(parent,report_FieldId_n_target); ret = true; break;
                }
                case LE_STR8('n','_','u','p','d','a','t','e'): {
                    value_SetEnum(parent,report_FieldId_n_update); ret = true; break;
                }
            }
            break;
        }
        case 9: {
            switch (algo::ReadLE64(rhs.elems)) {
                case LE_STR8('n','_','b','a','d','d','e','c'): {
                    if (memcmp(rhs.elems+8,"l",1)==0) { value_SetEnum(parent,report_FieldId_n_baddecl); ret = true; break; }
                    break;
                }
                case LE_STR8('n','_','c','p','p','f','i','l'): {
                    if (memcmp(rhs.elems+8,"e",1)==0) { value_SetEnum(parent,report_FieldId_n_cppfile); ret = true; break; }
                    break;
                }
                case LE_STR8('n','_','c','p','p','l','i','n'): {
                    if (memcmp(rhs.elems+8,"e",1)==0) { value_SetEnum(parent,report_FieldId_n_cppline); ret = true; break; }
                    break;
                }
                case LE_STR8('n','_','f','i','l','e','m','o'): {
                    if (memcmp(rhs.elems+8,"d",1)==0) { value_SetEnum(parent,report_FieldId_n_filemod); ret = true; break; }
                    break;
                }
                case LE_STR8('n','_','i','n','s','t','a','l'): {
                    if (memcmp(rhs.elems+8,"l",1)==0) { value_SetEnum(parent,report_FieldId_n_install); ret = true; break; }
                    break;
                }
            }
            break;
        }
        case 10: {
            switch (algo::ReadLE64(rhs.elems)) {
                case LE_STR8('n','_','f','i','l','e','_','m'): {
                    if (memcmp(rhs.elems+8,"od",2)==0) { value_SetEnum(parent,report_FieldId_n_file_mod); ret = true; break; }
                    break;
                }
                case LE_STR8('n','_','t','e','s','t','_','r'): {
                    if (memcmp(rhs.elems+8,"un",2)==0) { value_SetEnum(parent,report_FieldId_n_test_run); ret = true; break; }
                    break;
                }
            }
            break;
        }
        case 12: {
            switch (algo::ReadLE64(rhs.elems)) {
                case LE_STR8('n','_','t','e','s','t','_','t'): {
                    if (memcmp(rhs.elems+8,"otal",4)==0) { value_SetEnum(parent,report_FieldId_n_test_total); ret = true; break; }
                    break;
                }
            }
            break;
        }
        case 13: {
            switch (algo::ReadLE64(rhs.elems)) {
                case LE_STR8('n','_','m','y','s','t','e','r'): {
                    if (memcmp(rhs.elems+8,"yfunc",5)==0) { value_SetEnum(parent,report_FieldId_n_mysteryfunc); ret = true; break; }
                    break;
                }
            }
            break;
        }
    }
    return ret;
}

// --- report.FieldId.value.SetStrptr
// Convert string to field.
// If the string is invalid, set numeric value to DFLT
void report::value_SetStrptr(report::FieldId& parent, algo::strptr rhs, report_FieldIdEnum dflt) {
    if (!value_SetStrptrMaybe(parent,rhs)) value_SetEnum(parent,dflt);
}

// --- report.FieldId.value.ReadStrptrMaybe
// Convert string to field. Return success value
bool report::value_ReadStrptrMaybe(report::FieldId& parent, algo::strptr rhs) {
    bool retval = false;
    retval = value_SetStrptrMaybe(parent,rhs); // try symbol conversion
    if (!retval) { // didn't work? try reading as underlying type
        retval = i32_ReadStrptrMaybe(parent.value,rhs);
    }
    return retval;
}

// --- report.FieldId..ReadStrptrMaybe
// Read fields of report::FieldId from an ascii string.
// The format of the string is the format of the report::FieldId's only field
bool report::FieldId_ReadStrptrMaybe(report::FieldId &parent, algo::strptr in_str) {
    bool retval = true;
    retval = retval && value_ReadStrptrMaybe(parent, in_str);
    return retval;
}

// --- report.FieldId..Print
// print string representation of report::FieldId to string LHS, no header -- cprint:report.FieldId.String
void report::FieldId_Print(report::FieldId & row, algo::cstring &str) {
    report::value_Print(row, str);
}

// --- report.Protocol.proto.StaticCheck
void report::StaticCheck() {
    algo_assert(_offset_of(report::FieldId, value) + sizeof(((report::FieldId*)0)->value) == sizeof(report::FieldId));
}

// --- report.abt..ReadFieldMaybe
bool report::abt_ReadFieldMaybe(report::abt &parent, algo::strptr field, algo::strptr strval) {
    report::FieldId field_id;
    (void)value_SetStrptrMaybe(field_id,field);
    bool retval = true; // default is no error
    switch(field_id) {
        case report_FieldId_n_target: retval = u16_ReadStrptrMaybe(parent.n_target, strval); break;
        case report_FieldId_time: retval = algo::UnDiff_ReadStrptrMaybe(parent.time, strval); break;
        case report_FieldId_n_warn: retval = u32_ReadStrptrMaybe(parent.n_warn, strval); break;
        case report_FieldId_n_err: retval = u32_ReadStrptrMaybe(parent.n_err, strval); break;
        case report_FieldId_n_install: retval = u16_ReadStrptrMaybe(parent.n_install, strval); break;
        default: break;
    }
    if (!retval) {
        algo_lib::AppendErrtext("attr",field);
    }
    return retval;
}

// --- report.abt..ReadStrptrMaybe
// Read fields of report::abt from an ascii string.
// The format of the string is an ssim Tuple
bool report::abt_ReadStrptrMaybe(report::abt &parent, algo::strptr in_str) {
    bool retval = true;
    retval = algo::StripTypeTag(in_str, "report.abt");
    ind_beg(algo::Attr_curs, attr, in_str) {
        retval = retval && abt_ReadFieldMaybe(parent, attr.name, attr.value);
    }ind_end;
    return retval;
}

// --- report.abt..Print
// print string representation of report::abt to string LHS, no header -- cprint:report.abt.String
void report::abt_Print(report::abt & row, algo::cstring &str) {
    algo::tempstr temp;
    str << "report.abt";

    u16_Print(row.n_target, temp);
    PrintAttrSpaceReset(str,"n_target", temp);

    algo::UnDiff_Print(row.time, temp);
    PrintAttrSpaceReset(str,"time", temp);

    u32_Print(row.n_warn, temp);
    PrintAttrSpaceReset(str,"n_warn", temp);

    u32_Print(row.n_err, temp);
    PrintAttrSpaceReset(str,"n_err", temp);

    u16_Print(row.n_install, temp);
    PrintAttrSpaceReset(str,"n_install", temp);
}

// --- report.acr..ReadFieldMaybe
bool report::acr_ReadFieldMaybe(report::acr &parent, algo::strptr field, algo::strptr strval) {
    report::FieldId field_id;
    (void)value_SetStrptrMaybe(field_id,field);
    bool retval = true; // default is no error
    switch(field_id) {
        case report_FieldId_n_select: retval = u32_ReadStrptrMaybe(parent.n_select, strval); break;
        case report_FieldId_n_insert: retval = u32_ReadStrptrMaybe(parent.n_insert, strval); break;
        case report_FieldId_n_delete: retval = u32_ReadStrptrMaybe(parent.n_delete, strval); break;
        case report_FieldId_n_update: retval = u32_ReadStrptrMaybe(parent.n_update, strval); break;
        case report_FieldId_n_file_mod: retval = u32_ReadStrptrMaybe(parent.n_file_mod, strval); break;
        default: break;
    }
    if (!retval) {
        algo_lib::AppendErrtext("attr",field);
    }
    return retval;
}

// --- report.acr..ReadStrptrMaybe
// Read fields of report::acr from an ascii string.
// The format of the string is an ssim Tuple
bool report::acr_ReadStrptrMaybe(report::acr &parent, algo::strptr in_str) {
    bool retval = true;
    retval = algo::StripTypeTag(in_str, "report.acr");
    ind_beg(algo::Attr_curs, attr, in_str) {
        retval = retval && acr_ReadFieldMaybe(parent, attr.name, attr.value);
    }ind_end;
    return retval;
}

// --- report.acr..Print
// print string representation of report::acr to string LHS, no header -- cprint:report.acr.String
void report::acr_Print(report::acr & row, algo::cstring &str) {
    algo::tempstr temp;
    str << "report.acr";

    u32_Print(row.n_select, temp);
    PrintAttrSpaceReset(str,"n_select", temp);

    u32_Print(row.n_insert, temp);
    PrintAttrSpaceReset(str,"n_insert", temp);

    u32_Print(row.n_delete, temp);
    PrintAttrSpaceReset(str,"n_delete", temp);

    u32_Print(row.n_update, temp);
    PrintAttrSpaceReset(str,"n_update", temp);

    u32_Print(row.n_file_mod, temp);
    PrintAttrSpaceReset(str,"n_file_mod", temp);
}

// --- report.acr_check..ReadFieldMaybe
bool report::acr_check_ReadFieldMaybe(report::acr_check &parent, algo::strptr field, algo::strptr strval) {
    report::FieldId field_id;
    (void)value_SetStrptrMaybe(field_id,field);
    bool retval = true; // default is no error
    switch(field_id) {
        case report_FieldId_records: retval = u32_ReadStrptrMaybe(parent.records, strval); break;
        case report_FieldId_errors: retval = u32_ReadStrptrMaybe(parent.errors, strval); break;
        default: break;
    }
    if (!retval) {
        algo_lib::AppendErrtext("attr",field);
    }
    return retval;
}

// --- report.acr_check..ReadStrptrMaybe
// Read fields of report::acr_check from an ascii string.
// The format of the string is an ssim Tuple
bool report::acr_check_ReadStrptrMaybe(report::acr_check &parent, algo::strptr in_str) {
    bool retval = true;
    retval = algo::StripTypeTag(in_str, "report.acr_check");
    ind_beg(algo::Attr_curs, attr, in_str) {
        retval = retval && acr_check_ReadFieldMaybe(parent, attr.name, attr.value);
    }ind_end;
    return retval;
}

// --- report.acr_check..Print
// print string representation of report::acr_check to string LHS, no header -- cprint:report.acr_check.String
void report::acr_check_Print(report::acr_check & row, algo::cstring &str) {
    algo::tempstr temp;
    str << "report.acr_check";

    u32_Print(row.records, temp);
    PrintAttrSpaceReset(str,"records", temp);

    u32_Print(row.errors, temp);
    PrintAttrSpaceReset(str,"errors", temp);
}

// --- report.amc..ReadFieldMaybe
bool report::amc_ReadFieldMaybe(report::amc &parent, algo::strptr field, algo::strptr strval) {
    report::FieldId field_id;
    (void)value_SetStrptrMaybe(field_id,field);
    bool retval = true; // default is no error
    switch(field_id) {
        case report_FieldId_n_cppfile: retval = u32_ReadStrptrMaybe(parent.n_cppfile, strval); break;
        case report_FieldId_n_cppline: retval = u32_ReadStrptrMaybe(parent.n_cppline, strval); break;
        case report_FieldId_n_ctype: retval = u32_ReadStrptrMaybe(parent.n_ctype, strval); break;
        case report_FieldId_n_func: retval = u32_ReadStrptrMaybe(parent.n_func, strval); break;
        case report_FieldId_n_xref: retval = u32_ReadStrptrMaybe(parent.n_xref, strval); break;
        case report_FieldId_n_filemod: retval = u32_ReadStrptrMaybe(parent.n_filemod, strval); break;
        default: break;
    }
    if (!retval) {
        algo_lib::AppendErrtext("attr",field);
    }
    return retval;
}

// --- report.amc..ReadStrptrMaybe
// Read fields of report::amc from an ascii string.
// The format of the string is an ssim Tuple
bool report::amc_ReadStrptrMaybe(report::amc &parent, algo::strptr in_str) {
    bool retval = true;
    retval = algo::StripTypeTag(in_str, "report.amc");
    ind_beg(algo::Attr_curs, attr, in_str) {
        retval = retval && amc_ReadFieldMaybe(parent, attr.name, attr.value);
    }ind_end;
    return retval;
}

// --- report.amc..Print
// print string representation of report::amc to string LHS, no header -- cprint:report.amc.String
void report::amc_Print(report::amc & row, algo::cstring &str) {
    algo::tempstr temp;
    str << "report.amc";

    u32_Print(row.n_cppfile, temp);
    PrintAttrSpaceReset(str,"n_cppfile", temp);

    u32_Print(row.n_cppline, temp);
    PrintAttrSpaceReset(str,"n_cppline", temp);

    u32_Print(row.n_ctype, temp);
    PrintAttrSpaceReset(str,"n_ctype", temp);

    u32_Print(row.n_func, temp);
    PrintAttrSpaceReset(str,"n_func", temp);

    u32_Print(row.n_xref, temp);
    PrintAttrSpaceReset(str,"n_xref", temp);

    u32_Print(row.n_filemod, temp);
    PrintAttrSpaceReset(str,"n_filemod", temp);
}

// --- report.atf_comp..ReadFieldMaybe
bool report::atf_comp_ReadFieldMaybe(report::atf_comp &parent, algo::strptr field, algo::strptr strval) {
    report::FieldId field_id;
    (void)value_SetStrptrMaybe(field_id,field);
    bool retval = true; // default is no error
    switch(field_id) {
        case report_FieldId_ntest: retval = i32_ReadStrptrMaybe(parent.ntest, strval); break;
        case report_FieldId_nselect: retval = i32_ReadStrptrMaybe(parent.nselect, strval); break;
        case report_FieldId_npass: retval = i32_ReadStrptrMaybe(parent.npass, strval); break;
        case report_FieldId_nskip: retval = i32_ReadStrptrMaybe(parent.nskip, strval); break;
        case report_FieldId_nrun: retval = i32_ReadStrptrMaybe(parent.nrun, strval); break;
        case report_FieldId_nwrite: retval = i32_ReadStrptrMaybe(parent.nwrite, strval); break;
        case report_FieldId_nerr: retval = i32_ReadStrptrMaybe(parent.nerr, strval); break;
        case report_FieldId_ninsert: retval = i32_ReadStrptrMaybe(parent.ninsert, strval); break;
        case report_FieldId_success: retval = bool_ReadStrptrMaybe(parent.success, strval); break;
        default: break;
    }
    if (!retval) {
        algo_lib::AppendErrtext("attr",field);
    }
    return retval;
}

// --- report.atf_comp..ReadStrptrMaybe
// Read fields of report::atf_comp from an ascii string.
// The format of the string is an ssim Tuple
bool report::atf_comp_ReadStrptrMaybe(report::atf_comp &parent, algo::strptr in_str) {
    bool retval = true;
    retval = algo::StripTypeTag(in_str, "report.atf_comp");
    ind_beg(algo::Attr_curs, attr, in_str) {
        retval = retval && atf_comp_ReadFieldMaybe(parent, attr.name, attr.value);
    }ind_end;
    return retval;
}

// --- report.atf_comp..Print
// print string representation of report::atf_comp to string LHS, no header -- cprint:report.atf_comp.String
void report::atf_comp_Print(report::atf_comp & row, algo::cstring &str) {
    algo::tempstr temp;
    str << "report.atf_comp";

    i32_Print(row.ntest, temp);
    PrintAttrSpaceReset(str,"ntest", temp);

    i32_Print(row.nselect, temp);
    PrintAttrSpaceReset(str,"nselect", temp);

    i32_Print(row.npass, temp);
    PrintAttrSpaceReset(str,"npass", temp);

    i32_Print(row.nskip, temp);
    PrintAttrSpaceReset(str,"nskip", temp);

    i32_Print(row.nrun, temp);
    PrintAttrSpaceReset(str,"nrun", temp);

    i32_Print(row.nwrite, temp);
    PrintAttrSpaceReset(str,"nwrite", temp);

    i32_Print(row.nerr, temp);
    PrintAttrSpaceReset(str,"nerr", temp);

    i32_Print(row.ninsert, temp);
    PrintAttrSpaceReset(str,"ninsert", temp);

    bool_Print(row.success, temp);
    PrintAttrSpaceReset(str,"success", temp);
}

// --- report.atf_unit..ReadFieldMaybe
bool report::atf_unit_ReadFieldMaybe(report::atf_unit &parent, algo::strptr field, algo::strptr strval) {
    report::FieldId field_id;
    (void)value_SetStrptrMaybe(field_id,field);
    bool retval = true; // default is no error
    switch(field_id) {
        case report_FieldId_n_test_total: retval = u32_ReadStrptrMaybe(parent.n_test_total, strval); break;
        case report_FieldId_success: retval = bool_ReadStrptrMaybe(parent.success, strval); break;
        case report_FieldId_n_test_run: retval = u64_ReadStrptrMaybe(parent.n_test_run, strval); break;
        case report_FieldId_n_err: retval = u64_ReadStrptrMaybe(parent.n_err, strval); break;
        default: break;
    }
    if (!retval) {
        algo_lib::AppendErrtext("attr",field);
    }
    return retval;
}

// --- report.atf_unit..ReadStrptrMaybe
// Read fields of report::atf_unit from an ascii string.
// The format of the string is an ssim Tuple
bool report::atf_unit_ReadStrptrMaybe(report::atf_unit &parent, algo::strptr in_str) {
    bool retval = true;
    retval = algo::StripTypeTag(in_str, "report.atf_unit");
    ind_beg(algo::Attr_curs, attr, in_str) {
        retval = retval && atf_unit_ReadFieldMaybe(parent, attr.name, attr.value);
    }ind_end;
    return retval;
}

// --- report.atf_unit..Print
// print string representation of report::atf_unit to string LHS, no header -- cprint:report.atf_unit.String
void report::atf_unit_Print(report::atf_unit & row, algo::cstring &str) {
    algo::tempstr temp;
    str << "report.atf_unit";

    u32_Print(row.n_test_total, temp);
    PrintAttrSpaceReset(str,"n_test_total", temp);

    bool_Print(row.success, temp);
    PrintAttrSpaceReset(str,"success", temp);

    u64_Print(row.n_test_run, temp);
    PrintAttrSpaceReset(str,"n_test_run", temp);

    u64_Print(row.n_err, temp);
    PrintAttrSpaceReset(str,"n_err", temp);
}

// --- report.src_func..ReadFieldMaybe
bool report::src_func_ReadFieldMaybe(report::src_func &parent, algo::strptr field, algo::strptr strval) {
    report::FieldId field_id;
    (void)value_SetStrptrMaybe(field_id,field);
    bool retval = true; // default is no error
    switch(field_id) {
        case report_FieldId_n_func: retval = u32_ReadStrptrMaybe(parent.n_func, strval); break;
        case report_FieldId_n_line: retval = u32_ReadStrptrMaybe(parent.n_line, strval); break;
        case report_FieldId_n_static: retval = u32_ReadStrptrMaybe(parent.n_static, strval); break;
        case report_FieldId_n_inline: retval = u32_ReadStrptrMaybe(parent.n_inline, strval); break;
        case report_FieldId_n_mysteryfunc: retval = u32_ReadStrptrMaybe(parent.n_mysteryfunc, strval); break;
        case report_FieldId_n_filemod: retval = u32_ReadStrptrMaybe(parent.n_filemod, strval); break;
        case report_FieldId_n_baddecl: retval = u32_ReadStrptrMaybe(parent.n_baddecl, strval); break;
        case report_FieldId_comment: retval = algo::Comment_ReadStrptrMaybe(parent.comment, strval); break;
        default: break;
    }
    if (!retval) {
        algo_lib::AppendErrtext("attr",field);
    }
    return retval;
}

// --- report.src_func..ReadStrptrMaybe
// Read fields of report::src_func from an ascii string.
// The format of the string is an ssim Tuple
bool report::src_func_ReadStrptrMaybe(report::src_func &parent, algo::strptr in_str) {
    bool retval = true;
    retval = algo::StripTypeTag(in_str, "report.src_func");
    ind_beg(algo::Attr_curs, attr, in_str) {
        retval = retval && src_func_ReadFieldMaybe(parent, attr.name, attr.value);
    }ind_end;
    return retval;
}

// --- report.src_func..Print
// print string representation of report::src_func to string LHS, no header -- cprint:report.src_func.String
void report::src_func_Print(report::src_func & row, algo::cstring &str) {
    algo::tempstr temp;
    str << "report.src_func";

    u32_Print(row.n_func, temp);
    PrintAttrSpaceReset(str,"n_func", temp);

    u32_Print(row.n_line, temp);
    PrintAttrSpaceReset(str,"n_line", temp);

    u32_Print(row.n_static, temp);
    PrintAttrSpaceReset(str,"n_static", temp);

    u32_Print(row.n_inline, temp);
    PrintAttrSpaceReset(str,"n_inline", temp);

    u32_Print(row.n_mysteryfunc, temp);
    PrintAttrSpaceReset(str,"n_mysteryfunc", temp);

    u32_Print(row.n_filemod, temp);
    PrintAttrSpaceReset(str,"n_filemod", temp);

    u32_Print(row.n_baddecl, temp);
    PrintAttrSpaceReset(str,"n_baddecl", temp);

    algo::Comment_Print(row.comment, temp);
    PrintAttrSpaceReset(str,"comment", temp);
}

// --- report...SizeCheck
inline static void report::SizeCheck() {
}
