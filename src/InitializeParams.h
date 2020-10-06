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
 * InitializeParams.h
 *
 *  Created on: Sep 30, 2020
 *      Author: ballance
 */

#pragma once
#include "ClientInfo.h"
#include "ValInt.h"
#include "ValStr.h"
#include "ValVector.h"
#include "WorkDoneProgressParams.h"
#include "WorkspaceFolder.h"

namespace lls {

class InitializeParams;
typedef std::shared_ptr<InitializeParams> InitializeParamsSP;

class InitializeParams : public WorkDoneProgressParams {
public:
	InitializeParams();

	InitializeParams(const nlohmann::json &msg);

	virtual ~InitializeParams();

	ClientInfoSP clientInfo() const { return m_clientInfo; }

	ValStrSP rootPath() const { return m_rootPath; }

	void rootPath(ValStrSP v) {  m_rootPath = v; }

	ValStrSP rootUri() const { return m_rootUri; }

	void rootUri(ValStrSP v) {  m_rootUri = v; }

	virtual nlohmann::json dump();

	static InitializeParamsSP mk(const nlohmann::json &msg);

private:
	ClientInfoSP					m_clientInfo;
	ValIntSP						m_processId;
	ValStrSP						m_rootPath;
	ValStrSP						m_rootUri;
	ValStrSP						m_trace;
	ValVector<WorkspaceFolder>::SP	m_workspaceFolders;


};

} /* namespace lls */

