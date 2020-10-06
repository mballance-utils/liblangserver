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
 * ValBool.h
 *
 *  Created on: Oct 3, 2020
 *      Author: ballance
 */

#pragma once
#include "Val.h"

namespace lls {

class ValBool;
typedef std::shared_ptr<ValBool> ValBoolSP;
class ValBool : public Val {
public:
	ValBool(bool v=false);

	ValBool(const nlohmann::json &msg);

	virtual ~ValBool();

	virtual nlohmann::json dump();

	static ValBoolSP mk(bool v=false);

	static ValBoolSP mk(const nlohmann::json &msg);

public:
	static const ValBoolSP	true_v;
	static const ValBoolSP	false_v;

private:
	bool			m_val;
};

} /* namespace lls */

