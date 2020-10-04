/*
 * ServerCapabilities.cpp
 *
 *  Created on: Oct 1, 2020
 *      Author: ballance
 */

#include "ServerCapabilities.h"
#include "nlohmann/json.hpp"

namespace lls {

ServerCapabilities::ServerCapabilities() {
	// TODO Auto-generated constructor stub

}

ServerCapabilities::~ServerCapabilities() {
	// TODO Auto-generated destructor stub
}

nlohmann::json ServerCapabilities::dump() {
	nlohmann::json ret;

	if (m_textDocumentSync) {
		ret["textDocumentSync"] = m_textDocumentSync->dump();
	}
	if (m_completionProvider) {
		ret["completionProvider"] = m_completionProvider->dump();
	}

	return ret;
}

ServerCapabilitiesSP ServerCapabilities::mk() {
	return ServerCapabilitiesSP(new ServerCapabilities());
}

} /* namespace lls */
