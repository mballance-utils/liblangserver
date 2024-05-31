/**
 * Factory.h
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
#include <memory>
#include "lls/IFactory.h"

namespace lls {


class Factory : public virtual IFactory {
public:
    Factory();

    virtual ~Factory();

    virtual void init(jrpc::IFactory *f) override {
        m_factory = f;
    }

    virtual jrpc::IFactory *getFactory() override {
        return m_factory;
    }

    virtual dmgr::IDebugMgr *getDebugMgr();

    virtual IMarkedStringUP mkContentMarkedString(
        const std::string       &language,
        const std::string       &value) override;

    virtual IServerMessageDispatcher *mkNBServerMessageDispatcher(
        jrpc::ITaskQueue            *queue,
        jrpc::IMessageTransport     *transport,
        IServer                     *server
    ) override;

    virtual IClientMessageDispatcherUP mkClientMessageDispatcher(
        jrpc::ITaskQueue            *queue,
        jrpc::IMessageTransport     *transport,
        IClient                     *client
    ) override;
    
    virtual IDiagnosticUP mkDiagnostic(
        IRangeUP                        &range,
        DiagnosticSeverity              severity,
        const std::string               &message) override;
        
    virtual IDocumentSymbolUP mkDocumentSymbol(
        const std::string               &name,
        SymbolKind                      kind,
        IRangeUP                        &range,
        IRangeUP                        &selectionRange) override;

    virtual IDocumentSymbolResponseUP mkDocumentSymbolResponse(
        std::vector<IDocumentSymbolUP>  &symbols) override;


    virtual IHoverUP mkHover(
        IJsonUP                         &contents,
        IRangeUP                        &range) override;

    virtual IInitializeParamsUP mkInitializeParams(
        int32_t                         pid,
        IClientInfo                     *client_info,
        const std::string               &locale,
        const std::string               &rootPath,
        const std::string               &documentUri,
        const std::vector<std::string>  &workspace_folders) override;

    virtual IInitializeParamsUP mkInitializeParams(
        const nlohmann::json            &params) override;

    virtual IInitializeResultUP mkInitializeResult(
        IServerCapabilitiesUP           &capabilities,
        IServerInfoUP                   &serverInfo) override;

    virtual IInitializeResultUP mkInitializeResult(
        const nlohmann::json            &params) override;

    virtual ILocationUP mkLocation(
        const std::string               &uri,
        IRangeUP                        &range) override;

    virtual ILocationListUP mkLocationList(
        std::vector<ILocationUP>        &locations) override;

    virtual ILocationLinkUP mkLocationLink(
        IRangeUP                        &originSelectionRange,
        const std::string               &targetUri,
        IRangeUP                        &targetRange,
        IRangeUP                        &targetSelectionRange) override;

    virtual ILocationLinkListUP mkLocationLinkList(
        std::vector<ILocationLinkUP>    &locations) override;

    virtual IMarkupContentUP mkMarkupContent(
        MarkupKind                      kind,
        const std::string               &value) override;

    virtual INullUP mkNull() override;

    virtual IPositionUP mkPosition(
        int32_t                         line,
        int32_t                         character) override;

    virtual IPublishDiagnosticsParamsUP mkPublishDiagnosticsParams(
        const std::string               &uri,
        int32_t                         version,
        std::vector<IDiagnosticUP>      &diagnostics) override;

    virtual IRangeUP mkRange(
        IPositionUP                     &start,
        IPositionUP                     &end) override;

    virtual IServerCapabilitiesUP mkServerCapabilities(
        ITextDocumentSyncOptionsUP      &textDocumentSync
    ) override;

    virtual ITextDocumentSyncOptionsUP mkTextDocumentSyncOptions(
        bool                            open_close,
        TextDocumentSyncKind            sync_kind
    ) override;

    static IFactory *inst();

private:
    static std::unique_ptr<IFactory>     m_inst;
    jrpc::IFactory                      *m_factory;
};

}


