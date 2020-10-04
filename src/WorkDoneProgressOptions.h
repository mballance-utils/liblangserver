/*
 * WorkDoneProgressOptions.h
 *
 *  Created on: Oct 4, 2020
 *      Author: ballance
 */

#pragma once
#include "Val.h"
#include "ValBool.h"

namespace lls {

class WorkDoneProgressOptions : public Val {
public:
	WorkDoneProgressOptions();

	WorkDoneProgressOptions(const nlohmann::json &msg);

	virtual ~WorkDoneProgressOptions();

	ValBoolSP workDoneProgress() const {
		return m_workDoneProgress;
	}

	void workDoneProgress(ValBoolSP v) {
		m_workDoneProgress = v;
	}

	virtual void dump(nlohmann::json &msg);

private:
	ValBoolSP			m_workDoneProgress;

};

} /* namespace lls */

