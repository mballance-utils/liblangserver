/**
 * ServerBase.h
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
#include "jrpc/IEventLoop.h"
#include "lls/IFactory.h"
#include "lls/IServer.h"

namespace lls {



class ServerBase : public virtual IServer {
public:
    ServerBase(
        jrpc::IEventLoop            *loop,
        IFactory                    *factory) : 
            m_loop(loop), m_factory(factory) {

    }

    virtual ~ServerBase() { }
    
    virtual void init(IClient *client) override {
        m_client = client;
    }

	virtual void initialize(
        const std::string       &id,
        IInitializeParamsUP     &params) override {
        IServerCapabilitiesUP capabilites;
        IServerInfoUP serverInfo;

        IInitializeResultUP ret(m_factory->mkInitializeResult(
            capabilites,
            serverInfo));
    }

    virtual void initialized() override {
        // 
    }

    virtual void didOpen(IDidOpenTextDocumentParamsUP &params) override {

    }

    virtual void didChange(IDidChangeTextDocumentParamsUP &params) override {

    }

    virtual void didClose(IDidCloseTextDocumentParamsUP &params) override {

    }

    virtual void declaration(
        const std::string           &id,
        IDeclarationParamsUP        &params) override {

    }

    virtual void definition(
        const std::string               &id,
        ITextDocumentPositionParamsUP   &params) override {

    }

    virtual void documentSymbols(
        const std::string       &id,
        IDocumentSymbolParamsUP &params) override {
    }

    virtual void hover(
        const std::string   &id,
        IHoverParamsUP      &params) override {
    }

    virtual void shutdown(const std::string &id) override {

    }

protected:
    IClient                         *m_client;
    jrpc::IEventLoop                *m_loop;
    IFactory                        *m_factory;

};

}


