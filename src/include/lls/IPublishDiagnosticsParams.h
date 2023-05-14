/**
 * IPublishDiagnosticsParams.h
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
#include <string>
#include <vector>
#include "lls/IDiagnostic.h"
#include "lls/IJson.h"

namespace lls {

class IPublishDiagnosticsParams;
using IPublishDiagnosticsParamsUP=std::unique_ptr<IPublishDiagnosticsParams>;
class IPublishDiagnosticsParams : public virtual IJson {
public:

    virtual ~IPublishDiagnosticsParams() { }

    virtual const std::string &getUri() = 0;

    virtual int32_t getVersion() = 0;

    virtual const std::vector<IDiagnosticUP> &getDiagnostics() = 0;


};

} /* namespace lls */


