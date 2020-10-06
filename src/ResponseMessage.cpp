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
 * ResponseMessage.cpp
 *
 *  Created on: Sep 29, 2020
 *      Author: ballance
 */

#include "ResponseMessage.h"
#include "nlohmann/json.hpp"

namespace lls {

ResponseMessage::ResponseMessage() {

}

ResponseMessage::ResponseMessage(ValIntSP id) : m_id(id) {

}

ResponseMessage::~ResponseMessage() {
	// TODO Auto-generated destructor stub
}

void ResponseMessage::load(const nlohmann::json &msg) {
	Message::load(msg);
	m_id = ValInt::mk(msg["id"]);
}

nlohmann::json ResponseMessage::dump() {
	nlohmann::json msg;

	Message::dump(msg);

	if (m_id) {
		msg["id"] = m_id->dump();
	}
	if (m_result) {
		msg["result"] = m_result->dump();
	}

	return msg;
}

ResponseMessageSP ResponseMessage::mk(ValIntSP id) {
	return ResponseMessageSP(new ResponseMessage(id));
}

} /* namespace lls */
