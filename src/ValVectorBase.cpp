/*
 * ValVector.cpp
 *
 *  Created on: Oct 1, 2020
 *      Author: ballance
 */

#include "ValVectorBase.h"
#include "nlohmann/json.hpp"

namespace lls {

ValVectorBase::ValVectorBase(
		std::function<ValSP(const nlohmann::json &)> 	ctor,
		const nlohmann::json							&msg) {
	for (nlohmann::json::const_iterator
			it=msg.begin(); it!=msg.end(); it++) {
		ValSP v = ctor(*it);
		m_children.push_back(v);
	}
}

ValVectorBase::~ValVectorBase() {
	// TODO Auto-generated destructor stub
}

nlohmann::json ValVectorBase::dump() {
	nlohmann::json msg;

	return msg;
}

ValVectorBaseSP ValVectorBase::mk(
			std::function<ValSP(const nlohmann::json &)> 	ctor,
			const nlohmann::json 							&msg) {
	return ValVectorBaseSP(new ValVectorBase(ctor, msg));
}

} /* namespace lls */
