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
 * MessageDispatcher.cpp
 *
 *  Created on: Oct 1, 2020
 *      Author: ballance
 */

#include "MessageDispatcher.h"
#include "nlohmann/json.hpp"

namespace lls {

MessageDispatcher::MessageDispatcher() {
	// TODO Auto-generated constructor stub

}

MessageDispatcher::~MessageDispatcher() {
	// TODO Auto-generated destructor stub
}

void MessageDispatcher::register_method(
		const std::string							&method,
		std::function<void(const nlohmann::json &)>	impl) {
	m_method_m.insert({method, impl});
}

void MessageDispatcher::send(const nlohmann::json &msg) {
	std::map<std::string,std::function<void(const nlohmann::json&)>>::iterator it;

	if ((it=m_method_m.find(msg["method"])) != m_method_m.end()) {
		fprintf(stdout, "==> calling method impl\n");
		fflush(stdout);
		it->second(msg);
		fprintf(stdout, "<== calling method impl\n");
		fflush(stdout);
	} else {
		// Send back a response (?)
	}
}

} /* namespace lls */
