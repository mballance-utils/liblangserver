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
        jrpc::ITaskQueue            *queue,
        jrpc::IMessageTransport     *transport,
        IClient                     *client) :
            m_factory(factory), m_loop(0), 
            m_transport(transport), m_client(client) {
    DEBUG_INIT("ClientMessageDispatcher", factory->getDebugMgr());

    m_loop = transport->getLoop();

    m_dispatcher = m_factory->getFactory()->mkNBSocketServerMessageDispatcher(
        queue,
        m_transport
    );
    m_dispatcher->setResponseHandler(
        std::bind(&ClientMessageDispatcher::handleResult, this, 
            std::placeholders::_1, std::placeholders::_2));

}

ClientMessageDispatcher::~ClientMessageDispatcher() {

}

void ClientMessageDispatcher::initialize(
    const std::string       &id,
    IInitializeParamsUP     &params) {
    DEBUG_ENTER("initialize");

    // Send a request and poll waiting for a response
    jrpc::IRspMsgUP rsp(sendMethodRequest("initialize", params->toJson()));

    DEBUG_LEAVE("initialize");
}

void ClientMessageDispatcher::initialized() {
    DEBUG_ENTER("initialized");
    nlohmann::json params;

    sendNotification("initialized", params);

    DEBUG_LEAVE("initialized");
}

void ClientMessageDispatcher::didOpen(IDidOpenTextDocumentParamsUP &params) {
    DEBUG_ENTER("didOpen");
    nlohmann::json msg_params = params->toJson();
    sendNotification("textDocument/didOpen", msg_params);
    DEBUG_LEAVE("didOpen");
}

void ClientMessageDispatcher::didChange(IDidChangeTextDocumentParamsUP &params) {
    DEBUG_ENTER("didChange");
    nlohmann::json msg_params = params->toJson();
    sendNotification("textDocument/didChange", msg_params);
    DEBUG_LEAVE("didChange");
}

void ClientMessageDispatcher::didClose(IDidCloseTextDocumentParamsUP &params) {
    DEBUG_ENTER("didClose");
    DEBUG("TODO");
    DEBUG_LEAVE("didClose");
}

void ClientMessageDispatcher::documentSymbols(
    const std::string               &id,
    IDocumentSymbolParamsUP         &params) {
    DEBUG_ENTER("documentSymbols");
    DEBUG("TODO");
    DEBUG_LEAVE("documentSymbols");
}

void ClientMessageDispatcher::declaration(
        const std::string           &id,
        IDeclarationParamsUP        &params) {
}

void ClientMessageDispatcher::definition(
        const std::string           &id,
        ITextDocumentPositionParamsUP        &params) {
}

void ClientMessageDispatcher::hover(
    const std::string               &id,
    IHoverParamsUP                  &params) {
    DEBUG_ENTER("hover");
    DEBUG("TODO: hover");
    DEBUG_LEAVE("hover");
}

void ClientMessageDispatcher::shutdown(const std::string &id) {

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

void ClientMessageDispatcher::sendNotification(const std::string &method, const nlohmann::json &params) {
    DEBUG_ENTER("sendNotification");
    nlohmann::json msg;
    msg["jsonrpc"] = "2.0";
    msg["method"] = method;
    msg["params"] = params;

    m_rsp.release();
    
    m_transport->send(msg);

    DEBUG_LEAVE("sendNotification");
}

void ClientMessageDispatcher::handleResult(const std::string &id, jrpc::IRspMsgUP &rsp) {
    DEBUG_ENTER("handleResult %s", id.c_str());
    m_rsp = std::move(rsp);
    DEBUG_LEAVE("handleResult %s", id.c_str());
}

dmgr::IDebug *ClientMessageDispatcher::m_dbg = 0;

}
