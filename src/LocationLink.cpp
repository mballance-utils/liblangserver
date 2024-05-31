/*
 * LocationLink.cpp
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
#include "LocationLink.h"


namespace lls {


LocationLink::LocationLink(
    IRangeUP            &originSelectionRange,
    const std::string   &targetUri,
    IRangeUP            &targetRange,
    IRangeUP            &targetSelectionRange) :
    m_originSelectionRange(std::move(originSelectionRange)), 
    m_targetUri(targetUri),
    m_targetRange(std::move(targetRange)), 
    m_targetSelectionRange(std::move(targetSelectionRange)) {

}

LocationLink::~LocationLink() {

}

const nlohmann::json &LocationLink::toJson() {
    m_json.clear();
    if (m_originSelectionRange) {
        m_json["originSelectionRange"] = m_originSelectionRange->toJson();
    }
    m_json["targetUri"] = m_targetUri;
    m_json["targetRange"] = m_targetRange->toJson();
    m_json["targetSelectionRange"] = m_targetSelectionRange->toJson();
    return m_json;
}

}
