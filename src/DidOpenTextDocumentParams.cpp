/*
 * DidOpenTextDocumentParams.cpp
 *
 *  Created on: Oct 5, 2020
 *      Author: ballance
 */

#include "DidOpenTextDocumentParams.h"
#include "nlohmann/json.hpp"

namespace lls {

DidOpenTextDocumentParams::DidOpenTextDocumentParams(const nlohmann::json &msg) {
	m_textDocument = TextDocumentItem::mk(msg["textDocument"]);

}

DidOpenTextDocumentParams::~DidOpenTextDocumentParams() {
	// TODO Auto-generated destructor stub
}

DidOpenTextDocumentParamsSP DidOpenTextDocumentParams::mk(const nlohmann::json &msg) {
	return DidOpenTextDocumentParamsSP(new DidOpenTextDocumentParams(msg));
}

} /* namespace lls */
