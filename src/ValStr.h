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
 * ValStr.h
 *
 *  Created on: Sep 30, 2020
 *      Author: ballance
 */

#pragma once
#include <string>
#include "Val.h"

namespace lls {

class ValStr;
typedef std::shared_ptr<ValStr> ValStrSP;
class ValStr : public Val {
public:
	ValStr(const std::string &v);

	ValStr(const nlohmann::json &msg);

	virtual ~ValStr();

	const std::string &val() const { return m_val; }

	void val(const std::string &v) { m_val = v; }

	virtual nlohmann::json dump() override;

	static ValStrSP mk(const nlohmann::json &msg);

	static ValStrSP mk(const std::string &v);

private:
	std::string				m_val;
};

} /* namespace lls */

