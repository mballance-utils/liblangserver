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
 * WorkspaceFolder.h
 *
 *  Created on: Oct 1, 2020
 *      Author: ballance
 */

#pragma once
#include "Val.h"
#include "ValStr.h"

namespace lls {

class WorkspaceFolder;
typedef std::shared_ptr<WorkspaceFolder> WorkspaceFolderSP;

class WorkspaceFolder : public Val {
public:
	WorkspaceFolder(const nlohmann::json &msg);

	virtual ~WorkspaceFolder();

	ValStrSP uri() const { return m_uri; }

	ValStrSP name() const { return m_name; }

	virtual nlohmann::json dump();

	static WorkspaceFolderSP mk(const nlohmann::json &msg);

private:

	ValStrSP			m_uri;
	ValStrSP			m_name;

};

} /* namespace lls */

