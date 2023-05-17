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
#include "DidChangeTextDocumentParams.h"
#include "DidCloseTextDocumentParams.h"
#include "DidOpenTextDocumentParams.h"
#include "DocumentSymbolParams.h"
#include "HoverParams.h"


namespace lls {


ServerMessageDispatcher::ServerMessageDispatcher(
    IFactory                    *factory,
    jrpc::IMessageDispatcher    *dispatch,
    IServer                     *server) :
        m_factory(factory), m_dispatch(dispatch), 
        m_server(server) {
    DEBUG_INIT("ServerMessageDispatcher", factory->getDebugMgr());

    // The dispatcher implements the Client API
    server->init(this);

    m_dispatch->registerMethod("initialize",
        std::bind(&ServerMessageDispatcher::initializeRequest, this, std::placeholders::_1));
    m_dispatch->registerMethod("initialized",
        std::bind(&ServerMessageDispatcher::initializedRequest, this, std::placeholders::_1));
    m_dispatch->registerMethod("textDocument/didOpen",
        std::bind(&ServerMessageDispatcher::didOpenNotification, this, std::placeholders::_1));
    m_dispatch->registerMethod("textDocument/didChange",
        std::bind(&ServerMessageDispatcher::didChangeNotification, this, std::placeholders::_1));
    m_dispatch->registerMethod("textDocument/didClose",
        std::bind(&ServerMessageDispatcher::didCloseNotification, this, std::placeholders::_1));
    m_dispatch->registerMethod("textDocument/hover",
        std::bind(&ServerMessageDispatcher::hoverRequest, this, std::placeholders::_1));
    m_dispatch->registerMethod("textDocument/documentSymbol",
        std::bind(&ServerMessageDispatcher::documentSymbolRequest, this, std::placeholders::_1));
}

ServerMessageDispatcher::~ServerMessageDispatcher() {

}

void ServerMessageDispatcher::publishDiagnosticsNotification(
        IPublishDiagnosticsParamsUP         &params) {
    nlohmann::json msg;

    msg["method"] = "textDocument/publishDiagnostics";
    msg["params"] = params->toJson();

    m_dispatch->getPeer()->send(msg);
}

jrpc::IRspMsgUP ServerMessageDispatcher::initializeRequest(jrpc::IReqMsgUP &msg) {
    DEBUG_ENTER("initializeRequest");
    IInitializeParamsUP params(m_factory->mkInitializeParams(msg->getParams()));
    IInitializeResultUP result(m_server->initialize(params));
    jrpc::IRspMsgUP rsp;

    DEBUG("result: %p", result.get());
    if (result.get()) {
        rsp = jrpc::IRspMsgUP(m_factory->getFactory()->mkRspMsgSuccess(
            msg->getId(),
            result->toJson()
        ));
    }

    DEBUG_LEAVE("initializeRequest");
    return rsp;
}

jrpc::IRspMsgUP ServerMessageDispatcher::initializedRequest(jrpc::IReqMsgUP &msg) {
    DEBUG_ENTER("initializedRequest");
    m_server->initialized();
    DEBUG_LEAVE("initializedRequest");
    return 0;
};

jrpc::IRspMsgUP ServerMessageDispatcher::didOpenNotification(jrpc::IReqMsgUP &msg) {
    DEBUG_ENTER("didOpenNotification");
    IDidOpenTextDocumentParamsUP params(DidOpenTextDocumentParams::mk(msg->getParams()));
    m_server->didOpen(params);
    DEBUG_LEAVE("didOpenNotification");
    return 0;
}

jrpc::IRspMsgUP ServerMessageDispatcher::didChangeNotification(jrpc::IReqMsgUP &msg) {
    DEBUG_ENTER("didChangeNotification");
    IDidChangeTextDocumentParamsUP params(DidChangeTextDocumentParams::mk(msg->getParams()));
    m_server->didChange(params);
    DEBUG_LEAVE("didChangeNotification");
    return 0;
}

jrpc::IRspMsgUP ServerMessageDispatcher::didCloseNotification(jrpc::IReqMsgUP &msg) {
    DEBUG_ENTER("didCloseNotification");
    IDidCloseTextDocumentParamsUP params(DidCloseTextDocumentParams::mk(msg->getParams()));
    m_server->didClose(params);
    DEBUG_LEAVE("didCloseNotification");
    return 0;
}

jrpc::IRspMsgUP ServerMessageDispatcher::documentSymbolRequest(jrpc::IReqMsgUP &msg) {
    DEBUG_ENTER("documentSymbolRequest");
    jrpc::IRspMsgUP rsp;

    IDocumentSymbolParamsUP params(DocumentSymbolParams::mk(msg->getParams()));
    IDocumentSymbolResponseUP result(m_server->documentSymbols(params));

    rsp = jrpc::IRspMsgUP(m_factory->getFactory()->mkRspMsgSuccess(
        msg->getId(),
        result->toJson()));

    DEBUG_LEAVE("documentSymbolRequest");

    return rsp;
}

jrpc::IRspMsgUP ServerMessageDispatcher::hoverRequest(jrpc::IReqMsgUP &msg) {
    DEBUG_ENTER("hoverRequest");
    IHoverParamsUP params(HoverParams::mk(msg->getParams()));
    jrpc::IRspMsgUP rsp;

    IHoverUP result(m_server->hover(params));

    DEBUG("result: %p", result.get());
    if (result.get()) {
        rsp = jrpc::IRspMsgUP(m_factory->getFactory()->mkRspMsgSuccess(
            msg->getId(),
            result->toJson()
        ));
    }

    DEBUG_LEAVE("hoverRequest");
    return rsp;
}

dmgr::IDebug *ServerMessageDispatcher::m_dbg = 0;
 
}
