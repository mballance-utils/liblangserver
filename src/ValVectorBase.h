/*
 * ValVector.h
 *
 *  Created on: Oct 1, 2020
 *      Author: ballance
 */

#pragma once
#include <functional>
#include "Val.h"

namespace lls {

class ValVectorBase;
typedef std::shared_ptr<ValVectorBase> ValVectorBaseSP;
class ValVectorBase : public Val {
public:
	ValVectorBase();

	ValVectorBase(
			std::function<ValSP(const nlohmann::json &)> 	ctor,
			const nlohmann::json 							&msg);

	virtual ~ValVectorBase();

	const std::vector<ValSP> &children() const {
		return m_children;
	}

	ValSP children(uint32_t idx) const {
		return m_children.at(idx);
	}

	static ValVectorBaseSP mk(
			std::function<ValSP(const nlohmann::json &)> 	ctor,
			const nlohmann::json 							&msg);

private:
	std::vector<ValSP>				m_children;

};


} /* namespace lls */

