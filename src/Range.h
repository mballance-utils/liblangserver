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
 * Range.h
 *
 *  Created on: Oct 5, 2020
 *      Author: ballance
 */

#pragma once
#include "Val.h"
#include "Position.h"

namespace lls {

class Range;
typedef std::shared_ptr<Range> RangeSP;
class Range {
public:
	Range(const nlohmann::json &msg);

	Range(
		PositionSP		start,
		PositionSP		end);

	virtual ~Range();

	PositionSP start() const { return m_start; }

	void start(PositionSP v) { m_start = v; }

	PositionSP end() const { return m_end; }

	void end(PositionSP v) { m_end = v; }

	virtual nlohmann::json dump();

	static RangeSP mk(PositionSP start, PositionSP end);

	static RangeSP mk(const nlohmann::json &msg);

private:
	PositionSP			m_start;
	PositionSP			m_end;

};

}
