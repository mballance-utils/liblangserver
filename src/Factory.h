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

    virtual IServerMessageDispatcher *mkNBServerMessageDispatcher(
        jrpc::IMessageTransport     *transport,
        IServer                     *server
    ) override;

    virtual IInitializeParamsUP mkInitializeParams(
        int32_t                         pid,
        IClientInfo                     *client_info,
        const std::string               &locale,
        std::string                     &rootPath,
        std::string                     &documentUri,
        const std::vector<std::string>  &workspace_folders) override;

    virtual IInitializeParamsUP mkInitializeParams(
        const nlohmann::json            &params) override;

    virtual IInitializeResultUP mkInitializeResult(
        const nlohmann::json            &params) override;

    static IFactory *inst();

private:
    static std::unique_ptr<IFactory>     m_inst;
    jrpc::IFactory                      *m_factory;
};

}


