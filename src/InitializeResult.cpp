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
 * InitializeResult.cpp
 *
 *  Created on: Oct 1, 2020
 *      Author: ballance
 */

#include "InitializeResult.h"

namespace lls {

InitializeResult::InitializeResult(ServerCapabilitiesSP capabilities) :
	m_capabilities(capabilities) {
	// TODO Auto-generated constructor stub

}

InitializeResult::~InitializeResult() {
	// TODO Auto-generated destructor stub
}

nlohmann::json InitializeResult::dump() {
	nlohmann::json msg;
	msg["capabilities"] = m_capabilities->dump();
	if (m_info) {
		msg["serverInfo"] = m_info->dump();
	}

	return msg;
}

InitializeResultSP InitializeResult::mk(ServerCapabilitiesSP capabilities) {
	return InitializeResultSP(new InitializeResult(capabilities));
}

} /* namespace lls */
