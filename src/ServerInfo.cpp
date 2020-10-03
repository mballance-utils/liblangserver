/*
 * ServerInfo.cpp
 *
 *  Created on: Oct 2, 2020
 *      Author: ballance
 */

#include "ServerInfo.h"
#include "nlohmann/json.hpp"

namespace lls {

ServerInfo::ServerInfo(ValStrSP name) : m_name(name) {
	// TODO Auto-generated constructor stub

}

ServerInfo::~ServerInfo() {
	// TODO Auto-generated destructor stub
}

nlohmann::json ServerInfo::dump() {
	nlohmann::json msg;
	msg["name"] = m_name->dump();
	if (m_version) {
		msg["version"] = m_version->dump();
	}

	return msg;
}

ServerInfoSP ServerInfo::mk(ValStrSP name) {
	return ServerInfoSP(new ServerInfo(name));
}

} /* namespace lls */
