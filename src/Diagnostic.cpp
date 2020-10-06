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
 * Diagnostic.cpp
 *
 *  Created on: Oct 5, 2020
 *      Author: ballance
 */

#include "Diagnostic.h"
#include "nlohmann/json.hpp"

namespace lls {

Diagnostic::Diagnostic(
		RangeSP				range,
		ValStrSP			message) : m_range(range), m_message(message) {
	// TODO Auto-generated constructor stub

}

Diagnostic::~Diagnostic() {
	// TODO Auto-generated destructor stub
}

nlohmann::json Diagnostic::dump() {
	nlohmann::json msg;

	msg["range"] = m_range->dump();
	if (m_severity) {
		msg["severity"] = m_severity->dump();
	}
	if (m_code) {
		msg["code"] = m_code->dump();
	}
	if (m_source) {
		msg["source"] = m_source->dump();
	}
	msg["message"] = m_message->dump();

	return msg;
}

}
