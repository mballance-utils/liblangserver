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
 * Message.cpp
 *
 *  Created on: Sep 29, 2020
 *      Author: ballance
 */

#include "Message.h"
#include "nlohmann/json.hpp"

namespace lls {

Message::Message(const nlohmann::json &msg) {
	;
}

Message::Message() : m_jsonrpc("2.0") {
	// TODO Auto-generated constructor stub

}

Message::~Message() {
	// TODO Auto-generated destructor stub
}

void Message::load(const nlohmann::json &msg) {
	m_jsonrpc = msg["jsonrpc"];
}

void Message::dump(nlohmann::json &msg) {
	msg["jsonrpc"] = m_jsonrpc;
}

int32_t Message::get_int(const nlohmann::json &msg, const std::string &key) {
	int32_t ret = 0;
	if (msg["id"].type() == nlohmann::json::value_t::number_integer) {
		ret = msg["id"];
	} else {
		ret = std::stoi(msg["id"].get<std::string>());
	}
	return ret;
}

} /* namespace lls */
