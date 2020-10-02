/*
 * LangServer.cpp
 *
 *  Created on: Sep 21, 2020
 *      Author: ballance
 */

#include "LangServerMethodHandler.h"

#include "InitializeParams.h"
#include "nlohmann/json.hpp"

namespace lls {

LangServerMethodHandler::LangServerMethodHandler(
		IMessageTransport 	*out,
		ILangServer			*srv) : m_out(out), m_srv(srv) {

}

LangServerMethodHandler::~LangServerMethodHandler() {
	// TODO Auto-generated destructor stub
}

void LangServerMethodHandler::register_methods(IRegisterMethod *dispatcher) {
	dispatcher->register_method("initialize",
			std::bind(&LangServerMethodHandler::initialize,this,std::placeholders::_1));
}

void LangServerMethodHandler::send(const nlohmann::json &msg) {
	// Receive a message
}

void LangServerMethodHandler::initialize(const nlohmann::json &msg) {
	for (nlohmann::json::const_iterator it = msg.begin();
			it!=msg.end(); it++) {
		fprintf(stdout, "key: %s\n", it.key().c_str());
	}
	InitializeParamsSP params(InitializeParams::mk(msg["params"]));

	ServerCapabilitiesSP capabilities = m_srv->initialize(params);
}

}
