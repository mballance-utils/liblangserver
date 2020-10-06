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
 * Range.cpp
 *
 *  Created on: Oct 5, 2020
 *      Author: ballance
 */

#include "Range.h"
#include "nlohmann/json.hpp"

namespace lls {

Range::Range(const nlohmann::json &msg) {
	m_start = Position::mk(msg["start"]);
	m_end = Position::mk(msg["end"]);
}

Range::Range(
		PositionSP		start,
		PositionSP		end) : m_start(start), m_end(end) {
	// TODO Auto-generated constructor stub

}

Range::~Range() {
	// TODO Auto-generated destructor stub
}

nlohmann::json Range::dump() {
	nlohmann::json msg;
	msg["start"] = m_start->dump();
	msg["end"] = m_end->dump();

	return msg;
}

RangeSP Range::mk(const nlohmann::json &msg) {
	return RangeSP(new Range(msg));
}

}
