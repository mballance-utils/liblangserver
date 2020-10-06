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
 * RequestMessage.h
 *
 *  Created on: Sep 29, 2020
 *      Author: ballance
 */

#pragma once
#include "Message.h"
#include "Val.h"
#include "ValInt.h"
#include "ValStr.h"

namespace lls {

class RequestMessage : public Message {
public:
	RequestMessage(const nlohmann::json &msg);

	RequestMessage(ValIntSP id, ValStrSP method);

	virtual ~RequestMessage();

	int64_t id() const { return m_id->val(); }

	void id(int64_t i) { m_id->val(i); }

	const std::string &method() const { return m_method->val(); }

	void method(const std::string &m) { m_method->val(m); }

	ValSP params() const { return m_params; }

	void params(ValSP p) { m_params = p; }

	virtual void load(const nlohmann::json &msg);

	virtual void dump(nlohmann::json &msg);

	virtual nlohmann::json dump();

protected:
	ValIntSP			m_id;
	ValStrSP			m_method;

	ValSP				m_params;

};

} /* namespace lls */

