/*
 * ServerCapabilities.h
 *
 *  Created on: Oct 1, 2020
 *      Author: ballance
 */

#pragma once
#include "Val.h"

namespace lls {

class ServerCapabilities : public Val {
public:
	ServerCapabilities();

	virtual ~ServerCapabilities();

	virtual nlohmann::json dump() override;

private:
	// TextDocumentSyncOptions
	// CompletionOptions
	// HoverOptions
	// SignatureHelpOptions
	// DeclarationOptions|DeclarationRegistrationOptions
	// DefinitionOptions
	// TypeDefinitionOptions|TypeDefinitionRegistrationOptions
	//


};

} /* namespace lls */

