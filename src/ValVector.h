/*
 * ValVector.h
 *
 *  Created on: Oct 1, 2020
 *      Author: ballance
 */

#pragma once
#include "ValVectorBase.h"

namespace lls {

template <class T> class ValVector : public ValVectorBase {
public:
	typedef std::shared_ptr<ValVector<T>> SP;
public:

	ValVector() { }

	const std::vector<std::shared_ptr<T>> &children() const {
		return std::dynamic_pointer_cast<std::vector<std::shared_ptr<T>>>(
				ValVectorBase::children());
	}

	std::shared_ptr<T> children(uint32_t idx) const {
		return std::dynamic_pointer_cast<std::shared_ptr<T>>(
				ValVectorBase::children(idx));
	}

	static SP mk(const nlohmann::json &msg) {
		return std::dynamic_pointer_cast<ValVector<T>>(
				ValVectorBase::mk(
						[&](const nlohmann::json &sm) {
							return ValSP(new T(sm));
						}, msg));
	}

};

}

