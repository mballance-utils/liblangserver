/**
 * TextDocumentSyncOptions.h
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
#include "lls/ITextDocumentSyncOptions.h"
#include "Json.h"

namespace lls {



class TextDocumentSyncOptions :
    public virtual ITextDocumentSyncOptions,
    public virtual Json {
public:
    TextDocumentSyncOptions(
        bool                    open_close,
        TextDocumentSyncKind    sync_kind,
        bool                    will_save,
        bool                    will_save_wait_until,
        bool                    save,
        bool                    save_include_text
    );

    virtual ~TextDocumentSyncOptions();

    virtual bool getOpenClose() override {
        return m_open_close;
    }

    virtual void setOpenClose(bool e) override {
        m_open_close = e;
    }

    virtual TextDocumentSyncKind getChange() override {
        return m_sync_kind;
    }

    virtual void setChange(TextDocumentSyncKind kind) override {
        m_sync_kind = kind;
    }

    virtual bool getWillSave() override {
        return m_will_save;
    }

    virtual void setWillSave(bool e) override {
        m_will_save = e;
    }

    virtual bool getWillSaveWaitUntil() override {
        return m_will_save_wait_until;
    }

    virtual void setWillSaveWaitUntil(bool e) override {
        m_will_save_wait_until = e;
    }

    virtual bool getSave() override {
        return m_save;
    }

    virtual void setSave(bool e) override {
        m_save = e;
    }

    virtual bool getSaveIncludeText() override {
        return m_save_include_text;
    }

    virtual void setSaveIncludeText(bool e) override {
        m_save_include_text = e;
    }

    const nlohmann::json &toJson();

    static TextDocumentSyncOptions *mk(const nlohmann::json &msg);

private:
    bool                    m_open_close;
    TextDocumentSyncKind    m_sync_kind;
    bool                    m_will_save;
    bool                    m_will_save_wait_until;
    bool                    m_save;
    bool                    m_save_include_text;

};

}


