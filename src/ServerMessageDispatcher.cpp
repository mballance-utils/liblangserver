/*
 * ServerMessageDispatcher.cpp
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
#include "ServerMessageDispatcher.h"


namespace lls {


ServerMessageDispatcher::ServerMessageDispatcher(
    IFactory                    *factory,
    jrpc::IMessageDispatcher    *dispatch,
    IServer                     *server) :
        m_factory(factory), m_dispatch(dispatch), 
        m_server(server) {
    DEBUG_INIT("ServerMessageDispatcher", factory->getDebugMgr());

    m_dispatch->registerMethod("initialize",
        std::bind(&ServerMessageDispatcher::initializeRequest, this, std::placeholders::_1));
}

ServerMessageDispatcher::~ServerMessageDispatcher() {

}

jrpc::IRspMsgUP ServerMessageDispatcher::initializeRequest(jrpc::IReqMsgUP &msg) {
    DEBUG_ENTER("initializeRequest");
    IInitializeParamsUP params(m_factory->mkInitializeParams(msg->getParams()));
    IInitializeResultUP result(m_server->initialize(params));
    jrpc::IRspMsgUP rsp;

    if (result) {
        rsp = jrpc::IRspMsgUP(m_factory->getFactory()->mkRspMsgSuccess(
            msg->getId(),
            result->toJson()
        ));
    }

    DEBUG_LEAVE("initializeRequest");
    return rsp;
}

dmgr::IDebug *ServerMessageDispatcher::m_dbg = 0;

}
