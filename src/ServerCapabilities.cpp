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
 * ServerCapabilities.cpp
 *
 *  Created on: Oct 1, 2020
 *      Author: ballance
 */

#include "ServerCapabilities.h"
#include "nlohmann/json.hpp"

namespace lls {

ServerCapabilities::ServerCapabilities() {
	// TODO Auto-generated constructor stub

}

ServerCapabilities::~ServerCapabilities() {
	// TODO Auto-generated destructor stub
}

nlohmann::json ServerCapabilities::dump() {
	nlohmann::json ret;

	if (m_textDocumentSync) {
		ret["textDocumentSync"] = m_textDocumentSync->dump();
	}
	if (m_completionProvider) {
		ret["completionProvider"] = m_completionProvider->dump();
	}

	return ret;
}

ServerCapabilitiesSP ServerCapabilities::mk() {
	return ServerCapabilitiesSP(new ServerCapabilities());
}

} /* namespace lls */
