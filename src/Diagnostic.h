/**
 * Diagnostic.h
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
#include "lls/IDiagnostic.h"
#include "Json.h"

namespace lls {



class Diagnostic :
    public virtual IDiagnostic,
    public virtual Json {
public:
    Diagnostic(
        IRangeUP            &range,
        DiagnosticSeverity  severity,
        const std::string   &message
    );

    virtual ~Diagnostic();

    virtual IRange *getRange() override {
        return m_range.get();
    }

    virtual DiagnosticSeverity getSeverity() override {
        return m_severity;
    }

    virtual const std::string &getMessage() override {
        return m_message;
    }

    virtual const nlohmann::json &toJson() override;

private:
    IRangeUP                m_range;
    DiagnosticSeverity      m_severity;
    std::string             m_message;
};

}


