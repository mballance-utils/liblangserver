/*
 * TextDocumentIdentifier.cpp
 *
 *  Created on: Oct 5, 2020
 *      Author: ballance
 */

#include "TextDocumentIdentifier.h"
#include "nlohmann/json.hpp"

namespace lls {

TextDocumentIdentifier::TextDocumentIdentifier(const nlohmann::json &msg) {
	m_uri = ValStr::mk(msg["uri"]);

}

TextDocumentIdentifier::~TextDocumentIdentifier() {
	// TODO Auto-generated destructor stub
}

TextDocumentIdentifierSP TextDocumentIdentifier::mk(const nlohmann::json &msg) {
	return TextDocumentIdentifierSP(new TextDocumentIdentifier(msg));
}

} /* namespace lls */
