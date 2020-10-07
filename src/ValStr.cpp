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
 * ValStr.cpp
 *
 *  Created on: Sep 30, 2020
 *      Author: ballance
 */

#include "ValStr.h"
#include "nlohmann/json.hpp"

namespace lls {

ValStr::ValStr(const nlohmann::json &msg) {
	m_val = msg.get<std::string>();
}

ValStr::ValStr(const std::string &v) : m_val(v) {

}

ValStr::~ValStr() {
	// TODO Auto-generated destructor stub
}

nlohmann::json ValStr::dump() {
	return nlohmann::json(m_val);
}

ValStrSP ValStr::mk(const nlohmann::json &msg) {
	return ValStrSP(new ValStr(msg));
}

ValStrSP ValStr::mk(const std::string &v) {
	return ValStrSP(new ValStr(v));
}

ValStrSP ValStr::mk(const char *v) {
	return ValStrSP(new ValStr(std::string(v)));
}

} /* namespace lls */
