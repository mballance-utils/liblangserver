/*
 * ServerCapabilities.cpp
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
#include "ServerCapabilities.h"


namespace lls {


ServerCapabilities::ServerCapabilities(
    ITextDocumentSyncOptionsUP      &textDocumentSync) :
        m_textDocumentSync(textDocumentSync.release()) {

}

ServerCapabilities::~ServerCapabilities() {

}

const nlohmann::json &ServerCapabilities::toJson() {
    m_json.clear();

    m_json["textDocumentSync"] = m_textDocumentSync->toJson();

    return m_json;
}

IServerCapabilitiesUP ServerCapabilities::mk(const nlohmann::json &params) {

    ITextDocumentSyncOptionsUP textDocumentSync;

    if (params.contains("textDocumentSync")) {
        // TODO:
    }

    return IServerCapabilitiesUP(new ServerCapabilities(
        textDocumentSync
    ));
}

}
