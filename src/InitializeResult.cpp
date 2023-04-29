/*
 * InitializeResult.cpp
 *
 * Copyright 2022 Matthew Ballance and Contributors
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
#include "InitializeResult.h"


namespace lls {


InitializeResult::InitializeResult(
        IServerCapabilities     *capabilities,
        IServerInfo             *serverInfo) :
            m_capabilities(capabilities),
            m_serverInfo(serverInfo) {

}

InitializeResult::~InitializeResult() {

}

const nlohmann::json &InitializeResult::toJson() {
    m_json.clear();
    m_json["capabiities"] = m_capabilities->toJson();

    if (m_serverInfo) {
        m_json["serverInfo"] = m_serverInfo->toJson();
    }

    return m_json;
}

}
