/*
 * TextDocumentContentChangeEvent.cpp
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
#include "Range.h"
#include "TextDocumentContentChangeEvent.h"


namespace lls {


TextDocumentContentChangeEvent::TextDocumentContentChangeEvent(
    IRangeUP            &range,
    const std::string   &text) : m_range(std::move(range)), m_text(text) {

}

TextDocumentContentChangeEvent::~TextDocumentContentChangeEvent() {

}

const nlohmann::json &TextDocumentContentChangeEvent::toJson() {
    m_json.clear();
    if (m_range.get()) {
        m_json["range"] = m_range->toJson();
    }
    m_json["text"] = m_text;

    return m_json;
}

ITextDocumentContentChangeEventUP TextDocumentContentChangeEvent::mk(
    const nlohmann::json &m) {
    IRangeUP range;
    
    if (m.contains("range")) {
        range = IRangeUP(Range::mk(m["range"]));
    }
    std::string text = m["text"];

    return ITextDocumentContentChangeEventUP(new TextDocumentContentChangeEvent(
        range,
        text
    ));
}

}
