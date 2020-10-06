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
 * InitializeResult.h
 *
 *  Created on: Oct 1, 2020
 *      Author: ballance
 */

#pragma once
#include "Val.h"
#include "ServerCapabilities.h"
#include "ServerInfo.h"
#include "nlohmann/json.hpp"

namespace lls {

class InitializeResult;
typedef std::shared_ptr<InitializeResult> InitializeResultSP;
class InitializeResult : public Val {
public:
	InitializeResult(ServerCapabilitiesSP capabilities);

	virtual ~InitializeResult();

	ServerCapabilitiesSP capabilities() const {
		return m_capabilities;
	}

	void capabilities(ServerCapabilitiesSP c) {
		m_capabilities = c;
	}

	ServerInfoSP info() const {
		return m_info;
	}

	void info(ServerInfoSP i) {
		m_info = i;
	}

	virtual nlohmann::json dump();

	static InitializeResultSP mk(ServerCapabilitiesSP capabilities);

private:
	ServerCapabilitiesSP		m_capabilities;
	ServerInfoSP				m_info;

};

} /* namespace lls */

