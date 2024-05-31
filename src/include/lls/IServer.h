/**
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */
/*
 * IServer.h
 *
 *  Created on: Oct 1, 2020
 *      Author: ballance
 */

#pragma once
#include <memory>
#include "lls/IHover.h"
#include "lls/IHoverParams.h"
#include "lls/IClient.h"
#include "lls/IInitializeParams.h"
#include "lls/IInitializeResult.h"
#include "lls/IServerCapabilities.h"
#include "lls/IDeclarationParams.h"
#include "lls/IDidChangeTextDocumentParams.h"
#include "lls/IDidCloseTextDocumentParams.h"
#include "lls/IDidOpenTextDocumentParams.h"
#include "lls/IDocumentSymbolParams.h"
#include "lls/IDocumentSymbolResponse.h"


namespace lls {
class IServer;
using IServerUP=std::unique_ptr<IServer>;
class IServer {
public:

	virtual ~IServer() { }

    virtual void init(IClient *client) = 0;

	virtual void initialize(
        const std::string           &id,
        IInitializeParamsUP         &params) = 0;

    virtual void initialized() = 0;

    virtual void didOpen(IDidOpenTextDocumentParamsUP &params) = 0;

    virtual void didChange(IDidChangeTextDocumentParamsUP &params) = 0;

    virtual void didClose(IDidCloseTextDocumentParamsUP &params) = 0;

    /*
     * Expected to submit a response of DocumentSymbolResponse
     */
    virtual void documentSymbols(
        const std::string           &id,
        IDocumentSymbolParamsUP     &params) = 0;

    virtual void hover(
        const std::string           &id,
        IHoverParamsUP              &params) = 0;

    virtual void declaration(
        const std::string           &id,
        IDeclarationParamsUP        &params) = 0;

    virtual void definition(
        const std::string               &id,
        ITextDocumentPositionParamsUP   &params) = 0;

    virtual void shutdown(
        const std::string           &id) = 0;

/*
	virtual void didChangeTextDocument(DidChangeTextDocumentParamsSP params) = 0;

	virtual void didOpenTextDocument(DidOpenTextDocumentParamsSP params) = 0;

	virtual HoverSP hoverRequest(HoverParamsSP params) = 0;
 */

};

}
