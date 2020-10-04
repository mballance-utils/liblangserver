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

