/*
 * MessageDispatcher.cpp
 *
 *  Created on: Oct 1, 2020
 *      Author: ballance
 */

#include "MessageDispatcher.h"
#include "nlohmann/json.hpp"

namespace lls {

MessageDispatcher::MessageDispatcher() {
	// TODO Auto-generated constructor stub

}

MessageDispatcher::~MessageDispatcher() {
	// TODO Auto-generated destructor stub
}

void MessageDispatcher::register_method(
		const std::string							&method,
		std::function<void(const nlohmann::json &)>	impl) {
	m_method_m.insert({method, impl});
}

void MessageDispatcher::send(const nlohmann::json &msg) {
	std::map<std::string,std::function<void(const nlohmann::json&)>>::iterator it;

	if ((it=m_method_m.find(msg["method"])) != m_method_m.end()) {
		fprintf(stdout, "==> calling method impl\n");
		fflush(stdout);
		it->second(msg);
		fprintf(stdout, "<== calling method impl\n");
		fflush(stdout);
	} else {
		// Send back a response (?)
	}
}

} /* namespace lls */
