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
 * WorkDoneProgressOptions.cpp
 *
 *  Created on: Oct 4, 2020
 *      Author: ballance
 */

#include "WorkDoneProgressOptions.h"
#include "nlohmann/json.hpp"

namespace lls {

WorkDoneProgressOptions::WorkDoneProgressOptions(ValBoolSP v) : m_workDoneProgress(v) {

}

WorkDoneProgressOptions::WorkDoneProgressOptions(const nlohmann::json &msg) {
	if (msg.contains("workDoneProgress")) {
		m_workDoneProgress = ValBool::mk(msg["workDoneProgress"]);
	}
}

WorkDoneProgressOptions::~WorkDoneProgressOptions() {
	// TODO Auto-generated destructor stub
}

void WorkDoneProgressOptions::dump(nlohmann::json &msg) {
	if (m_workDoneProgress) {
		msg["workDoneProgress"] = m_workDoneProgress->dump();
	}
}

nlohmann::json WorkDoneProgressOptions::dump() {
	nlohmann::json msg = nlohmann::json(
			nlohmann::json::value_type::object({}));
	if (m_workDoneProgress) {
		msg["workDoneProgress"] = m_workDoneProgress->dump();
	}

	return msg;
}

WorkDoneProgressOptionsSP WorkDoneProgressOptions::mk(ValBoolSP v) {
	return WorkDoneProgressOptionsSP(new WorkDoneProgressOptions(v));
}


} /* namespace lls */
