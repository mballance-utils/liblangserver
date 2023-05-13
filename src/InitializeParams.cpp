/*
 * InitializeParams.cpp
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
#include "jrpc/impl/JsonUtil.h"
#include "InitializeParams.h"


namespace lls {


InitializeParams::InitializeParams(
        int32_t                         pid,
        IClientInfo                     *client_info,
        const std::string               &locale,
        const std::string               &rootPath,
        const std::string               &documentUri,
        const std::vector<std::string>  &workspace_folders) :
            m_pid(pid), m_client_info(client_info), m_locale(locale),
            m_rootPath(rootPath), m_documentUri(documentUri),
            m_workspace_folders(workspace_folders) {

}

InitializeParams::~InitializeParams() {

}

const nlohmann::json &InitializeParams::toJson() {
    m_json.clear();

    m_json["pid"] = m_pid;
    if (m_client_info) {
        // TODO: pack
    }
    if (m_locale != "") {
        m_json["locale"] = m_locale;
    }
    if (m_rootPath != "") {
        m_json["rootPath"] = m_rootPath;
    }
    m_json["documentUri"] = m_documentUri;

    if (m_workspace_folders.size() > 0) {
        nlohmann::json &ws_folders = m_json["workspace_folders"];
        for (std::vector<std::string>::const_iterator
            it=m_workspace_folders.begin();
            it!=m_workspace_folders.end(); it++) {
            ws_folders.push_back(*it);
        }
    }

    return m_json;
}

IInitializeParams *InitializeParams::mk(const nlohmann::json &params) {
    int32_t pid = -1;
    IClientInfo *client_info = 0;
    std::string locale;
    std::string rootPath;
    std::string documentUri;
    std::vector<std::string> workspace_folders;

    if (params.contains("pid")) {
        pid = jrpc::JsonUtil::getInt(params["pid"]);
    }

    if (params.contains("locale")) {
        locale = params["locale"];
    }

    if (params.contains("rootPath")) {
        rootPath = params["rootPath"];
    }

    if (params.contains("documentUri")) {
        documentUri = params["documentUri"];
    }

    if (params.contains("workspace_folders")) {
        const nlohmann::json &ws_folders = params["workspace_folders"];

        for (auto it=ws_folders.begin();
            it!=ws_folders.end(); it++) {
            workspace_folders.push_back(*it);
        }
    }

    return new InitializeParams(
        pid,
        client_info,
        locale,
        rootPath,
        documentUri,
        workspace_folders);
}

}
