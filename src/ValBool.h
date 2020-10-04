/*
 * ValBool.h
 *
 *  Created on: Oct 3, 2020
 *      Author: ballance
 */

#pragma once
#include "Val.h"

namespace lls {

class ValBool;
typedef std::shared_ptr<ValBool> ValBoolSP;
class ValBool : public Val {
public:
	ValBool(bool v=false);

	ValBool(const nlohmann::json &msg);

	virtual ~ValBool();

	virtual nlohmann::json dump();

	static ValBoolSP mk(bool v=false);

	static ValBoolSP mk(const nlohmann::json &msg);

public:
	static const ValBoolSP	true_v;
	static const ValBoolSP	false_v;

private:
	bool			m_val;
};

} /* namespace lls */

