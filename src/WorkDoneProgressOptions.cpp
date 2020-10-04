/*
 * WorkDoneProgressOptions.cpp
 *
 *  Created on: Oct 4, 2020
 *      Author: ballance
 */

#include "WorkDoneProgressOptions.h"
#include "nlohmann/json.hpp"

namespace lls {

WorkDoneProgressOptions::WorkDoneProgressOptions() {

}

WorkDoneProgressOptions::WorkDoneProgressOptions(const nlohmann::json &msg) {
	if (msg.contains("workDoneProgress")) {
		m_workDoneProgress = ValBool::mk(msg["workDoneProgress"]);
	}
}

WorkDoneProgressOptions::~WorkDoneProgressOptions() {
	// TODO Auto-generated destructor stub
}

void WorkDoneProgressOptions::dump(nlohmann::json &msg) {
	if (m_workDoneProgress) {
		msg["workDoneProgress"] = m_workDoneProgress->dump();
	}
}

} /* namespace lls */
