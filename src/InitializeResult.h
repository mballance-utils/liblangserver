/**
 * InitializeResult.h
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
#include "lls/IInitializeResult.h"
#include "lls/IServerCapabilities.h"
#include "Json.h"

namespace lls {



class InitializeResult : 
    public virtual IInitializeResult,
    public virtual Json {
public:
    InitializeResult(
        IServerCapabilitiesUP   &capabilities,
        IServerInfoUP           &serverInfo
    );

    virtual ~InitializeResult();

    virtual IServerCapabilities *getCapabilities() override {
        return m_capabilities.get();
    }

    virtual IServerInfo *getServerInfo() override {
        return m_serverInfo.get();
    }

    virtual const nlohmann::json &toJson() override;

    static IInitializeResultUP mk(const nlohmann::json &params);

private:
    IServerCapabilitiesUP           m_capabilities;
    IServerInfoUP                   m_serverInfo;

};

}


