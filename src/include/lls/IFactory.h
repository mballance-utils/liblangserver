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
#include "lls/IClientInfo.h"
#include "lls/IInitializeParams.h"
#include "lls/IInitializeResult.h"
#include "lls/IServer.h"
#include "lls/IServerMessageDispatcher.h"

namespace lls {



class IFactory {
public:

    virtual ~IFactory() { }

    virtual void init(jrpc::IFactory *f) = 0;

    virtual jrpc::IFactory *getFactory() = 0;

    virtual dmgr::IDebugMgr *getDebugMgr() = 0;

    virtual IServerMessageDispatcher *mkNBServerMessageDispatcher(
        jrpc::IMessageTransport     *transport,
        IServer                     *server
    ) = 0;

    virtual IInitializeParamsUP mkInitializeParams(
        int32_t                         pid,
        IClientInfo                     *client_info,
        const std::string               &locale,
        std::string                     &rootPath,
        std::string                     &documentUri,
        const std::vector<std::string>  &workspace_folders) = 0;

    virtual IInitializeParamsUP mkInitializeParams(
        const nlohmann::json            &params) = 0;

    virtual IInitializeResultUP mkInitializeResult(
        const nlohmann::json            &params) = 0;

};

} /* namespace lls */


