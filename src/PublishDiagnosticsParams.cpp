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
 * PublishDiagnosticsParams.cpp
 *
 *  Created on: Oct 5, 2020
 *      Author: ballance
 */

#include "PublishDiagnosticsParams.h"
#include "nlohmann/json.hpp"

namespace lls {

PublishDiagnosticsParams::PublishDiagnosticsParams(
		ValStrSP					uri,
		ValVector<Diagnostic>::SP	diagnostics) :
				m_uri(uri), m_diagnostics(diagnostics) {

}

PublishDiagnosticsParams::~PublishDiagnosticsParams() {
	// TODO Auto-generated destructor stub
}

PublishDiagnosticsParamsSP PublishDiagnosticsParams::mk(
			ValStrSP 					uri,
			ValVector<Diagnostic>::SP 	diagnostics) {
	return PublishDiagnosticsParamsSP(
			new PublishDiagnosticsParams(uri, diagnostics));
}

nlohmann::json PublishDiagnosticsParams::dump() {
	nlohmann::json msg;

	msg["uri"] = m_uri->dump();
	msg["diagnostics"] = m_diagnostics->dump();

	return msg;
}

} /* namespace lls */
