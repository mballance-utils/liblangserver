/*
 * DidCloseTextDocumentParams.cpp
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
#include "DidCloseTextDocumentParams.h"
#include "TextDocumentIdentifier.h"


namespace lls {


DidCloseTextDocumentParams::DidCloseTextDocumentParams(
        ITextDocumentIdentifierUP     &textDocument) : m_textDocument(std::move(textDocument)) {

}

DidCloseTextDocumentParams::~DidCloseTextDocumentParams() {

}

const nlohmann::json &DidCloseTextDocumentParams::toJson() {
    m_json.clear();
    m_json["textDocument"] = m_textDocument->toJson();
    return m_json;
}

IDidCloseTextDocumentParamsUP DidCloseTextDocumentParams::mk(const nlohmann::json &m) {
    ITextDocumentIdentifierUP textDocument(TextDocumentIdentifier::mk(m["textDocument"]));

    return IDidCloseTextDocumentParamsUP(new DidCloseTextDocumentParams(textDocument));
}

}
