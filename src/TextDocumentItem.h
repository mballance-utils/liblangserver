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
 * TextDocumentItem.h
 *
 *  Created on: Oct 5, 2020
 *      Author: ballance
 */

#pragma once
#include "Val.h"
#include "ValInt.h"
#include "ValStr.h"

namespace lls {

class TextDocumentItem;
typedef std::shared_ptr<TextDocumentItem> TextDocumentItemSP;
class TextDocumentItem : public Val {
public:
	TextDocumentItem(const nlohmann::json &msg);

	virtual ~TextDocumentItem();

	ValStrSP uri() const { return m_uri; }

	void uri(ValStrSP v) { m_uri = v; }

	ValStrSP languageId() const { return m_languageId; }

	void languageId(ValStrSP v) { m_languageId = v; }

	ValIntSP version() const { return m_version; }

	void version(ValIntSP v) { m_version = v; }

	ValStrSP text() const { return m_text; }

	void text(ValStrSP v) { m_text = v; }

	static TextDocumentItemSP mk(const nlohmann::json &msg);


private:
	ValStrSP			m_uri;

	ValStrSP			m_languageId;

	ValIntSP			m_version;

	ValStrSP			m_text;

};

} /* namespace lls */

