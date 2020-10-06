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
 * ServerCapabilities.h
 *
 *  Created on: Oct 1, 2020
 *      Author: ballance
 */

#pragma once
#include "Val.h"
#include "CompletionOptions.h"
#include "TextDocumentSyncOptions.h"

namespace lls {

class ServerCapabilities;
typedef std::shared_ptr<ServerCapabilities> ServerCapabilitiesSP;
class ServerCapabilities : public Val {
public:
	ServerCapabilities();

	virtual ~ServerCapabilities();

	virtual nlohmann::json dump() override;

	TextDocumentSyncOptionsSP textDocumentSync() const {
		return m_textDocumentSync;
	}

	void textDocumentSync(TextDocumentSyncOptionsSP o) {
		m_textDocumentSync = o;
	}

	CompletionOptionsSP completionProvider() const {
		return m_completionProvider;
	}

	void completionProvider(CompletionOptionsSP o) {
		m_completionProvider = o;
	}

	static ServerCapabilitiesSP mk();

private:
	TextDocumentSyncOptionsSP		m_textDocumentSync;
	CompletionOptionsSP				m_completionProvider;
	// HoverOptions
	// SignatureHelpOptions
	// DeclarationOptions|DeclarationRegistrationOptions
	// DefinitionOptions
	// TypeDefinitionOptions|TypeDefinitionRegistrationOptions
	//


};

} /* namespace lls */

