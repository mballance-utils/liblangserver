/*
 * ValStr.cpp
 *
 *  Created on: Sep 30, 2020
 *      Author: ballance
 */

#include "ValStr.h"
#include "nlohmann/json.hpp"

namespace lls {

ValStr::ValStr(const nlohmann::json &msg) {
	m_val = msg.get<std::string>();
}

ValStr::ValStr(const std::string &v) : m_val(v) {

}

ValStr::~ValStr() {
	// TODO Auto-generated destructor stub
}

ValStrSP ValStr::mk(const nlohmann::json &msg) {
	return ValStrSP(new ValStr(msg));
}

} /* namespace lls */
