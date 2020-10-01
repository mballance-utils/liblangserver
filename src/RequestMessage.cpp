/*
 * RequestMessage.cpp
 *
 *  Created on: Sep 29, 2020
 *      Author: ballance
 */

#include "RequestMessage.h"
#include "nlohmann/json.hpp"

namespace lls {

RequestMessage::RequestMessage() {
	// TODO Auto-generated constructor stub

}

RequestMessage::~RequestMessage() {
	// TODO Auto-generated destructor stub
}

void RequestMessage::load(const nlohmann::json &msg) {
	Message::load(msg);
	m_id = get_int(msg, "id");
	m_method = msg["method"];
}

void RequestMessage::dump(nlohmann::json &msg) {
	Message::dump(msg);
	msg["id"] = m_id;
	msg["method"] = m_method;
}

} /* namespace lls */
