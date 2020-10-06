/**
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */
/*
 * Position.cpp
 *
 *  Created on: Oct 5, 2020
 *      Author: ballance
 */

#include "Position.h"
#include "nlohmann/json.hpp"

namespace lls {

Position::Position(const nlohmann::json &msg) {
	m_line = ValInt::mk(msg["line"]);
	m_character = ValInt::mk(msg["character"]);
}

Position::Position(
		ValIntSP			line,
		ValIntSP			character) :
		m_line(line), m_character(character) {
	// TODO Auto-generated constructor stub

}

Position::~Position() {
	// TODO Auto-generated destructor stub
}

nlohmann::json Position::dump() {
	nlohmann::json msg;
	msg["line"] = m_line->dump();
	msg["character"] = m_character->dump();

	return msg;
}

PositionSP Position::mk(const nlohmann::json &msg) {
	return PositionSP(new Position(msg));
}

PositionSP Position::mk(ValIntSP line, ValIntSP character) {
	return PositionSP(new Position(line, character));
}


}
