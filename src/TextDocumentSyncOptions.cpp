/*
 * TextDocumentSyncOptions.cpp
 *
 *  Created on: Oct 3, 2020
 *      Author: ballance
 */

#include "TextDocumentSyncOptions.h"
#include "nlohmann/json.hpp"

namespace lls {

TextDocumentSyncOptions::TextDocumentSyncOptions(
			ValBoolSP				openClose,
			TextDocumentSyncKindSP	change) :
				m_openClose(openClose), m_change(change) {

}

TextDocumentSyncOptions::TextDocumentSyncOptions(
		const nlohmann::json &msg) {
	if (msg.contains("openClose")) {
		m_openClose = ValBool::mk(msg["openClose"]);
	}
	if (msg.contains("change")) {
		m_change = TextDocumentSyncKind::mk(msg);
	}
}

TextDocumentSyncOptions::~TextDocumentSyncOptions() {
	// TODO Auto-generated destructor stub
}

nlohmann::json TextDocumentSyncOptions::dump() {
	nlohmann::json msg;
	if (m_openClose) {
		msg["openClose"] = m_openClose->dump();
	}
	if (m_change) {
		msg["change"] = m_change->dump();
	}

	return msg;
}

TextDocumentSyncOptionsSP TextDocumentSyncOptions::mk(
			ValBoolSP				openClose,
			TextDocumentSyncKindSP	change) {
	return TextDocumentSyncOptionsSP(new TextDocumentSyncOptions(
			openClose, change));
}

} /* namespace lls */
