/*
 * InitializeResult.cpp
 *
 *  Created on: Oct 1, 2020
 *      Author: ballance
 */

#include "InitializeResult.h"

namespace lls {

InitializeResult::InitializeResult(ServerCapabilitiesSP capabilities) :
	m_capabilities(capabilities) {
	// TODO Auto-generated constructor stub

}

InitializeResult::~InitializeResult() {
	// TODO Auto-generated destructor stub
}

nlohmann::json InitializeResult::dump() {
	nlohmann::json msg;
	msg["capabilities"] = m_capabilities->dump();
	if (m_info) {
		msg["serverInfo"] = m_info->dump();
	}

	return msg;
}

InitializeResultSP InitializeResult::mk(ServerCapabilitiesSP capabilities) {
	return InitializeResultSP(new InitializeResult(capabilities));
}

} /* namespace lls */
