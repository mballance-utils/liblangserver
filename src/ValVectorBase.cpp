/*
 * ValVector.cpp
 *
 *  Created on: Oct 1, 2020
 *      Author: ballance
 */

#include "ValVectorBase.h"

namespace lls {

ValVectorBase::ValVectorBase(
		std::function<ValSP(const nlohmann::json &)> 	ctor,
		const nlohmann::json							&msg) {
	for (uint32_t i=0; ; ) {
		ValSP v = ctor(msg);
	}

}

ValVectorBase::~ValVectorBase() {
	// TODO Auto-generated destructor stub
}

} /* namespace lls */
