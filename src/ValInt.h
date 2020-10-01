/*
 * ValInt.h
 *
 *  Created on: Oct 1, 2020
 *      Author: ballance
 */

#pragma once
#include "Val.h"

namespace lls {

class ValInt;
typedef std::shared_ptr<ValInt> ValIntSP;
class ValInt : public Val {
public:
	ValInt();

	virtual ~ValInt();

	static ValIntSP mk(const nlohmann::json &msg);
};

} /* namespace lls */

