/*
 * DidChangeTextDocumentParams.cpp
 *
 *  Created on: Oct 5, 2020
 *      Author: ballance
 */

#include "DidChangeTextDocumentParams.h"
#include "nlohmann/json.hpp"

namespace lls {

DidChangeTextDocumentParams::DidChangeTextDocumentParams(const nlohmann::json &msg) {
	m_textDocument = VersionedTextDocumentIdentifier::mk(msg["textDocument"]);
	m_contentChanges = ValVector<TextDocumentContentChangeEvent>::mk(msg["contentChanges"]);

}

DidChangeTextDocumentParams::~DidChangeTextDocumentParams() {
	// TODO Auto-generated destructor stub
}

DidChangeTextDocumentParamsSP DidChangeTextDocumentParams::mk(
		const nlohmann::json &msg) {
	return DidChangeTextDocumentParamsSP(new DidChangeTextDocumentParams(msg));
}

} /* namespace lls */
