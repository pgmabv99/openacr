// Copyright (C) 2023-2024 AlgoRND
// Copyright (C) 2020-2021 Astra
// Copyright (C) 2018-2019 NYSE | Intercontinental Exchange
//
// License: GPL
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
// Contacting ICE: <https://www.theice.com/contact>
// Target: amc (exe) -- Algo Model Compiler: generate code under include/gen and cpp/gen
// Exceptions: NO
// Source: cpp/amc/read.cpp -- Read ctype from string
//

#include "include/amc.h"

// -----------------------------------------------------------------------------

static void GenRead_Tuple(algo_lib::Replscope &R, amc::FCtype &ctype, amc::FCfmt &cfmt) {
    int n_anon = c_anonfld_N(ctype);
    amc::FFunc& func = amc::CreateCurFunc(false, "ReadTupleMaybe");
    Ins(&R, func.proto, "$Name_ReadTupleMaybe()",false);
    AddProtoArg(func, Subst(R,"$Cpptype &"), "parent");
    AddProtoArg(func, "algo::Tuple &", "tuple");
    AddRetval(func, "bool", "retval", "true");
    func.glob = true;
    func.extrn = cfmt.printfmt == dmmeta_Printfmt_printfmt_Extern;
    Ins(&R, func.comment, "Read fields of $Cpptype from attributes of ascii tuple TUPLE");
    if (n_anon > 0) {
        Ins(&R, func.body      , "int anon_idx = 0;");
    }
    if (!func.extrn) {
        Ins(&R, func.body      , "ind_beg(algo::Tuple_attrs_curs,attr,tuple) {");
        if (n_anon > 0) {
            Ins(&R, func.body  , "    if (ch_N(attr.name) == 0) {");
            Ins(&R, func.body  , "        attr.name = $Name_GetAnon(parent, anon_idx++);");
            Ins(&R, func.body  , "    }");
        }
        Ins(&R, func.body      , "    retval = $Name_ReadFieldMaybe(parent, attr.name, attr.value);");
        Ins(&R, func.body      , "    if (!retval) {");
        Ins(&R, func.body      , "        break;");
        Ins(&R, func.body      , "    }");
        Ins(&R, func.body      , "}ind_end;");
        if (n_anon > 0) {
            MaybeUnused(func, "anon_idx");
        }
    }
}

// -----------------------------------------------------------------------------

static void Ctype_ReadStrptrMaybe_Ssim(algo_lib::Replscope &R, amc::FCtype &ctype, amc::FFunc &readstrptr) {
    Set(R, "$CtypeName", ctype.ctype);
    Ins(&R, readstrptr.comment, "The format of the string is an ssim Tuple");
    // Detect both variants -- ssimfile name AND ctype name
    if (ctype.c_ssimfile) {
        Set(R, "$SsimfileName", ctype.c_ssimfile->ssimfile);
        Ins(&R, readstrptr.body     , "retval = algo::StripTypeTag(in_str, \"$SsimfileName\") || algo::StripTypeTag(in_str, \"$CtypeName\");");
    } else {
        Ins(&R, readstrptr.body     , "retval = algo::StripTypeTag(in_str, \"$CtypeName\");");
    }
    int n_anon = c_anonfld_N(ctype);
    if (n_anon > 0) {
        Ins(&R, readstrptr.body , "int anon_idx = 0;");
    }
    Ins(&R, readstrptr.body     , "ind_beg(algo::Attr_curs, attr, in_str) {");
    if (n_anon > 0) {
        Ins(&R, readstrptr.body , "    if (ch_N(attr.name) == 0) {");
        Ins(&R, readstrptr.body , "        attr.name = $Name_GetAnon(parent, anon_idx++);");
        Ins(&R, readstrptr.body , "    }");
    }
    Ins(&R, readstrptr.body     , "    retval = retval && $Name_ReadFieldMaybe(parent, attr.name, attr.value);");
    Ins(&R, readstrptr.body     , " }ind_end;");
    if (n_anon > 0) {
        MaybeUnused(readstrptr, "anon_idx");
    }
    MaybeUnused(readstrptr, "parent");
    MaybeUnused(readstrptr, "in_str");
}

// -----------------------------------------------------------------------------

static void Ctype_ReadStrptrMaybe_Sep(algo_lib::Replscope &R, amc::FCtype &ctype, amc::FFunc &readstrptr, strptr sep) {
    Ins(&R, readstrptr.comment, "The format of the string is a string with separated values");
    Ins(&R, readstrptr.body, "algo::strptr value;");
    int counter = 0;
    amc::FField *lastfld = NULL;
    ind_beg(amc::ctype_c_field_curs, field,ctype) {
        if (HasReadExprQ(field)) {
            lastfld = &field;
        }
    }ind_end;
    ind_beg(amc::ctype_c_field_curs, field,ctype) {
        if (HasReadExprQ(field) && bh_bitfld_EmptyQ(field)) {
            char c = sep.elems[u32_Min(counter, elems_N(sep)-1)];
            counter++;
            tempstr cpp_char;
            char_PrintCppSingleQuote(c, cpp_char);
            Set(R, "$cppchar", cpp_char);
            Set(R, "$name", name_Get(field));
            Ins(&R, readstrptr.body, "");
            if (&field != lastfld) {
                Ins(&R, readstrptr.body, "algo::NextSep(in_str, $cppchar, value);");
            } else {
                Ins(&R, readstrptr.body, "value = in_str;");// no more -- scan the rest
            }
            Set(R, "$ReadExpr", ReadFieldExpr(field, "parent", "value"));
            Ins(&R, readstrptr.body    , "retval = retval && $ReadExpr;");
        }
    }ind_end;
    if (counter-1 != elems_N(sep)) {
        prerr("amc.bad_sep"
              <<Keyval("ctype",ctype.ctype)
              <<Keyval("need_sep_len", counter-1)
              <<Keyval("sep_len", elems_N(sep))
              <<Keyval("comment","Separator string must match the number of fields in ctype"));
        algo_lib::_db.exit_code++;
    }
}

// -----------------------------------------------------------------------------

static void Ctype_ReadStrptrMaybe_Raw(algo_lib::Replscope &R, amc::FCtype &ctype, amc::FFunc &readstrptr) {
    if (c_datafld_N(ctype)>0) {
        Ins(&R, readstrptr.comment, "The format of the string is the format of the $Cpptype's only field");
    }
    int nprint = 0;
    ind_beg(amc::ctype_c_field_curs, field,ctype) {
        bool good = true;
        good &= HasReadExprQ(field);
        good &= !field.c_bitfld;
        if (good) {
            Set(R,"$name",name_Get(field));
            Set(R,"$fns",ns_Get(field));
            Set(R,"$Fldtype",field.cpp_type);
            Set(R, "$ReadExpr", ReadFieldExpr(field, "parent", "in_str"));
            Ins(&R, readstrptr.body, "retval = retval && $ReadExpr;");
            nprint++;
        }
    }ind_end;
    if (nprint > 1) {
        prerr("amc.too_raw"
              <<Keyval("ctype",ctype.ctype)
              <<Keyval("comment","Raw format expects 1 printable field"));
        algo_lib::_db.exit_code++;
    }
    if (nprint == 0) {
        verblog("amc.not_raw_enough  ctype:"<<ctype.ctype<<"  comment:'Raw format expects at least 1 printable field'");
    }
    MaybeUnused(readstrptr, "parent");
    MaybeUnused(readstrptr, "in_str");
}

// -----------------------------------------------------------------------------

static void Ctype_ReadStrptrMaybe_Bitset(algo_lib::Replscope &R, amc::FCtype &ctype, amc::FCfmt &cfmt, amc::FFunc &readstrptr) {
    vrfy(ch_N(cfmt.sep)==1, tempstr()<<"For Bitset only one-char separator is supported: "<<cfmt.cfmt);
    cstring sep;
    char_PrintCppSingleQuote(cfmt.sep.ch[0],sep);
    Set(R, "$sep", sep);
    Set(R, "$ns", ns_Get(ctype));
    Ins(&R, readstrptr.body        ,"// Clear affected bits first)"); // default may be true
    ind_beg(amc::ctype_c_field_curs,field,ctype) if (field.arg == "bool") {
        Set(R, "$name", name_Get(field));
        Ins(&R, readstrptr.body, tempstr()<<AssignExpr(field,"parent","false",false)<<";");
    }ind_end;
    Ins(&R, readstrptr.body        ,"// Read $sep-separated list of bools");
    Ins(&R, readstrptr.body        ,"while (ch_N(in_str)) {");
    Ins(&R, readstrptr.body        ,"    strptr field_name;");
    Ins(&R, readstrptr.body        ,"    algo::NextSep(in_str,$sep,field_name);");
    Ins(&R, readstrptr.body        ,"    field_name = algo::Trimmed(field_name);");
    Ins(&R, readstrptr.body        ,"    if (ch_N(field_name)) {");
    Ins(&R, readstrptr.body        ,"        $ns::FieldId field_id;");
    Ins(&R, readstrptr.body        ,"        bool ok = $ns::value_SetStrptrMaybe(field_id,field_name);");
    Ins(&R, readstrptr.body        ,"        if (ok) {");
    Ins(&R, readstrptr.body        ,"            switch (field_id) {");
    ind_beg(amc::ctype_c_field_curs,field,ctype) if (field.arg == "bool") {
        Set(R, "$name", name_Get(field));
        Ins(&R, readstrptr.body    ,"            case $ns_FieldId_$name: {");
        Ins(&R, readstrptr.body,                     tempstr()<<AssignExpr(field,"parent","true",false)<<";");
        Ins(&R, readstrptr.body    ,"            } break;");
    }ind_end;
    Ins(&R, readstrptr.body        ,"            default: ok = false; break;");
    Ins(&R, readstrptr.body        ,"            }");
    Ins(&R, readstrptr.body        ,"        }");
    Ins(&R, readstrptr.body        ,"        if (!ok) {");
    Ins(&R, readstrptr.body        ,"            algo_lib::AppendErrtext(\"bitfld\",field_name);");
    Ins(&R, readstrptr.body        ,"            retval = false;");
    Ins(&R, readstrptr.body        ,"        }");
    Ins(&R, readstrptr.body        ,"    }");
    Ins(&R, readstrptr.body        ,"}");
    MaybeUnused(readstrptr, "parent");
    MaybeUnused(readstrptr, "in_str");
}

// -----------------------------------------------------------------------------

// Dispatach on field name, and read appropriate field
void amc::tfunc_Ctype_ReadFieldMaybe() {
    amc::FCtype &ctype = *amc::_db.genctx.p_ctype;
    bool doit = false;
    ind_beg(amc::ctype_zs_cfmt_curs,cfmt,ctype) if (cfmt.read
                                                    && !(   cfmt.printfmt == dmmeta_Printfmt_printfmt_Raw
                                                            || cfmt.printfmt == dmmeta_Printfmt_printfmt_Extern)) {
        doit = true;
    }ind_end;
    bool has_varlen=false;
    ind_beg(amc::ctype_c_field_curs,field,ctype) {
        has_varlen
            = field.reftype == dmmeta_Reftype_reftype_Varlen
            || field.reftype == dmmeta_Reftype_reftype_Inlary
            || field.reftype == dmmeta_Reftype_reftype_Tary;
        if (has_varlen) {
            break;
        }
    }ind_end;

    if (doit) {
        algo_lib::Replscope R;
        Set(R, "$ns", ns_Get(ctype));
        Set(R, "$Name", name_Get(ctype));
        Set(R, "$Cpptype", ctype.cpp_type);
        amc::FFunc& fcn = amc::CreateCurFunc(true);
        fcn.glob = true;
        fcn.extrn = false;
        AddRetval(fcn, "bool", "retval", "true");
        AddProtoArg(fcn, amc::Refto(ctype.cpp_type), "parent");
        AddProtoArg(fcn, "algo::strptr", "field");
        AddProtoArg(fcn, "algo::strptr", "strval");
        Ins(&R, fcn.body       , "$ns::FieldId field_id;");
        Set(R, "$strippedfield", has_varlen ? "algo::Pathcomp(field, \".LL\")" : "field");
        Ins(&R, fcn.body       , "(void)value_SetStrptrMaybe(field_id,$strippedfield);");
        Ins(&R, fcn.body       , "switch(field_id) {");
        ind_beg(amc::ctype_c_field_curs, field,ctype) {
            Set(R, "$name", name_Get(field));
            Set(R, "$ReadExpr", ReadFieldExpr(field, "parent", "strval"));
            Ins(&R, fcn.body,"case $ns_FieldId_$name: {");
            Ins(&R, fcn.body,"    retval = $ReadExpr;");
            if (c_pmaskfld_member_N(field) > 0) {
                Ins(&R, fcn.body,"    if (retval) {");
                fcn.body << SetPresentExpr(field, "parent");
                Ins(&R, fcn.body,"    }");
            }
            Ins(&R, fcn.body,"    break;");
            Ins(&R, fcn.body,"}");
        }ind_end;
        Ins(&R, fcn.body, "default: break;");
        Ins(&R, fcn.body, "}");
        Ins(&R, fcn.body, "if (!retval) {");
        Ins(&R, fcn.body, "    algo_lib::AppendErrtext(\"attr\",field);");
        Ins(&R, fcn.body, "}");
    }
}

// -----------------------------------------------------------------------------

void amc::GenRead(amc::FCtype &ctype, amc::FCfmt &cfmt) {
    algo_lib::Replscope R;
    Set(R, "$ctype", ctype.ctype);
    Set(R, "$Name", name_Get(ctype));
    Set(R, "$Cpptype", ctype.cpp_type);
    if (strfmt_Get(cfmt) == dmmeta_Strfmt_strfmt_String) {
        amc::FFunc& func = amc::CreateCurFunc(false, "ReadStrptrMaybe");
        Ins(&R, func.proto, "$Name_ReadStrptrMaybe()", false);
        AddProtoArg(func,Subst(R,"$Cpptype &"),"parent");
        AddProtoArg(func,"algo::strptr", "in_str");
        AddRetval(func, "bool", "retval", "true");
        if (VarlenQ(ctype)) {
            Ins(&R, func.comment, "Any varlen fields are returned in algo_lib::_db.varlenbuf if set");
        }
        Ins(&R, func.comment, "Read fields of $Cpptype from an ascii string.");
        if (cfmt.printfmt == dmmeta_Printfmt_printfmt_Extern) {
            func.extrn = true;
        } else if (cfmt.printfmt == dmmeta_Printfmt_printfmt_Sep) {
            Ctype_ReadStrptrMaybe_Sep(R, ctype, func, cfmt.sep);
        } else if (cfmt.printfmt == dmmeta_Printfmt_printfmt_Raw) {
            Ctype_ReadStrptrMaybe_Raw(R, ctype, func);
        } else if (cfmt.printfmt == dmmeta_Printfmt_printfmt_Tuple) {
            Ctype_ReadStrptrMaybe_Ssim(R, ctype, func);
        } else if (cfmt.printfmt == dmmeta_Printfmt_printfmt_Bitset) {
            Ctype_ReadStrptrMaybe_Bitset(R, ctype, cfmt, func);
        } else {
            vrfy("amc.badcfmt",tempstr()
                 <<Keyval("cfmt",cfmt.cfmt)
                 <<Keyval("printfmt",cfmt.printfmt)
                 <<Keyval("comment","unsupported strfmt for reading"));
        }
    } else if (strfmt_Get(cfmt) == dmmeta_Strfmt_strfmt_Tuple) {
        GenRead_Tuple(R,ctype,cfmt);
    }
}
