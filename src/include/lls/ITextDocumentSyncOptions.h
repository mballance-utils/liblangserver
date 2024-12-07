/**
 * ITextDocumentSyncOptions.h
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

namespace lls {

enum class TextDocumentSyncKind {
    None,
    Full,
    Incremental
};

class ITextDocumentSyncOptions;
using ITextDocumentSyncOptionsUP=std::unique_ptr<ITextDocumentSyncOptions>;
class ITextDocumentSyncOptions : public virtual IJson {
public:

    virtual ~ITextDocumentSyncOptions() { }

    virtual bool getOpenClose() = 0;

    virtual void setOpenClose(bool e) = 0;

    virtual TextDocumentSyncKind getChange() = 0;

    virtual void setChange(TextDocumentSyncKind kind) = 0;

    virtual bool getWillSave() = 0;

    virtual void setWillSave(bool e) = 0;

    virtual bool getWillSaveWaitUntil() = 0;

    virtual void setWillSaveWaitUntil(bool e) = 0;

    virtual bool getSave() = 0;

    virtual void setSave(bool e) = 0;

    virtual bool getSaveIncludeText() = 0;

    virtual void setSaveIncludeText(bool e) = 0;

};

} /* namespace lls */


