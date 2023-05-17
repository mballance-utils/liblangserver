/*
 * DocumentSymbol.cpp
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
#include "DocumentSymbol.h"


namespace lls {


DocumentSymbol::DocumentSymbol(
    const std::string           &name,
    SymbolKind                  kind,
    IRangeUP                    &range,
    IRangeUP                    &selectionRange) :
        m_name(name), m_kind(kind), m_range(std::move(range)),
        m_selectionRange(std::move(selectionRange)) {

}

DocumentSymbol::~DocumentSymbol() {

}

const nlohmann::json &DocumentSymbol::toJson() {
    m_json.clear();
    m_json["name"] = m_name;
    m_json["kind"] = (int)m_kind;
    m_json["range"] = m_range->toJson();
    m_json["selectionRange"] = m_selectionRange->toJson();

    return m_json;
}

}
