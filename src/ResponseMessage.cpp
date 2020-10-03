/*
 * ResponseMessage.cpp
 *
 *  Created on: Sep 29, 2020
 *      Author: ballance
 */

#include "ResponseMessage.h"
#include "nlohmann/json.hpp"

namespace lls {

ResponseMessage::ResponseMessage() {

}

ResponseMessage::ResponseMessage(ValIntSP id) : m_id(id) {

}

ResponseMessage::~ResponseMessage() {
	// TODO Auto-generated destructor stub
}

void ResponseMessage::load(const nlohmann::json &msg) {
	Message::load(msg);
	m_id = ValInt::mk(msg["id"]);
}

nlohmann::json ResponseMessage::dump() {
	nlohmann::json msg;

	Message::dump(msg);

	if (m_id) {
		msg["id"] = m_id->dump();
	}
	if (m_result) {
		msg["result"] = m_result->dump();
	}

	return msg;
}

ResponseMessageSP ResponseMessage::mk(ValIntSP id) {
	return ResponseMessageSP(new ResponseMessage(id));
}

} /* namespace lls */
