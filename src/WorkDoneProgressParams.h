/*
 * WorkDoneProgressParams.h
 *
 *  Created on: Sep 30, 2020
 *      Author: ballance
 */

#pragma once
#include "Val.h"
#include "ProgressToken.h"

namespace lls {

class WorkDoneProgressParams;
typedef std::shared_ptr<WorkDoneProgressParams> WorkDoneProgressParamsSP;
class WorkDoneProgressParams : public Val {
public:
	WorkDoneProgressParams();

	WorkDoneProgressParams(const nlohmann::json &msg);

	virtual ~WorkDoneProgressParams();

	virtual void dump(nlohmann::json &msg);

	static WorkDoneProgressParamsSP mk(const nlohmann::json &msg);

private:
	ProgressTokenSP				m_workDoneToken;


};

} /* namespace lls */

