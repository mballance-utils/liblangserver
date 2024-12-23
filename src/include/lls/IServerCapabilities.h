/**
 * IServerCapabilities.h
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
#include "lls/IJson.h"
#include "lls/ITextDocumentSyncOptions.h"

namespace lls {

class IServerCapabilities;
using IServerCapabilitiesUP=std::unique_ptr<IServerCapabilities>;
class IServerCapabilities : public virtual IJson {
public:

    virtual ~IServerCapabilities() { }

    virtual ITextDocumentSyncOptions *getTextDocumentSync() = 0;


    virtual bool getHoverProvider() = 0;

    virtual void setHoverProvider(bool have) = 0;

    virtual void setDeclarationProvider(bool have) = 0;

    virtual bool getDocumentSymbolProvider() = 0;

    virtual void setDocumentSymbolProvider(bool have) = 0;

};

} /* namespace lls */


