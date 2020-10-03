/*
 * ServerInfo.h
 *
 *  Created on: Oct 2, 2020
 *      Author: ballance
 */

#pragma once
#include "Val.h"
#include "ValStr.h"

namespace lls {

class ServerInfo;
typedef std::shared_ptr<ServerInfo> ServerInfoSP;
class ServerInfo {
public:
	ServerInfo(ValStrSP name);

	virtual ~ServerInfo();

	ValStrSP name() const { return m_name; }

	void name(ValStrSP n) { m_name = n; }

	ValStrSP version() const { return m_version; }

	void version(ValStrSP v) { m_version = v; }

	virtual nlohmann::json dump();

	static ServerInfoSP mk(ValStrSP name);

private:
	ValStrSP			m_name;
	ValStrSP			m_version;

};

} /* namespace lls */

