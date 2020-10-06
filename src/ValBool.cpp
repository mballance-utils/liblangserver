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
 * ValBool.cpp
 *
 *  Created on: Oct 3, 2020
 *      Author: ballance
 */

#include "ValBool.h"
#include "nlohmann/json.hpp"

namespace lls {

ValBool::ValBool(bool v) : m_val(v) {

}

ValBool::ValBool(const nlohmann::json &msg) {
	m_val = msg.get<bool>();
}

ValBool::~ValBool() {
	// TODO Auto-generated destructor stub
}

nlohmann::json ValBool::dump() {
	return nlohmann::json(m_val);
}

ValBoolSP ValBool::mk(bool v) {
	return ValBoolSP(new ValBool(v));
}

ValBoolSP ValBool::mk(const nlohmann::json &msg) {
	return ValBoolSP(new ValBool(msg));
}

const ValBoolSP	ValBool::true_v(new ValBool(true));
const ValBoolSP	ValBool::false_v(new ValBool(false));

} /* namespace lls */
