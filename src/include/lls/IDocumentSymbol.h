/**
 * IDocumentSymbol.h
 *
 * Copyright 2023 Matthew Ballance and Contributors
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may 
 * not use this file except in compliance with the License.  
 * You may obtain a copy of the License at:
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software 
 * distributed under the License is distributed on an "AS IS" BASIS, 
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  
 * See the License for the specific language governing permissions and 
 * limitations under the License.
 *
 * Created on:
 *     Author: 
 */
#pragma once
#include <string>
#include <vector>
#include "lls/IJson.h"
#include "lls/IRange.h"

namespace lls {

enum class SymbolKind {
	File = 1,
	Module = 2,
	Namespace = 3,
	Package = 4,
	Class = 5,
	Method = 6,
	Property = 7,
	Field = 8,
	Constructor = 9,
	Enum = 10,
	Interface = 11,
	Function = 12,
	Variable = 13,
	Constant = 14,
	String = 15,
	Number = 16,
	Boolean = 17,
	Array = 18,
	Object = 19,
	Key = 20,
	Null = 21,
	EnumMember = 22,
	Struct = 23,
	Event = 24,
	Operator = 25,
	TypeParameter = 26
};

class IDocumentSymbol;
using IDocumentSymbolUP=std::unique_ptr<IDocumentSymbol>;
class IDocumentSymbol : public virtual IJson {
public:

    virtual ~IDocumentSymbol() { }

    virtual const std::string &getName() = 0;

    virtual SymbolKind getKind() = 0;

    virtual IRange *getRange() = 0;

    virtual IRange *getSelectionRange() = 0;

    virtual void addChild(IDocumentSymbolUP &c) = 0;

    virtual std::vector<IDocumentSymbolUP> &getChildren() = 0;

};

} /* namespace lls */


