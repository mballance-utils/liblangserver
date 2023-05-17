/**
 * PublishDiagnosticsParams.h
 *
 * Copyright 2023 Matthew Ballance and Contributors
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
#include "Json.h"
#include "lls/IPublishDiagnosticsParams.h"

namespace lls {


class PublishDiagnosticsParams : 
    public virtual IPublishDiagnosticsParams,
    public virtual Json {
public:
    PublishDiagnosticsParams(
        const std::string           &uri,
        int32_t                     version,
        std::vector<IDiagnosticUP>  &diagnostics
    );

    virtual ~PublishDiagnosticsParams();

    virtual const std::string &getUri() override {
        return m_uri;
    }

    virtual int32_t getVersion() override {
        return m_version;
    }

    virtual const std::vector<IDiagnosticUP> &getDiagnostics() override {
        return m_diagnostics;
    }

    virtual const nlohmann::json &toJson() override;

private:
    std::string                     m_uri;
    int32_t                         m_version;
    std::vector<IDiagnosticUP>      m_diagnostics;
};

}


