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
 * RequestMessage.cpp
 *
 *  Created on: Sep 29, 2020
 *      Author: ballance
 */

#include "RequestMessage.h"
#include "nlohmann/json.hpp"

namespace lls {

RequestMessage::RequestMessage(const nlohmann::json &msg) : Message(msg) {
	if (msg.contains("id")) {
		m_id = ValInt::mk(msg["id"]);
	}
	m_method = ValStr::mk(msg["method"]);
}

RequestMessage::RequestMessage(ValIntSP id, ValStrSP method) {
	m_id = id;
	m_method = method;
}

RequestMessage::~RequestMessage() {
	// TODO Auto-generated destructor stub
}

void RequestMessage::load(const nlohmann::json &msg) {
	Message::load(msg);
	m_id = ValInt::mk(msg["id"]);
	m_method = ValStr::mk(msg["method"]);
}

void RequestMessage::dump(nlohmann::json &msg) {
	Message::dump(msg);
	msg["id"] = m_id->dump();
	msg["method"] = m_method->dump();
	msg["params"] = (m_params)?m_params->dump():nlohmann::json(nullptr);
}

nlohmann::json RequestMessage::dump() {
	nlohmann::json msg;
	dump(msg);
	return msg;
}


} /* namespace lls */
