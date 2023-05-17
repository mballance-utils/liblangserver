/*
 * PublishDiagnosticsParams.cpp
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
#include "PublishDiagnosticsParams.h"


namespace lls {


PublishDiagnosticsParams::PublishDiagnosticsParams(
    const std::string           &uri,
    int32_t                     version,
    std::vector<IDiagnosticUP>  &diagnostics) :
    m_uri(uri), m_version(version) {

    for (std::vector<IDiagnosticUP>::iterator
        it=diagnostics.begin();
        it!=diagnostics.end(); it++) {
        m_diagnostics.push_back(std::move(*it));
    }
}

PublishDiagnosticsParams::~PublishDiagnosticsParams() {

}

const nlohmann::json &PublishDiagnosticsParams::toJson() {
    m_json.clear();
    m_json["uri"] = m_uri;

    if (m_version >= 0) {
        m_json["version"] = m_version;
    }

    m_json["diagnostics"] = nlohmann::json::array(); 
    nlohmann::json &diagnostics = m_json["diagnostics"];
    for (std::vector<IDiagnosticUP>::const_iterator
        it=m_diagnostics.begin();
        it!=m_diagnostics.end(); it++) {
        diagnostics.push_back((*it)->toJson());
    }

    return m_json;
}

}
