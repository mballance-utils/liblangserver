/*
 * Position.cpp
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


namespace lls {


Position::Position(
    int32_t         line,
    int32_t         character) : m_line(line), m_character(character) {

}

Position::~Position() {

}

const nlohmann::json &Position::toJson() {
    m_json.clear();
    m_json["line"] = m_line;
    m_json["character"] = m_character;
    return m_json;
}

IPositionUP Position::mk(const nlohmann::json &m) {
    int32_t line = m["line"];
    int32_t character = m["character"];
    return IPositionUP(new Position(line, character));
}

}
