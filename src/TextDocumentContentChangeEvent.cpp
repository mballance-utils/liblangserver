/*
 * TextDocumentContentChangeEvent.cpp
 *
 *  Created on: Oct 5, 2020
 *      Author: ballance
 */

#include "TextDocumentContentChangeEvent.h"
#include "nlohmann/json.hpp"

namespace lls {

TextDocumentContentChangeEvent::TextDocumentContentChangeEvent(
		const nlohmann::json &msg) {
	if (msg.contains("range")) {
		m_range = Range::mk(msg["range"]);
	}
	m_text = ValStr::mk(msg["text"]);

}

TextDocumentContentChangeEvent::~TextDocumentContentChangeEvent() {
	// TODO Auto-generated destructor stub
}

TextDocumentContentChangeEventSP TextDocumentContentChangeEvent::mk(
		const nlohmann::json &msg) {
	return TextDocumentContentChangeEventSP(
			new TextDocumentContentChangeEvent(msg));
}

} /* namespace lls */
