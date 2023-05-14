/*
 * TextDocumentPositionParams.cpp
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
#include "Position.h"
#include "TextDocumentIdentifier.h"
#include "TextDocumentPositionParams.h"


namespace lls {


TextDocumentPositionParams::TextDocumentPositionParams(
    ITextDocumentIdentifierUP       &textDocument,
    IPositionUP                     &position) :
        m_textDocument(std::move(textDocument)), m_position(std::move(position)) {

}

TextDocumentPositionParams::TextDocumentPositionParams(const nlohmann::json &m) {
    m_textDocument = TextDocumentIdentifier::mk(m["textDocument"]);
    m_position = Position::mk(m["position"]);
}

TextDocumentPositionParams::~TextDocumentPositionParams() {

}

const nlohmann::json &TextDocumentPositionParams::toJson() {
    m_json.clear();
    m_json["textDocument"] = m_textDocument->toJson();
    m_json["position"] = m_position->toJson();
    return m_json;
}

ITextDocumentPositionParamsUP TextDocumentPositionParams::mk(const nlohmann::json &m) {
    return ITextDocumentPositionParamsUP(new TextDocumentPositionParams(m));
}


}
