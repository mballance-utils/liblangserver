/*
 * ProgressToken.h
 *
 *  Created on: Sep 30, 2020
 *      Author: ballance
 */

#pragma once
#include "Val.h"

namespace lls {

class ProgressToken;
typedef std::shared_ptr<ProgressToken> ProgressTokenSP;
class ProgressToken : public Val {
public:
	ProgressToken(const nlohmann::json &msg);

	virtual ~ProgressToken();

	static ProgressTokenSP mk(const nlohmann::json &msg);

private:

	/** number | string */
	ValSP				m_value;

};

} /* namespace lls */

