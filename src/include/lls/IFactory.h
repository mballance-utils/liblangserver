/**
 * IFactory.h
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
#include "jrpc/IFactory.h"
#include "lls/IClient.h"
#include "lls/IClientInfo.h"
#include "lls/IClientMessageDispatcher.h"
#include "lls/IContent.h"
#include "lls/IDiagnostic.h"
#include "lls/IDocumentSymbol.h"
#include "lls/IDocumentSymbolParams.h"
#include "lls/IDocumentSymbolResponse.h"
#include "lls/IHover.h"
#include "lls/IInitializeParams.h"
#include "lls/IInitializeResult.h"
#include "lls/ILocation.h"
#include "lls/ILocationList.h"
#include "lls/ILocationLink.h"
#include "lls/ILocationLinkList.h"
#include "lls/IMarkedString.h"
#include "lls/IMarkupContent.h"
#include "lls/INull.h"
#include "lls/IPublishDiagnosticsParams.h"
#include "lls/IServer.h"
#include "lls/IServerMessageDispatcher.h"
#include "lls/ITextDocumentSyncOptions.h"

namespace lls {



class IFactory {
public:

    virtual ~IFactory() { }

    virtual void init(jrpc::IFactory *f) = 0;

    virtual jrpc::IFactory *getFactory() = 0;

    virtual dmgr::IDebugMgr *getDebugMgr() = 0;

    virtual IMarkedStringUP mkContentMarkedString(
        const std::string       &language,
        const std::string       &value) = 0;

    virtual IServerMessageDispatcher *mkNBServerMessageDispatcher(
        jrpc::ITaskQueue            *queue,
        jrpc::IMessageTransport     *transport,
        IServer                     *server
    ) = 0;

    virtual IClientMessageDispatcherUP mkClientMessageDispatcher(
        jrpc::ITaskQueue            *queue,
        jrpc::IMessageTransport     *transport,
        IClient                     *client
    ) = 0;

    virtual IDiagnosticUP mkDiagnostic(
        IRangeUP                        &range,
        DiagnosticSeverity              severity,
        const std::string               &message) = 0;

    virtual IDocumentSymbolUP mkDocumentSymbol(
        const std::string               &name,
        SymbolKind                      kind,
        IRangeUP                        &range,
        IRangeUP                        &selectionRange
    ) = 0;

    virtual IDocumentSymbolResponseUP mkDocumentSymbolResponse(
        std::vector<IDocumentSymbolUP>  &symbols
    ) = 0;

    virtual IHoverUP mkHover(
        IJsonUP                         &contents,
        IRangeUP                        &range) = 0;

    virtual IInitializeParamsUP mkInitializeParams(
        int32_t                         pid,
        IClientInfo                     *client_info,
        const std::string               &locale,
        const std::string               &rootPath,
        const std::string               &documentUri,
        const std::vector<std::string>  &workspace_folders) = 0;

    virtual IInitializeParamsUP mkInitializeParams(
        const nlohmann::json            &params) = 0;

    virtual IInitializeResultUP mkInitializeResult(
        IServerCapabilitiesUP           &capabilities,
        IServerInfoUP                   &serverInfo
    ) = 0;

    virtual IInitializeResultUP mkInitializeResult(
        const nlohmann::json            &params) = 0;

    virtual ILocationUP mkLocation(
        const std::string               &uri,
        IRangeUP                        &range) = 0;

    virtual ILocationListUP mkLocationList(
        std::vector<ILocationUP>        &locations) = 0;

    virtual ILocationLinkUP mkLocationLink(
        IRangeUP                        &originSelectionRange,
        const std::string               &targetUri,
        IRangeUP                        &targetRange,
        IRangeUP                        &targetSelectionRange) = 0;

    virtual ILocationLinkListUP mkLocationLinkList(
        std::vector<ILocationLinkUP>    &locations) = 0;

    virtual IMarkupContentUP mkMarkupContent(
        MarkupKind                      kind,
        const std::string               &value) = 0;

    virtual INullUP mkNull() = 0;

    virtual IPositionUP mkPosition(
        int32_t                         line,
        int32_t                         character) = 0;

    virtual IPublishDiagnosticsParamsUP mkPublishDiagnosticsParams(
        const std::string               &uri,
        int32_t                         version,
        std::vector<IDiagnosticUP>      &diagnostics) = 0;

    virtual IRangeUP mkRange(
        IPositionUP                     &start,
        IPositionUP                     &end) = 0;

    virtual IServerCapabilitiesUP mkServerCapabilities(
        ITextDocumentSyncOptionsUP      &textDocumentSync
    ) = 0;

    virtual ITextDocumentSyncOptionsUP mkTextDocumentSyncOptions(
        bool                            open_close,
        TextDocumentSyncKind            sync_kind,
        bool                            will_save,
        bool                            will_save_wait_until,
        bool                            save,
        bool                            save_include_text
    ) = 0;

};

} /* namespace lls */


