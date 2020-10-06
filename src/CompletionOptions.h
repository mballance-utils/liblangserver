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
 * CompletionOptions.h
 *
 *  Created on: Oct 4, 2020
 *      Author: ballance
 */

#pragma once
#include "WorkDoneProgressOptions.h"
#include "ValBool.h"
#include "ValStr.h"
#include "ValVector.h"

namespace lls {

class CompletionOptions;
typedef std::shared_ptr<CompletionOptions> CompletionOptionsSP;
class CompletionOptions : public WorkDoneProgressOptions {
public:
	CompletionOptions();

	virtual ~CompletionOptions();

	ValVector<ValStr>::SP triggerCharacters() const {
		return m_triggerCharacters;
	}

	void triggerCharacters(ValVector<ValStr>::SP v) {
		m_triggerCharacters = v;
	}

	ValVector<ValStr>::SP allCommitCharacters() const {
		return m_allCommitCharacters;
	}

	void allCommitCharacters(ValVector<ValStr>::SP v) {
		m_allCommitCharacters = v;
	}

	ValBoolSP resolveProvider() const {
		return m_resolveProvider;
	}

	void resolveProvider(ValBoolSP v) {
		m_resolveProvider = v;
	}

	virtual nlohmann::json dump();

	static CompletionOptionsSP mk();

private:
	ValVector<ValStr>::SP		m_triggerCharacters;
	ValVector<ValStr>::SP		m_allCommitCharacters;
	ValBoolSP					m_resolveProvider;

};

} /* namespace lls */

