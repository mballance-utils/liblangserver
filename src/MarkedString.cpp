/*
 * MarkedString.cpp
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
#include "MarkedString.h"


namespace lls {


MarkedString::MarkedString(
    const std::string           &language,
    const std::string           &value) 
        : Content(ContentKind::MarkedString), m_language(language), m_value(value) {

}

MarkedString::~MarkedString() {

}

const nlohmann::json &MarkedString::toJson() {
    m_json.clear();
    if (m_language != "") {
        m_json["language"] = m_language;
        m_json["value"] = m_value;
    } else {
        m_json = m_value;
    }

    return m_json;
}

}
