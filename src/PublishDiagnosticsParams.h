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
 * PublishDiagnosticsParams.h
 *
 *  Created on: Oct 5, 2020
 *      Author: ballance
 */

#pragma once
#include "Diagnostic.h"
#include "Val.h"
#include "ValStr.h"
#include "ValVector.h"

namespace lls {

class PublishDiagnosticsParams;
typedef std::shared_ptr<PublishDiagnosticsParams> PublishDiagnosticsParamsSP;
class PublishDiagnosticsParams : public Val {
public:
	PublishDiagnosticsParams(
			ValStrSP 					uri,
			ValVector<Diagnostic>::SP 	diagnostics);

	virtual ~PublishDiagnosticsParams();

	ValStrSP uri() const { return m_uri; }

	const ValVector<Diagnostic>::SP diagnostics() const {
		return m_diagnostics;
	}

	virtual nlohmann::json dump();

	static PublishDiagnosticsParamsSP mk(
			ValStrSP 					uri,
			ValVector<Diagnostic>::SP 	diagnostics);

private:
	ValStrSP					m_uri;
	ValVector<Diagnostic>::SP	m_diagnostics;


};

} /* namespace lls */

