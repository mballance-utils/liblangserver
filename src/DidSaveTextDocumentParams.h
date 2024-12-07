/**
 * DidSaveTextDocumentParams.h
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
#include "lls/IDidSaveTextDocumentParams.h"
#include "Json.h"

namespace lls {


class DidSaveTextDocumentParams :
    public virtual IDidSaveTextDocumentParams,
    public virtual Json {
public:
    DidSaveTextDocumentParams(
        ITextDocumentIdentifierUP   &textDocument,
        const std::string           &text);

    virtual ~DidSaveTextDocumentParams();

    virtual ITextDocumentIdentifier *getTextDocument() override {
        return m_textDocument.get();
    }

    virtual const std::string &getText() override {
        return m_text;
    }

    virtual const nlohmann::json &toJson() override;

    static IDidSaveTextDocumentParamsUP mk(const nlohmann::json &m);

private:
    ITextDocumentIdentifierUP                 m_textDocument;
    std::string                               m_text;


};

}


