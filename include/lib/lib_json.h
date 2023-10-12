// Copyright (C) 2014-2019 NYSE | Intercontinental Exchange
// Copyright (C) 2020-2021 Astra
// Copyright (C) 2023 AlgoRND
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
// Target: lib_json (lib) -- Full json support library
// Exceptions: NO
// Header: include/lib/lib_json.h
//
// JSON library
// predefined conversions from basic types to json nodes

#pragma once

#include "include/gen/lib_json_gen.h"
lib_json::FNode *u64_FmtJson(u64 value, lib_json::FNode *parent);
lib_json::FNode *u32_FmtJson(u32 value, lib_json::FNode *parent);
lib_json::FNode *u16_FmtJson(u16 value, lib_json::FNode *parent);
lib_json::FNode *u8_FmtJson(u8 value, lib_json::FNode *parent);
lib_json::FNode *i64_FmtJson(i64 value, lib_json::FNode *parent);
lib_json::FNode *i32_FmtJson(i32 value, lib_json::FNode *parent);
lib_json::FNode *i16_FmtJson(i16 value, lib_json::FNode *parent);
lib_json::FNode *i8_FmtJson(i8 value, lib_json::FNode *parent);
lib_json::FNode *double_FmtJson(double value, lib_json::FNode *parent);
lib_json::FNode *float_FmtJson(float value, lib_json::FNode *parent);
lib_json::FNode *bool_FmtJson(bool value, lib_json::FNode *parent);
lib_json::FNode *char_FmtJson(char value, lib_json::FNode *parent);

namespace lib_json {
    // Parses JSON text into tree structure according to ECMA-404
    // can be invoked repeadetly with new data portions (can be used directly as read hook)
    //
    // PARSER    parser handle
    // BUF       input buffer to process
    //           non-zero-length - parse new data portion
    //           zero-length     - to finalize and check completeness
    // RETURN    true for OK, false for parse error
    //
    // after finalization, root node pointer is available at: parser.root_node
    // whole tree is automatically deleted upon parser destruction,
    // to detach tree from parser do parser.root_node=NULL

    bool JsonParse(lib_json::FParser &parser, strptr buf);

    // Check for parse error
    //
    // PARSER    parser handle
    // RETURN    true for OK, false for parse error
    bool JsonParseOkQ(lib_json::FParser &parser);

    // Serialize to JSON tree to text
    // NODE      root node to start from
    // LHS       target string
    // PRETTY    whether or not pretty-format
    // INDENT    level of indenting (for pretty-formatting)

    void JsonSerialize(lib_json::FNode* node, cstring &lhs, bool pretty=false, u32 indent=0);


    // Create new JSON node
    // PARENT    parent node or NULL
    // TYPE      node type
    // VALUE     node value where applicable (only for field, string, number)
    lib_json::FNode &NewNode(lib_json::FNode *parent, lib_json_FNode_type_Enum type, strptr value=strptr());
    lib_json::FNode &NewFieldNode(lib_json::FNode *parent, strptr field);

    //
    // Convenience functions for creating trees.
    // Each function checks if parent is an object, and pre-creates a field child if necessary.
    //  (thus creating up to 2 new nodes at a time)
    lib_json::FNode &NewObjectNode(lib_json::FNode *parent, strptr field=strptr());
    lib_json::FNode  &NewArrayNode(lib_json::FNode *parent, strptr field=strptr());
    lib_json::FNode &NewStringNode(lib_json::FNode *parent, strptr field=strptr(), strptr value=strptr());
    lib_json::FNode &NewNumberNode(lib_json::FNode *parent, strptr field=strptr(), strptr value=strptr("0"));

    //
    // Convenience functions for getting values from tree in exception-safe manner
    //

    // Find node in object chain
    // PARENT    node to start from
    // PATH      dot-separated list of field keys
    //           e.g. path abc.def.ghi and parent pointing to {"abc:{"def":{"ghi":value}}}
    //           yields value node
    lib_json::FNode* node_Find(lib_json::FNode* parent, strptr path);

    // Get node value as string
    // Empty string is returned in case of any error or null value
    // true/false is converted to 0/1
    //
    // PARENT    node to start from
    // PATH      dot-separated list of field keys
    strptr strptr_Get(lib_json::FNode* parent, strptr path);

    // Get array node, NULL in case of any error
    //
    // PARENT    node to start from
    // PATH      dot-separated list of field keys
    lib_json::FNode* node_GetArray(lib_json::FNode* parent, strptr path);

    // Get node value as u32, EXCEPTION on any error
    // true/false is converted to 0/1
    //
    // PARENT    node to start from
    // PATH      dot-separated list of field keys
    u32 u32_Get(lib_json::FNode* parent, strptr path);
}

#include "include/lib/lib_json.inl.h"
#include "include/gen/lib_json_gen.inl.h"
