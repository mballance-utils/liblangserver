/**
 * ClientMessageDispatcher.h
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
#include "dmgr/IDebugMgr.h"
#include "jrpc/IEventLoop.h"
#include "jrpc/IMessageTransport.h"
#include "lls/IClient.h"
#include "lls/IClientMessageDispatcher.h"
#include "lls/IFactory.h"
#include "lls/IInitializeResult.h"

namespace lls {

/**
 * Dispatches client messages and implements the server API
 * for communicating with a Server
 * 
 */
class ClientMessageDispatcher : 
    public virtual IClientMessageDispatcher,
    public virtual jrpc::IMessageTransport {
public:
    ClientMessageDispatcher(
        IFactory                    *factory,
        jrpc::IMessageTransport     *transport,
        IClient                     *client);

    virtual ~ClientMessageDispatcher();

    virtual void init(IMessageTransport   *peer) override {
        // ..
    }

    /**
     * Send an outbound message via this transport
     */
	virtual void send(const nlohmann::json &msg) override {
        m_transport->send(msg);
    }

    /**
     * Get the event loop that this transport uses
     */
    virtual jrpc::IEventLoop *getLoop() override {
        return m_transport->getLoop();
    }

	virtual IInitializeResultUP initialize(IInitializeParamsUP &params) override;

    virtual void initialized() override;

    virtual void didOpen(IDidOpenTextDocumentParamsUP &params) override;

    virtual void didChange(IDidChangeTextDocumentParamsUP &params) override;

    virtual void didClose(IDidCloseTextDocumentParamsUP &params) override;

    virtual IHoverUP hover(IHoverParamsUP &params) override;

private:

    jrpc::IRspMsgUP sendMethodRequest(const std::string &method, const nlohmann::json &params);

    void sendNotification(const std::string &method, const nlohmann::json &params);

    void handleResult(int32_t id, jrpc::IRspMsgUP &rsp);

private:
    static dmgr::IDebug             *m_dbg;
    int32_t                         m_req_id;
    IFactory                        *m_factory;
    jrpc::IEventLoop                *m_loop;
    jrpc::IMessageTransport         *m_transport;
    IClient                         *m_client;
    jrpc::IMessageDispatcher        *m_dispatcher;

    jrpc::IRspMsgUP                 m_rsp;
};

}


