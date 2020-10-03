/*
 * InitializeResult.h
 *
 *  Created on: Oct 1, 2020
 *      Author: ballance
 */

#pragma once
#include "Val.h"
#include "ServerCapabilities.h"
#include "ServerInfo.h"
#include "nlohmann/json.hpp"

namespace lls {

class InitializeResult;
typedef std::shared_ptr<InitializeResult> InitializeResultSP;
class InitializeResult : public Val {
public:
	InitializeResult(ServerCapabilitiesSP capabilities);

	virtual ~InitializeResult();

	ServerCapabilitiesSP capabilities() const {
		return m_capabilities;
	}

	void capabilities(ServerCapabilitiesSP c) {
		m_capabilities = c;
	}

	ServerInfoSP info() const {
		return m_info;
	}

	void info(ServerInfoSP i) {
		m_info = i;
	}

	virtual nlohmann::json dump();

	static InitializeResultSP mk(ServerCapabilitiesSP capabilities);

private:
	ServerCapabilitiesSP		m_capabilities;
	ServerInfoSP				m_info;

};

} /* namespace lls */

