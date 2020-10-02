/*
 * ClientInfo.cpp
 *
 *  Created on: Sep 30, 2020
 *      Author: ballance
 */

#include "ClientInfo.h"
#include "nlohmann/json.hpp"

namespace lls {

ClientInfo::ClientInfo(const nlohmann::json &msg) {
	if (msg.contains("version")) {
		m_version = ValStr::mk(msg["version"]);
	}
	// TODO Auto-generated constructor stub

}

ClientInfo::~ClientInfo() {
	// TODO Auto-generated destructor stub
}

ClientInfoSP ClientInfo::mk(const nlohmann::json &msg) {
	return ClientInfoSP(new ClientInfo(msg));
}

} /* namespace lls */
