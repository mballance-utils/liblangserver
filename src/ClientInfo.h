/*
 * ClientInfo.h
 *
 *  Created on: Sep 30, 2020
 *      Author: ballance
 */

#pragma once
#include "Val.h"
#include "ValStr.h"

namespace lls {

class ClientInfo;
typedef std::shared_ptr<ClientInfo> ClientInfoSP;
class ClientInfo : public Val {
public:
	ClientInfo(const nlohmann::json &msg);

	virtual ~ClientInfo();

	ValStrSP name() const { return m_name; }

	ValStrSP version() const { return m_version; }

	static ClientInfoSP mk(const nlohmann::json &msg);

private:
	ValStrSP			m_name;
	ValStrSP			m_version;
};

} /* namespace lls */

