/*
 * VersionedTextDocumentIdentifier.cpp
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
#include "VersionedTextDocumentIdentifier.h"


namespace lls {


VersionedTextDocumentIdentifier::VersionedTextDocumentIdentifier(
    const std::string       &uri,
    int32_t                 version) : TextDocumentIdentifier(uri), m_version(version) {

}

VersionedTextDocumentIdentifier::~VersionedTextDocumentIdentifier() {

}

const nlohmann::json &VersionedTextDocumentIdentifier::toJson() {
    m_json.clear();
    m_json["uri"] = getUri();
    m_json["version"] = m_version;
    return m_json;
}

IVersionedTextDocumentIdentifierUP VersionedTextDocumentIdentifier::mk(const nlohmann::json &m) {
    std::string uri = m["uri"];
    int32_t version = m["version"];
    return IVersionedTextDocumentIdentifierUP(new VersionedTextDocumentIdentifier(uri, version));
}

}
