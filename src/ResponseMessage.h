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
 * ResponseMessage.h
 *
 *  Created on: Sep 29, 2020
 *      Author: ballance
 */

#pragma once
#include "Message.h"
#include "Val.h"
#include "ValInt.h"

namespace lls {

class ResponseMessage;
typedef std::shared_ptr<ResponseMessage> ResponseMessageSP;
class ResponseMessage : public Message {
public:
	ResponseMessage();

	ResponseMessage(ValIntSP id);

	virtual ~ResponseMessage();

	ValSP result() const { return m_result; }

	void result(ValSP r) { m_result = r; }

	virtual void load(const nlohmann::json &msg);

	virtual nlohmann::json dump();

	static ResponseMessageSP mk(ValIntSP id);

protected:
	ValIntSP				m_id;
	ValSP					m_result;

};

} /* namespace lls */

