/*
 * Diagnostic.cpp
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
#include "Diagnostic.h"


namespace lls {


Diagnostic::Diagnostic(
    IRangeUP            &range,
    DiagnosticSeverity  severity,
    const std::string   &message) :
        m_range(std::move(range)),
        m_severity(severity),
        m_message(message) {


}

Diagnostic::~Diagnostic() {

}

const nlohmann::json &Diagnostic::toJson() {
    m_json.clear();
    m_json["range"] = m_range->toJson();

    int severity_n = -1;
    switch (m_severity) {
        case DiagnosticSeverity::Error:
            severity_n = 1;
            break;
        case DiagnosticSeverity::Warning:
            severity_n = 2;
            break;
        case DiagnosticSeverity::Information:
            severity_n = 3;
            break;
        case DiagnosticSeverity::Hint:
            severity_n = 4;
            break;
    }
    m_json["severity"] = severity_n;
    m_json["message"] = m_message;

    return m_json;
}

}
