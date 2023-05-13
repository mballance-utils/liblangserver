/**
 * TextDocumentItem.h
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
#include"Json.h"
#include "lls/ITextDocumentItem.h"

namespace lls {


class TextDocumentItem : 
    public virtual ITextDocumentItem,
    public virtual Json {
public:
    TextDocumentItem(
        const std::string       &uri,
        const std::string       &languageId,
        int32_t                 version,
        const std::string       &text);

    virtual ~TextDocumentItem();

    virtual const std::string &getUri() override {
        return m_uri;
    }

    virtual const std::string &getLanguageId() override {
        return m_languageId;
    }

    virtual int32_t getVersion() override {
        return m_version;
    }

    virtual const std::string &getText() override {
        return m_text;
    }

    virtual const nlohmann::json &toJson() override;

    static ITextDocumentItemUP mk(const nlohmann::json &m);

private:
    std::string                 m_uri;
    std::string                 m_languageId;
    int32_t                     m_version;
    std::string                 m_text;

};

}


