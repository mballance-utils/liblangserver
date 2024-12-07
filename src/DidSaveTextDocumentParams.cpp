/*
 * DidSaveTextDocumentParams.cpp
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
#include "DidSaveTextDocumentParams.h"
#include "TextDocumentIdentifier.h"


namespace lls {


DidSaveTextDocumentParams::DidSaveTextDocumentParams(
        ITextDocumentIdentifierUP     &textDocument,
        const std::string             &text) : 
        m_textDocument(std::move(textDocument)), m_text(text) {

}

DidSaveTextDocumentParams::~DidSaveTextDocumentParams() {

}

const nlohmann::json &DidSaveTextDocumentParams::toJson() {
    m_json.clear();
    m_json["textDocument"] = m_textDocument->toJson();
    m_json["text"] = m_text;
    return m_json;
}

IDidSaveTextDocumentParamsUP DidSaveTextDocumentParams::mk(const nlohmann::json &m) {
    ITextDocumentIdentifierUP textDocument(TextDocumentIdentifier::mk(m["textDocument"]));
    std::string text;
    if (m.find("text") != m.end()) {
        text = m["text"];
    }

    return IDidSaveTextDocumentParamsUP(new DidSaveTextDocumentParams(textDocument, text));
}

}
