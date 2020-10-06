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
 * WorkDoneProgressParams.cpp
 *
 *  Created on: Sep 30, 2020
 *      Author: ballance
 */

#include "WorkDoneProgressParams.h"
#include "nlohmann/json.hpp"

namespace lls {


WorkDoneProgressParams::WorkDoneProgressParams() {

}

WorkDoneProgressParams::WorkDoneProgressParams(const nlohmann::json &msg) {
	if (msg.contains("workDoneToken")) {
		m_workDoneToken = ProgressToken::mk(msg["workDoneToken"]);
	}

}

WorkDoneProgressParams::~WorkDoneProgressParams() {
	// TODO Auto-generated destructor stub
}

void WorkDoneProgressParams::dump(nlohmann::json &msg) {
	// TODO:
}

} /* namespace lls */
