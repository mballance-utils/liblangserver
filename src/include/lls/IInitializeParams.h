/**
 * IInitializeParams.h
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
#include <stdint.h>
#include <memory>
#include <string>
#include <vector>
#include "lls/IClientInfo.h"
#include "lls/IJson.h"

namespace lls {

class IInitializeParams;
using IInitializeParamsUP=std::unique_ptr<IInitializeParams>;
class IInitializeParams : public virtual IJson {
public:

    virtual ~IInitializeParams() { }

    virtual int32_t getProcessId() = 0;

    virtual IClientInfo *getCientInfo() = 0;

    virtual const std::string &getLocale() = 0;

    virtual const std::string &getRootPath() = 0;

    virtual const std::string &getDocumentUri() = 0;

    // TODO: initializationOptions

    virtual const std::vector<std::string> &getWorkspaceFolders() const = 0;

};

} /* namespace lls */


