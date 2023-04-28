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
#include "jrpc/IEventLoop.h"
#include "lls/IFactory.h"
#include "lls/IInitializeParams.h"
#include "lls/IServerCapabilities.h"

namespace lls {

class IServer {
public:

	virtual ~IServer() { }

/*
    virtual void init(
        jrpc::IEventLoop            *loop,
        IFactory                    *factory,
        IClientConnection           *connection) = 0;

	virtual IServerCapabilitiesUP initialize(IInitializeParamsUP params) = 0;

	virtual void didChangeTextDocument(DidChangeTextDocumentParamsSP params) = 0;

	virtual void didOpenTextDocument(DidOpenTextDocumentParamsSP params) = 0;

	virtual HoverSP hoverRequest(HoverParamsSP params) = 0;
 */

};

}
