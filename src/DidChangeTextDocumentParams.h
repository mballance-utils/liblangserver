/**
 * DidChangeTextDocumentParams.h
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
#pragma once
#include "lls/IDidChangeTextDocumentParams.h"
#include "Json.h"

namespace lls {



class DidChangeTextDocumentParams :
    public virtual IDidChangeTextDocumentParams,
    public virtual Json {
public:
    DidChangeTextDocumentParams(
        IVersionedTextDocumentIdentifierUP                &textDocument,
        std::vector<ITextDocumentContentChangeEventUP>    &changes
    );

    virtual ~DidChangeTextDocumentParams();

    virtual IVersionedTextDocumentIdentifier *getTextDocument() override {
        return m_textDocument.get();
    }

    virtual const std::vector<ITextDocumentContentChangeEventUP> &getChanges() override {
        return m_changes;
    }

    virtual const nlohmann::json &toJson() override;

    static IDidChangeTextDocumentParamsUP mk(const nlohmann::json &m);

private:
    IVersionedTextDocumentIdentifierUP                  m_textDocument;
    std::vector<ITextDocumentContentChangeEventUP>      m_changes;

};

}


