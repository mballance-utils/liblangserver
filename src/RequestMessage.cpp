/*
 * RequestMessage.cpp
 *
 *  Created on: Sep 29, 2020
 *      Author: ballance
 */

#include "RequestMessage.h"
#include "nlohmann/json.hpp"

namespace lls {

RequestMessage::RequestMessage(const nlohmann::json &msg) : Message(msg) {
	m_id = ValInt::mk(msg["id"]);
	m_method = ValStr::mk(msg["method"]);
}

RequestMessage::RequestMessage(int32_t id, const std::string &method) {
	m_id = ValInt::mk(id);
	m_method = ValStr::mk(method);
}

RequestMessage::~RequestMessage() {
	// TODO Auto-generated destructor stub
}

void RequestMessage::load(const nlohmann::json &msg) {
	Message::load(msg);
	m_id = ValInt::mk(msg["id"]);
	m_method = ValStr::mk(msg["method"]);
}

void RequestMessage::dump(nlohmann::json &msg) {
	Message::dump(msg);
	msg["id"] = m_id->dump();
	msg["method"] = m_method->dump();
	msg["params"] = (m_params)?m_params->dump():nlohmann::json(nullptr);
}

nlohmann::json RequestMessage::dump() {
	nlohmann::json msg;
	dump(msg);
	return msg;
}


} /* namespace lls */
