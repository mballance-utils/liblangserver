/*
 * VersionedTextDocumentIdentifier.cpp
 *
 *  Created on: Oct 5, 2020
 *      Author: ballance
 */

#include "VersionedTextDocumentIdentifier.h"
#include "nlohmann/json.hpp"

namespace lls {

VersionedTextDocumentIdentifier::VersionedTextDocumentIdentifier(
		const nlohmann::json &msg) : TextDocumentIdentifier(msg) {
	if (msg.contains("version")) {
		m_version = ValInt::mk(msg["version"]);
	}
}

VersionedTextDocumentIdentifier::~VersionedTextDocumentIdentifier() {
	// TODO Auto-generated destructor stub
}

VersionedTextDocumentIdentifierSP VersionedTextDocumentIdentifier::mk(
		const nlohmann::json &msg) {
	return VersionedTextDocumentIdentifierSP(
			new VersionedTextDocumentIdentifier(msg));
}

} /* namespace lls */
