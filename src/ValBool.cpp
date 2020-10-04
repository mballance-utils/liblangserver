/*
 * ValBool.cpp
 *
 *  Created on: Oct 3, 2020
 *      Author: ballance
 */

#include "ValBool.h"
#include "nlohmann/json.hpp"

namespace lls {

ValBool::ValBool(bool v) : m_val(v) {

}

ValBool::ValBool(const nlohmann::json &msg) {
	m_val = msg.get<bool>();
}

ValBool::~ValBool() {
	// TODO Auto-generated destructor stub
}

nlohmann::json ValBool::dump() {
	return nlohmann::json(m_val);
}

ValBoolSP ValBool::mk(bool v) {
	return ValBoolSP(new ValBool(v));
}

ValBoolSP ValBool::mk(const nlohmann::json &msg) {
	return ValBoolSP(new ValBool(msg));
}

const ValBoolSP	ValBool::true_v(new ValBool(true));
const ValBoolSP	ValBool::false_v(new ValBool(false));

} /* namespace lls */
