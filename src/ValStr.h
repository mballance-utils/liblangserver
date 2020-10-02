/*
 * ValStr.h
 *
 *  Created on: Sep 30, 2020
 *      Author: ballance
 */

#pragma once
#include <string>
#include "Val.h"

namespace lls {

class ValStr;
typedef std::shared_ptr<ValStr> ValStrSP;
class ValStr : public Val {
public:
	ValStr(const std::string &v);

	ValStr(const nlohmann::json &msg);

	virtual ~ValStr();

	const std::string &val() const { return m_val; }

	void val(const std::string &v) { m_val = v; }

	virtual nlohmann::json dump() override;

	static ValStrSP mk(const nlohmann::json &msg);

	static ValStrSP mk(const std::string &v);

private:
	std::string				m_val;
};

} /* namespace lls */

