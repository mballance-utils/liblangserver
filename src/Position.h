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
 * Position.h
 *
 *  Created on: Oct 5, 2020
 *      Author: ballance
 */

#pragma once
#include "Val.h"
#include "ValInt.h"

namespace lls {

class Position;
typedef std::shared_ptr<Position> PositionSP;
class Position : public Val {
public:
	Position(const nlohmann::json &msg);

	Position(
			ValIntSP		line,
			ValIntSP		character);

	virtual ~Position();

	ValIntSP line() const { return m_line; }

	void line(ValIntSP l) { m_line = l; }

	ValIntSP character() const { return m_character; }

	void character(ValIntSP v) { m_character = v; }

	virtual nlohmann::json dump();

	static PositionSP mk(
			ValIntSP line,
			ValIntSP character);

	static PositionSP mk(const nlohmann::json &msg);

private:
	ValIntSP			m_line;
	ValIntSP			m_character;

};

}
