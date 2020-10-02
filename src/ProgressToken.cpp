/*
 * ProgressToken.cpp
 *
 *  Created on: Sep 30, 2020
 *      Author: ballance
 */

#include "ProgressToken.h"
#include "nlohmann/json.hpp"

namespace lls {

ProgressToken::ProgressToken(const nlohmann::json &msg) {
	if (msg.is_number()) {
	} else {

	}

}

ProgressToken::~ProgressToken() {
	// TODO Auto-generated destructor stub
}

ProgressTokenSP ProgressToken::mk(const nlohmann::json &msg) {
	return ProgressTokenSP(new ProgressToken(msg));
}

} /* namespace lls */
