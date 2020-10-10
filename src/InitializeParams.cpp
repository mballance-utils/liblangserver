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
 * InitializeParams.cpp
 *
 *  Created on: Sep 30, 2020
 *      Author: ballance
 */

#include "nlohmann/json.hpp"
#include "InitializeParams.h"

namespace lls {

InitializeParams::InitializeParams() {
}

InitializeParams::InitializeParams(const nlohmann::json &msg) :
	WorkDoneProgressParams(msg) {

	if (msg.contains("processId") && !msg["processId"].is_null()) {
		m_processId = ValInt::mk(msg["processId"]);
	}
	if (msg.contains("clientInfo")) {
		m_clientInfo = ClientInfo::mk(msg["clientInfo"]);
	}

	if (msg.contains("rootPath") && !msg["rootPath"].is_null()) {
		m_rootPath = ValStr::mk(msg["rootPath"]);
	}

	if (msg.contains("rootUri") && !msg["rootUri"].is_null()) {
		m_rootUri = ValStr::mk(msg["rootUri"]);
	}

	if (msg.contains("initializeOptions")) {
		// TODO:
	}

	if (msg.contains("capabilities")) {
		// TODO:
	}

	if (msg.contains("trace")) {
		m_trace = ValStr::mk(msg["trace"]);
	}

	if (msg.contains("workspaceFolders") && !msg["workspaceFolders"].is_null()) {
		m_workspaceFolders = ValVector<WorkspaceFolder>::mk(msg["workspaceFolders"]);
	}

}

InitializeParams::~InitializeParams() {
	// TODO Auto-generated destructor stub
}

nlohmann::json InitializeParams::dump() {
	nlohmann::json msg;
	WorkDoneProgressParams::dump(msg);

	msg["processId"] = (m_processId)?m_processId->dump():nlohmann::json(nullptr);

	if (m_clientInfo) {
		msg["clientInfo"] = m_clientInfo->dump();
	}
	if (m_rootPath) {
		msg["rootPath"] = m_rootPath->dump();
	}
	if (m_rootUri) {
		msg["rootUri"] = m_rootUri->dump();
	}

	return msg;
}

InitializeParamsSP InitializeParams::mk(const nlohmann::json &msg) {
	return InitializeParamsSP(new InitializeParams(msg));
}

} /* namespace lls */
