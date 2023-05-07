/*
 * ClientMessageDispatcher.cpp
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
#include "dmgr/impl/DebugMacros.h"
#include "nlohmann/json.hpp"
#include "ClientMessageDispatcher.h"
#include "InitializeResult.h"


namespace lls {


ClientMessageDispatcher::ClientMessageDispatcher(
        IFactory                    *factory,
        jrpc::IMessageTransport     *transport,
        IClient                     *client) :
            m_factory(factory), m_loop(0), 
            m_transport(transport), m_client(client) {
    DEBUG_INIT("ClientMessageDispatcher", factory->getDebugMgr());

    m_loop = transport->getLoop();

    m_dispatcher = m_factory->getFactory()->mkNBSocketServerMessageDispatcher(
        m_transport
    );
    m_dispatcher->setResponseHandler(
        std::bind(&ClientMessageDispatcher::handleResult, this, 
            std::placeholders::_1, std::placeholders::_2));

}

ClientMessageDispatcher::~ClientMessageDispatcher() {

}

IInitializeResultUP ClientMessageDispatcher::initialize(IInitializeParamsUP &params) {
    DEBUG_ENTER("initialize");

    // Send a request and poll waiting for a response
    jrpc::IRspMsgUP rsp(sendMethodRequest("initialize", params->toJson()));

    IInitializeResultUP ret = InitializeResult::mk(rsp->getResult());

    DEBUG_LEAVE("initialize");

    return ret;
}

jrpc::IRspMsgUP ClientMessageDispatcher::sendMethodRequest(const std::string &method, const nlohmann::json &params) {
    DEBUG_ENTER("sendMethodRequest: %s", method.c_str());
    nlohmann::json msg;
    msg["jsonrpc"] = "2.0";
    msg["id"] = m_req_id;
    m_req_id++;
    msg["method"] = method;
    msg["params"] = params;

    m_rsp.release();
    
    m_transport->send(msg);

    while (!m_rsp) {
        if (!m_loop->process_one_event(-1)) {
            break;
        }
    }

    DEBUG_LEAVE("sendMethodRequest: %s", method.c_str());
    return std::move(m_rsp);
}

void ClientMessageDispatcher::handleResult(int32_t id, jrpc::IRspMsgUP &rsp) {
    DEBUG_ENTER("handleResult %d", id);
    m_rsp = std::move(rsp);
    DEBUG_LEAVE("handleResult %d", id);
}

dmgr::IDebug *ClientMessageDispatcher::m_dbg = 0;

}
