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
 * LangServer.h
 *
 *  Created on: Sep 21, 2020
 *      Author: ballance
 */

#pragma once
#include <map>
#include <functional>
#include <string>

#include "IClientConnection.h"
#include "ILangServer.h"
#include "IMessageTransport.h"
#include "IRegisterMethod.h"
#include "nlohmann/json_fwd.hpp"



namespace lls {

/**
 * Implements processing and handling of LSP messages
 */
class LangServerMethodHandler :
		public virtual IMessageTransport,
		public virtual IClientConnection {
public:
	LangServerMethodHandler(
			IMessageTransport 	*out,
			ILangServer			*srv);

	virtual ~LangServerMethodHandler();

	void register_methods(
			IRegisterMethod		*dispatcher);

	/**
	 * Accept in-bound messages
	 */
	virtual void send(const nlohmann::json &msg) override;

	virtual void publishDiagnostics(PublishDiagnosticsParamsSP params) override;

private:

	virtual void initialize(const nlohmann::json &msg);

	virtual void didChangeTextDocument(const nlohmann::json &msg);

	virtual void didOpenTextDocument(const nlohmann::json &msg);

	virtual void hoverRequest(const nlohmann::json &msg);

private:
	IMessageTransport							*m_out;
	ILangServer									*m_srv;
};

}

