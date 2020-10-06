/*
 * Diagnostic.cpp
 *
 *  Created on: Oct 5, 2020
 *      Author: ballance
 */

#include "Diagnostic.h"
#include "nlohmann/json.hpp"

namespace lls {

Diagnostic::Diagnostic(
		RangeSP				range,
		ValStrSP			message) : m_range(range), m_message(message) {
	// TODO Auto-generated constructor stub

}

Diagnostic::~Diagnostic() {
	// TODO Auto-generated destructor stub
}

nlohmann::json Diagnostic::dump() {
	nlohmann::json msg;

	msg["range"] = m_range->dump();
	if (m_severity) {
		msg["severity"] = m_severity->dump();
	}
	if (m_code) {
		msg["code"] = m_code->dump();
	}
	if (m_source) {
		msg["source"] = m_source->dump();
	}
	msg["message"] = m_message->dump();

	return msg;
}

}
