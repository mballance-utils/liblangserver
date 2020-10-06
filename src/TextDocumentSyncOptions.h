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
 * TextDocumentSyncOptions.h
 *
 *  Created on: Oct 3, 2020
 *      Author: ballance
 */

#pragma once
#include "Val.h"
#include "ValBool.h"
#include "TextDocumentSyncKind.h"

namespace lls {

class TextDocumentSyncOptions;
typedef std::shared_ptr<TextDocumentSyncOptions> TextDocumentSyncOptionsSP;
class TextDocumentSyncOptions : public Val {
public:
	TextDocumentSyncOptions(
			ValBoolSP				openClose,
			TextDocumentSyncKindSP	change);

	TextDocumentSyncOptions(const nlohmann::json &msg);

	virtual ~TextDocumentSyncOptions();

	ValBoolSP openClose() const { return m_openClose; }

	void openClose(ValBoolSP v) { m_openClose = v; }

	virtual nlohmann::json dump();

	static TextDocumentSyncOptionsSP mk(
			ValBoolSP				openClose,
			TextDocumentSyncKindSP	change);

private:
	ValBoolSP					m_openClose;
	TextDocumentSyncKindSP		m_change;
};

} /* namespace lls */

