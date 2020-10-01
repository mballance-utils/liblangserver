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
class ValStr {
public:
	ValStr(const std::string &v);

	ValStr(const nlohmann::json &msg);

	virtual ~ValStr();

	const std::string &val() const { return m_val; }

	static ValStrSP mk(const nlohmann::json &msg);

private:
	std::string				m_val;
};

} /* namespace lls */

