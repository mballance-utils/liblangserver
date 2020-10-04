/*
 * ValInt.cpp
 *
 *  Created on: Oct 1, 2020
 *      Author: ballance
 */

#include "ValInt.h"
#include "nlohmann/json.hpp"

namespace lls {

ValInt::ValInt(int64_t v) : m_val(v){

}

ValInt::ValInt(const nlohmann::json &msg) {
	if (msg.is_number()) {
		m_val = msg;
	} else if (msg.is_string()) {
		m_val =std::stoi(msg.get<std::string>());
	} else {
		// ERROR
		m_val = -1;
	}
}

ValInt::~ValInt() {
	// TODO Auto-generated destructor stub
}

nlohmann::json ValInt::dump() {
	return nlohmann::json(m_val);
}

ValIntSP ValInt::mk(const nlohmann::json &msg) {
	if (msg.is_number()) {
		return ValIntSP(new ValInt(msg));
	} else if (msg.is_string()) {
		return ValIntSP(new ValInt(std::stoi(msg.get<std::string>())));
	} else {
		// ERROR
		return ValIntSP(new ValInt(-1));
	}
}

ValIntSP ValInt::mk(int32_t v) {
	return ValIntSP(new ValInt(v));
}

} /* namespace lls */
