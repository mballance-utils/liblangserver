/*
 * WorkDoneProgressParams.cpp
 *
 *  Created on: Sep 30, 2020
 *      Author: ballance
 */

#include "WorkDoneProgressParams.h"
#include "nlohmann/json.hpp"

namespace lls {

WorkDoneProgressParams::WorkDoneProgressParams(const nlohmann::json &msg) {
	if (msg.contains("workDoneToken")) {
		m_workDoneToken = ProgressToken::mk(msg["workDoneToken"]);
	}

}

WorkDoneProgressParams::~WorkDoneProgressParams() {
	// TODO Auto-generated destructor stub
}

} /* namespace lls */
