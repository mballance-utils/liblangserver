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
 * DidChangeTextDocumentParams.h
 *
 *  Created on: Oct 5, 2020
 *      Author: ballance
 */

#pragma once
#include "Val.h"
#include "VersionedTextDocumentIdentifier.h"
#include "TextDocumentContentChangeEvent.h"
#include "ValVector.h"

namespace lls {

class DidChangeTextDocumentParams;
typedef std::shared_ptr<DidChangeTextDocumentParams> DidChangeTextDocumentParamsSP;
class DidChangeTextDocumentParams : public Val {
public:
	DidChangeTextDocumentParams(const nlohmann::json &msg);

	virtual ~DidChangeTextDocumentParams();

	VersionedTextDocumentIdentifierSP textDocument() const {
		return m_textDocument;
	}

	ValVector<TextDocumentContentChangeEvent>::SP contentChanges() const {
		return m_contentChanges;
	}

	static DidChangeTextDocumentParamsSP mk(const nlohmann::json &msg);

private:
	VersionedTextDocumentIdentifierSP				m_textDocument;
	ValVector<TextDocumentContentChangeEvent>::SP	m_contentChanges;

};

} /* namespace lls */

