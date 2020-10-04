/*
 * TextDocumentSyncKind.cpp
 *
 *  Created on: Oct 3, 2020
 *      Author: ballance
 */

#include "TextDocumentSyncKind.h"
#include "nlohmann/json.hpp"

namespace lls {

TextDocumentSyncKind::TextDocumentSyncKind(int64_t v) : ValInt(v) {

}

TextDocumentSyncKind::TextDocumentSyncKind(const nlohmann::json &msg) : ValInt(msg) {

}

TextDocumentSyncKind::~TextDocumentSyncKind() {
	// TODO Auto-generated destructor stub
}

TextDocumentSyncKindSP TextDocumentSyncKind::mk(const nlohmann::json &msg) {
	return TextDocumentSyncKindSP(new TextDocumentSyncKind(msg));
}

const TextDocumentSyncKindSP	TextDocumentSyncKind::None =
		TextDocumentSyncKindSP(new TextDocumentSyncKind(0));
const TextDocumentSyncKindSP	TextDocumentSyncKind::Full =
		TextDocumentSyncKindSP(new TextDocumentSyncKind(1));
const TextDocumentSyncKindSP	TextDocumentSyncKind::Incremental =
		TextDocumentSyncKindSP(new TextDocumentSyncKind(2));

} /* namespace lls */
