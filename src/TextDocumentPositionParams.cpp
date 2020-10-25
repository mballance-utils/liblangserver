/*
 * TextDocumentPositionParams.cpp
 *
 *  Created on: Oct 25, 2020
 *      Author: ballance
 */

#include "TextDocumentPositionParams.h"
#include "nlohmann/json.hpp"

namespace lls {

TextDocumentPositionParams::TextDocumentPositionParams(
		const nlohmann::json &msg) {
	// TODO Auto-generated constructor stub
	m_textDocument = TextDocumentIdentifier::mk(msg["textDocument"]);
	m_position = Position::mk(msg["position"]);
}

TextDocumentPositionParams::~TextDocumentPositionParams() {
	// TODO Auto-generated destructor stub
}

TextDocumentPositionParamsSP TextDocumentPositionParams::mk(const nlohmann::json &msg) {
	return TextDocumentPositionParamsSP(new TextDocumentPositionParams(msg));
}

} /* namespace lls */
