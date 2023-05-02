/**
 * InitializeParams.h
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
#include "lls/IClientInfo.h"
#include "lls/IInitializeParams.h"
#include "Json.h"

namespace lls {


class InitializeParams : 
    public virtual IInitializeParams,
    public virtual Json {
public:
    InitializeParams(
        int32_t                         pid,
        IClientInfo                     *client_info,
        const std::string               &locale,
        const std::string               &rootPath,
        const std::string               &documentUri,
        const std::vector<std::string>  &workspace_folders);

    virtual ~InitializeParams();

    virtual int32_t getProcessId() override { return m_pid; }

    virtual IClientInfo *getCientInfo() override { 
        return m_client_info.get(); 
    }

    virtual const std::string &getLocale() override {
        return m_locale;
    }

    virtual const std::string &getRootPath() override {
        return m_rootPath;
    }

    virtual const std::string &getDocumentUri() override {
        return m_documentUri;
    }

    // TODO: initializationOptions

    virtual const std::vector<std::string> &getWorkspaceFolders() const override {
        return m_workspace_folders;
    }

    virtual const nlohmann::json &toJson() override;

    static IInitializeParams *mk(const nlohmann::json &params);

private:
    int32_t                         m_pid;
    IClientInfoUP                   m_client_info;
    const std::string               m_locale;
    std::string                     m_rootPath;
    std::string                     m_documentUri;
    std::vector<std::string>        m_workspace_folders;

};

}


