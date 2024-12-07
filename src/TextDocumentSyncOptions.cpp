/*
 * TextDocumentSyncOptions.cpp
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
#include "TextDocumentSyncOptions.h"


namespace lls {


TextDocumentSyncOptions::TextDocumentSyncOptions(
    bool                        open_close,
    TextDocumentSyncKind        sync_kind,
    bool                        will_save,
    bool                        will_save_wait_until,
    bool                        save,
    bool                        save_include_text) :
    m_open_close(open_close), m_sync_kind(sync_kind),
    m_will_save(will_save), m_will_save_wait_until(will_save_wait_until),
    m_save(save), m_save_include_text(save_include_text) {

}

TextDocumentSyncOptions::~TextDocumentSyncOptions() {

}

const nlohmann::json &TextDocumentSyncOptions::toJson() {
    m_json.clear();
    m_json["openClose"] = m_open_close;

    switch (m_sync_kind) {
        case TextDocumentSyncKind::None:
            m_json["change"] = 0;
            break;
        case TextDocumentSyncKind::Incremental:
            m_json["change"] = 1;
            break;
        case TextDocumentSyncKind::Full:
            m_json["change"] = 2;
            break;
        default:
            m_json["change"] = "Unknown";
            break;
    }

    m_json["willSave"] = m_will_save;
    m_json["willSaveWaitUntil"] = m_will_save_wait_until;
    if (m_save) {
        nlohmann::json &save = m_json["save"];
        save["includeText"] = m_save_include_text;
    } else {
        m_json["save"] = m_save;
    }

    return m_json;
}

TextDocumentSyncOptions *TextDocumentSyncOptions::mk(const nlohmann::json &msg) {
    bool open_close = false;
    TextDocumentSyncKind kind = TextDocumentSyncKind::None;
    bool will_save = false;
    bool will_save_wait_until = false;
    bool save = false;
    bool save_include_text = false;

    if (msg.contains("openClose")) {
        open_close = msg["openClose"];
    }

    if (msg.contains("change")) {
        if (msg["change"] == 0) {
            kind = TextDocumentSyncKind::None;
        } else if (msg["change"] == 1) {
            kind = TextDocumentSyncKind::Incremental;
        } else if (msg["change"] == 2) {
            kind = TextDocumentSyncKind::Full;
        }
    }

    if (msg.contains("willSave")) {
        will_save = msg["willSave"];
    }

    if (msg.contains("willSaveWaitUntil")) {
        will_save_wait_until = msg["willSaveWaitUntil"];
    }

    if (msg.contains("save")) {
        if (msg["save"].is_boolean()) {
            save = msg["save"];
        } else if (msg["save"].contains("includeText")) {
            save = true;
            save_include_text = msg["save"]["includeText"];    
        }
    }


    return new TextDocumentSyncOptions(
        open_close, 
        kind,
        will_save,
        will_save_wait_until,
        save,
        save_include_text);
}

}
