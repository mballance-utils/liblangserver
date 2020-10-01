/*
 * InitializeParams.cpp
 *
 *  Created on: Sep 30, 2020
 *      Author: ballance
 */

#include "nlohmann/json.hpp"
#include "InitializeParams.h"

namespace lls {

InitializeParams::InitializeParams(const nlohmann::json &msg) :
	WorkDoneProgressParams(msg) {

	if (msg.contains("clientInfo")) {
		m_clientInfo = ClientInfo::mk(msg["clientInfo"]);
	}

	if (msg.contains("rootPath") && !msg["rootPath"].is_null()) {
		m_rootPath = ValStr::mk(msg["rootPath"]);
	}

	if (msg.contains("rootUri") && !msg["rootUri"].is_null()) {
		m_rootPath = ValStr::mk(msg["rootUri"]);
	}

	if (msg.contains("initializeOptions")) {
		// TODO:
	}

	if (msg.contains("capabilities")) {
		// TODO:
	}

	if (msg.contains("trace")) {
		m_trace = ValStr::mk(msg["trace"]);
	}

	if (msg.contains("workspaceFolders") && !msg["workspaceFolders"].is_null()) {
		m_workspaceFolders = ValVector<WorkspaceFolder>::mk(msg["workspaceFolders"]);
//ValVector<WorkspaceFolder>::mk(msg["workspaceFolders"]);
	}

}

InitializeParams::~InitializeParams() {
	// TODO Auto-generated destructor stub
}

} /* namespace lls */
