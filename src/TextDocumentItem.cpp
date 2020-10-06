/*
 * TextDocumentItem.cpp
 *
 *  Created on: Oct 5, 2020
 *      Author: ballance
 */

#include "TextDocumentItem.h"
#include "nlohmann/json.hpp"

namespace lls {

TextDocumentItem::TextDocumentItem(const nlohmann::json &msg) {
	m_uri = ValStr::mk(msg["uri"]);
	m_languageId = ValStr::mk(msg["languageId"]);
	m_version = ValInt::mk(msg["version"]);
	m_text = ValStr::mk(msg["text"]);
}

TextDocumentItem::~TextDocumentItem() {
	// TODO Auto-generated destructor stub
}

TextDocumentItemSP TextDocumentItem::mk(const nlohmann::json &msg) {
	return TextDocumentItemSP(new TextDocumentItem(msg));
}

} /* namespace lls */
