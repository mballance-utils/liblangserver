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
	/*
	for (uint32_t i=0; ; ) {
		ValSP v = ctor(msg);
	}
	 */

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
