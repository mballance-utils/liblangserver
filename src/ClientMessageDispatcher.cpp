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


namespace lls {


ClientMessageDispatcher::ClientMessageDispatcher(
        IFactory                    *factory,
        jrpc::IEventLoop            *loop,
        jrpc::IMessageTransport     *transport) :
            m_factory(factory), m_loop(loop), m_transport(transport) {
    DEBUG_INIT("ClientMessageDispatcher", factory->getDebugMgr());

    m_dispatcher = m_factory->getFactory()->mkNBSocketServerMessageDispatcher(
        m_transport
    );

    // initializeResult
    m_dispatcher->registerMethod(
        "initializeResult", 
        std::bind(&ClientMessageDispatcher::initializeResult, this, std::placeholders::_1));

}

ClientMessageDispatcher::~ClientMessageDispatcher() {

}

IServerCapabilitiesUP ClientMessageDispatcher::initialize(IInitializeParamsUP params) {
    params->toJson();

    // Send a request and poll waiting for a response

}

jrpc::IRspMsgUP ClientMessageDispatcher::initializeResult(jrpc::IReqMsgUP &msg) {
    m_initializeResult = m_factory->mkInitializeResult(msg->getParams());

    return jrpc::IRspMsgUP();
}

dmgr::IDebug *ClientMessageDispatcher::m_dbg = 0;

}
