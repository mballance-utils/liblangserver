/*
 * MarkupContent.cpp
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
#include "MarkupContent.h"


namespace lls {


MarkupContent::MarkupContent(
    MarkupKind          kind,
    const std::string   &value) : m_kind(kind), m_value(value) {

}

MarkupContent::~MarkupContent() {

}

const nlohmann::json &MarkupContent::toJson() {
    m_json.clear();
    m_json["kind"] = (m_kind == MarkupKind::Markdown)?"markdown":"plaintext";
    m_json["value"] = m_value;
    return m_json;
}

}
