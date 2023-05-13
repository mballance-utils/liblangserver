/*
 * Range.cpp
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
#include "Range.h"


namespace lls {


Range::Range(
    IPositionUP     &start,
    IPositionUP     &end) : 
        m_start(start.release()), m_end(end.release()) {

}

Range::~Range() {

}

const nlohmann::json &Range::toJson() {
    m_json.clear();
    m_json["start"] = m_start->toJson();
    m_json["end"] = m_end->toJson();
    return m_json;
}

IRangeUP Range::mk(const nlohmann::json &m) {
    IPositionUP start(Position::mk(m["start"]));
    IPositionUP end(Position::mk(m["end"]));
    return IRangeUP(new Range(start, end));
}

}
