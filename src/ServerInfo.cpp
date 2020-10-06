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
 * ServerInfo.cpp
 *
 *  Created on: Oct 2, 2020
 *      Author: ballance
 */

#include "ServerInfo.h"
#include "nlohmann/json.hpp"

namespace lls {

ServerInfo::ServerInfo(ValStrSP name) : m_name(name) {
	// TODO Auto-generated constructor stub

}

ServerInfo::~ServerInfo() {
	// TODO Auto-generated destructor stub
}

nlohmann::json ServerInfo::dump() {
	nlohmann::json msg;
	msg["name"] = m_name->dump();
	if (m_version) {
		msg["version"] = m_version->dump();
	}

	return msg;
}

ServerInfoSP ServerInfo::mk(ValStrSP name) {
	return ServerInfoSP(new ServerInfo(name));
}

} /* namespace lls */
