/*
 * DidChangeTextDocumentParams.cpp
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
#include "DidChangeTextDocumentParams.h"
#include "TextDocumentContentChangeEvent.h"
#include "VersionedTextDocumentIdentifier.h"


namespace lls {


DidChangeTextDocumentParams::DidChangeTextDocumentParams(
    IVersionedTextDocumentIdentifierUP                &textDocument,
    std::vector<ITextDocumentContentChangeEventUP>    &changes) :
        m_textDocument(textDocument.release()) {

    for (std::vector<ITextDocumentContentChangeEventUP>::iterator
        it=changes.begin();
        it!=changes.end(); it++) {
        m_changes.push_back(ITextDocumentContentChangeEventUP(it->release()));
    }
}

DidChangeTextDocumentParams::~DidChangeTextDocumentParams() {

}

const nlohmann::json &DidChangeTextDocumentParams::toJson() {
    m_json.clear();
    m_json["textDocument"] = m_textDocument->toJson();
    nlohmann::json &changes = m_json["changes"];
    for (std::vector<ITextDocumentContentChangeEventUP>::iterator
        it=m_changes.begin();
        it!=m_changes.end(); it++) {
        changes.push_back((*it)->toJson());
    }

    return m_json;
}

IDidChangeTextDocumentParamsUP DidChangeTextDocumentParams::mk(const nlohmann::json &m) {
    IVersionedTextDocumentIdentifierUP textDocument(
        VersionedTextDocumentIdentifier::mk(m["textDocument"]));
    std::vector<ITextDocumentContentChangeEventUP> changes;
    const nlohmann::json &changes_j = m["contentChanges"];
    for (uint32_t i=0; i<changes_j.size(); i++) {
        ITextDocumentContentChangeEventUP change(TextDocumentContentChangeEvent::mk(changes_j.at(i)));
        changes.push_back(std::move(change));
    }

    return IDidChangeTextDocumentParamsUP(new DidChangeTextDocumentParams(textDocument, changes));
}

}
