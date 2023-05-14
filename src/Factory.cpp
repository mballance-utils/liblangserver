/*
 * Factory.cpp
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
#include "Factory.h"
#include "lls/FactoryExt.h"
#include "ClientMessageDispatcher.h"
#include "Hover.h"
#include "InitializeParams.h"
#include "InitializeResult.h"
#include "MarkedString.h"
#include "ServerCapabilities.h"
#include "ServerMessageDispatcher.h"
#include "TextDocumentSyncOptions.h"

namespace lls {


Factory::Factory() : m_factory(0) {

}

Factory::~Factory() {

}

dmgr::IDebugMgr *Factory::getDebugMgr() {
    return m_factory->getDebugMgr();
}

IServerMessageDispatcher *Factory::mkNBServerMessageDispatcher(
        jrpc::IMessageTransport     *transport,
        IServer                     *server) {
    return new ServerMessageDispatcher(
        this, 
        m_factory->mkNBSocketServerMessageDispatcher(transport),
        server);
}

IClientMessageDispatcherUP Factory::mkClientMessageDispatcher(
        jrpc::IMessageTransport     *transport,
        IClient                     *client) {
    return IClientMessageDispatcherUP(new ClientMessageDispatcher(
        this,
        transport,
        client
    ));
}

IMarkedStringUP Factory::mkContentMarkedString(
        const std::string       &language,
        const std::string       &value) {
    return IMarkedStringUP(new MarkedString(language, value));
}

IDiagnosticUP Factory::mkDiagnostic(
        IRangeUP                        &range,
        DiagnosticSeverity              severity,
        const std::string               &message) {

}

IHoverUP Factory::mkHover(
        IContentUP                      &contents,
        IRangeUP                        &range) {
    return IHoverUP(new Hover(contents, range));
}


IInitializeParamsUP Factory::mkInitializeParams(
        int32_t                         pid,
        IClientInfo                     *client_info,
        const std::string               &locale,
        const std::string               &rootPath,
        const std::string               &documentUri,
        const std::vector<std::string>  &workspace_folders) {
    return IInitializeParamsUP(new InitializeParams(
        pid,
        client_info,
        locale,
        rootPath,
        documentUri,
        workspace_folders));
}

IInitializeParamsUP Factory::mkInitializeParams(
        const nlohmann::json            &params) {
    return IInitializeParamsUP(InitializeParams::mk(params));
}

IInitializeResultUP Factory::mkInitializeResult(
        IServerCapabilitiesUP           &capabilities,
        IServerInfoUP                   &serverInfo) {
    return IInitializeResultUP(new InitializeResult(capabilities, serverInfo));
}

IInitializeResultUP Factory::mkInitializeResult(
        const nlohmann::json            &params) {
    // TODO:
    return 0;
}

IPublishDiagnosticsParamsUP Factory::mkPublishDiagnosticsParams(
        const std::string               &uri,
        int32_t                         version,
        std::vector<IDiagnosticUP>      &diagnostics) {

}

IServerCapabilitiesUP Factory::mkServerCapabilities(
        ITextDocumentSyncOptionsUP      &textDocumentSync) {
    return IServerCapabilitiesUP(new ServerCapabilities(
        textDocumentSync
    ));
}


ITextDocumentSyncOptionsUP Factory::mkTextDocumentSyncOptions(
        bool                            open_close,
        TextDocumentSyncKind            sync_kind) {
    return ITextDocumentSyncOptionsUP(new TextDocumentSyncOptions(open_close, sync_kind));
}

IFactory *Factory::inst() {
    if (!m_inst) {
        m_inst = std::unique_ptr<IFactory>(new Factory());
    }
    return m_inst.get();
}

std::unique_ptr<IFactory> Factory::m_inst;

}

lls::IFactory *lls_getFactory() {
    return lls::Factory::inst();
}
