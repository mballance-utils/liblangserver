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
 * ValInt.cpp
 *
 *  Created on: Oct 1, 2020
 *      Author: ballance
 */

#include "ValInt.h"
#include "nlohmann/json.hpp"

namespace lls {

ValInt::ValInt(int64_t v) : m_val(v){

}

ValInt::ValInt(const nlohmann::json &msg) {
	if (msg.is_number()) {
		m_val = msg;
	} else if (msg.is_string()) {
		m_val =std::stoi(msg.get<std::string>());
	} else {
		// ERROR
		m_val = -1;
	}
}

ValInt::~ValInt() {
	// TODO Auto-generated destructor stub
}

nlohmann::json ValInt::dump() {
	return nlohmann::json(m_val);
}

ValIntSP ValInt::mk(const nlohmann::json &msg) {
	if (msg.is_number()) {
		return ValIntSP(new ValInt(msg));
	} else if (msg.is_string()) {
		return ValIntSP(new ValInt(std::stoi(msg.get<std::string>())));
	} else {
		// ERROR
		return ValIntSP(new ValInt(-1));
	}
}

ValIntSP ValInt::mk(int32_t v) {
	return ValIntSP(new ValInt(v));
}

} /* namespace lls */
