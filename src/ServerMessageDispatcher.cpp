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
#include "DeclarationParams.h"
#include "DidChangeTextDocumentParams.h"
#include "DidCloseTextDocumentParams.h"
#include "DidOpenTextDocumentParams.h"
#include "DidSaveTextDocumentParams.h"
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
    m_dispatch->registerMethod("textDocument/didSave",
        std::bind(&ServerMessageDispatcher::didSaveNotification, this, std::placeholders::_1));
    m_dispatch->registerMethod("textDocument/didClose",
        std::bind(&ServerMessageDispatcher::didCloseNotification, this, std::placeholders::_1));
    m_dispatch->registerMethod("textDocument/hover",
        std::bind(&ServerMessageDispatcher::hoverRequest, this, std::placeholders::_1));
    m_dispatch->registerMethod("textDocument/declaration",
        std::bind(&ServerMessageDispatcher::declaration, this, std::placeholders::_1));
    m_dispatch->registerMethod("textDocument/definition",
        std::bind(&ServerMessageDispatcher::definition, this, std::placeholders::_1));
    m_dispatch->registerMethod("textDocument/documentSymbol",
        std::bind(&ServerMessageDispatcher::documentSymbolRequest, this, std::placeholders::_1));
    m_dispatch->registerMethod("shutdown",
        std::bind(&ServerMessageDispatcher::shutdown, this, std::placeholders::_1));
    m_dispatch->registerMethod("exit",
        std::bind(&ServerMessageDispatcher::exit, this, std::placeholders::_1));
}

ServerMessageDispatcher::~ServerMessageDispatcher() {

}

void ServerMessageDispatcher::publishDiagnosticsNotification(
        IPublishDiagnosticsParamsUP         &params) {
    nlohmann::json msg;

    msg["jsonrpc"] = "2.0";
    msg["method"] = "textDocument/publishDiagnostics";
    msg["params"] = params->toJson();

    m_dispatch->getPeer()->send(msg);
}

void ServerMessageDispatcher::sendNotification(
        const std::string               &method,
        IJson                           *params) {
    nlohmann::json msg;

    msg["jsonrpc"] = "2.0";
    msg["method"] = method;
    msg["params"] = params->toJson();

    m_dispatch->getPeer()->send(msg);

    delete params;
}

void ServerMessageDispatcher::sendRspSuccess(
        const std::string               &id,
        IJson                           *result) {
    nlohmann::json msg;

    msg["id"] = id;
    msg["jsonrpc"] = "2.0";
    if (result) {
        msg["result"] = result->toJson();
    } else {
        msg["result"] = nullptr;
    }

    m_dispatch->getPeer()->send(msg);

    delete result;
}

void ServerMessageDispatcher::sendRspError(
        const std::string               &id,
        int32_t                         code,
        const std::string               &msg,
        IJson                           *data) {
    nlohmann::json rsp;

    rsp["id"] = id;
    rsp["jsonrpc"] = "2.0";
    rsp["code"] = code;
    rsp["message"] = msg;
    rsp["data"] = data->toJson();

    m_dispatch->getPeer()->send(rsp);

    delete data;
}

void ServerMessageDispatcher::initializeRequest(jrpc::IReqMsgUP &msg) {
    DEBUG_ENTER("initializeRequest");
    IInitializeParamsUP params(m_factory->mkInitializeParams(msg->getParams()));
    m_server->initialize(msg->getId(), params);

    DEBUG_LEAVE("initializeRequest");
}

void ServerMessageDispatcher::initializedRequest(jrpc::IReqMsgUP &msg) {
    DEBUG_ENTER("initializedRequest");
    m_server->initialized();
    DEBUG_LEAVE("initializedRequest");
};

void ServerMessageDispatcher::didOpenNotification(jrpc::IReqMsgUP &msg) {
    DEBUG_ENTER("didOpenNotification");
    IDidOpenTextDocumentParamsUP params(DidOpenTextDocumentParams::mk(msg->getParams()));
    m_server->didOpen(params);
    DEBUG_LEAVE("didOpenNotification");
}

void ServerMessageDispatcher::didChangeNotification(jrpc::IReqMsgUP &msg) {
    DEBUG_ENTER("didChangeNotification");
    IDidChangeTextDocumentParamsUP params(DidChangeTextDocumentParams::mk(msg->getParams()));
    m_server->didChange(params);
    DEBUG_LEAVE("didChangeNotification");
}

void ServerMessageDispatcher::didSaveNotification(jrpc::IReqMsgUP &msg) {
    DEBUG_ENTER("didSaveNotification");
    IDidSaveTextDocumentParamsUP params(DidSaveTextDocumentParams::mk(msg->getParams()));
    m_server->didSave(params);
    DEBUG_LEAVE("didSaveNotification");
}

void ServerMessageDispatcher::didCloseNotification(jrpc::IReqMsgUP &msg) {
    DEBUG_ENTER("didCloseNotification");
    IDidCloseTextDocumentParamsUP params(DidCloseTextDocumentParams::mk(msg->getParams()));
    m_server->didClose(params);
    DEBUG_LEAVE("didCloseNotification");
}

void ServerMessageDispatcher::declaration(jrpc::IReqMsgUP &msg) {
    DEBUG_ENTER("declaration");
    jrpc::IRspMsgUP rsp;
    IDeclarationParamsUP params(DeclarationParams::mk(msg->getParams()));
    m_server->declaration(msg->getId(), params);
    DEBUG_LEAVE("declaration");
}

void ServerMessageDispatcher::definition(jrpc::IReqMsgUP &msg) {
    DEBUG_ENTER("definition");
    jrpc::IRspMsgUP rsp;
    ITextDocumentPositionParamsUP params(TextDocumentPositionParams::mk(msg->getParams()));
    m_server->definition(msg->getId(), params);
    DEBUG_LEAVE("definition");
}

void ServerMessageDispatcher::documentSymbolRequest(jrpc::IReqMsgUP &msg) {
    DEBUG_ENTER("documentSymbolRequest");
    jrpc::IRspMsgUP rsp;

    IDocumentSymbolParamsUP params(DocumentSymbolParams::mk(msg->getParams()));
    m_server->documentSymbols(msg->getId(), params);

    DEBUG_LEAVE("documentSymbolRequest");
}

void ServerMessageDispatcher::hoverRequest(jrpc::IReqMsgUP &msg) {
    DEBUG_ENTER("hoverRequest");
    IHoverParamsUP params(HoverParams::mk(msg->getParams()));

    m_server->hover(msg->getId(), params);

    DEBUG_LEAVE("hoverRequest");
}

void ServerMessageDispatcher::shutdown(jrpc::IReqMsgUP &msg) {
    DEBUG_ENTER("shutdown");
    m_server->shutdown(msg->getId());
    DEBUG_LEAVE("shutdown");
}

void ServerMessageDispatcher::exit(jrpc::IReqMsgUP &msg) {
    DEBUG_ENTER("exit");
    m_server->exit();
    DEBUG_LEAVE("exit");
}

dmgr::IDebug *ServerMessageDispatcher::m_dbg = 0;
 
}
