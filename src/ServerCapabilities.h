/**
 * ServerCapabilities.h
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
#pragma once
#include "lls/IServerCapabilities.h"
#include "Json.h"

namespace lls {



class ServerCapabilities :
    public virtual IServerCapabilities,
    public virtual Json {
public:
    ServerCapabilities(
        ITextDocumentSyncOptionsUP      &textDocumentSync
    );

    virtual ~ServerCapabilities();

    virtual ITextDocumentSyncOptions *getTextDocumentSync() override {
        return m_textDocumentSync.get();
    }

    virtual bool getHoverProvider() override {
        return m_hover_provider;
    }

    virtual void setHoverProvider(bool have) override {
        m_hover_provider = have;
    }
    
    virtual bool getDocumentSymbolProvider() override {
        return m_documentSymbolProvider;
    }

    virtual void setDocumentSymbolProvider(bool have) override {
        m_documentSymbolProvider = have;
    }

    virtual const nlohmann::json &toJson() override;

    static IServerCapabilitiesUP mk(const nlohmann::json &params);

private:
    ITextDocumentSyncOptionsUP          m_textDocumentSync;
    bool                                m_hover_provider;
    bool                                m_documentSymbolProvider;

};

}


