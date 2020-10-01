/*
 * Val.h
 *
 *  Created on: Sep 30, 2020
 *      Author: ballance
 */

#pragma once
#include <memory>
#include "nlohmann/json_fwd.hpp"

namespace lls {

class Val;
typedef std::shared_ptr<Val> ValSP;

class Val {
public:
	Val();

	virtual ~Val();

	virtual nlohmann::json dump();

	static ValSP load(const nlohmann::json &msg);

};


} /* namespace lls */

