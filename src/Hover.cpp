/*
 * Hover.cpp
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
#include "Hover.h"


namespace lls {


Hover::Hover(
    IContentUP          &contents,
    IRangeUP            &range) : 
        m_contents(std::move(contents)), m_range(std::move(range)) {

}

Hover::~Hover() {

}

const nlohmann::json &Hover::toJson() {
    m_json.clear();
    if (m_contents || m_range) {
        m_json["contents"] = m_contents->toJson();
        if (m_range) {
            m_json["range"] = m_range->toJson();
        }
    }
    return m_json;
}

    static IHoverUP mk(const nlohmann::json &m);

}
