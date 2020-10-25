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
 * CompletionOptions.cpp
 *
 *  Created on: Oct 4, 2020
 *      Author: ballance
 */

#include "CompletionOptions.h"
#include "ValBool.h"
#include "nlohmann/json.hpp"

namespace lls {

CompletionOptions::CompletionOptions() : WorkDoneProgressOptions(ValBool::mk(false)) {
	// TODO Auto-generated constructor stub

}

CompletionOptions::~CompletionOptions() {
	// TODO Auto-generated destructor stub
}

nlohmann::json CompletionOptions::dump() {
	nlohmann::json msg;

	WorkDoneProgressOptions::dump(msg);
	if (m_triggerCharacters) {
		msg["triggerCharacters"] = m_triggerCharacters->dump();
	}
	if (m_allCommitCharacters) {
		msg["allCommitCharacters"] = m_allCommitCharacters->dump();
	}
	if (m_resolveProvider) {
		msg["resolveProvider"] = m_resolveProvider->dump();
	}

	return msg;
}

CompletionOptionsSP CompletionOptions::mk() {
	return CompletionOptionsSP(new CompletionOptions());
}

} /* namespace lls */
