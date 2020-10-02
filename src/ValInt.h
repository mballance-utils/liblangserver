/*
 * ValInt.h
 *
 *  Created on: Oct 1, 2020
 *      Author: ballance
 */

#pragma once
#include "Val.h"

namespace lls {

class ValInt;
typedef std::shared_ptr<ValInt> ValIntSP;
class ValInt : public Val {
public:
	ValInt(int64_t v);

	virtual ~ValInt();

	int64_t val() const { return m_val; }

	void val(int64_t v) { m_val = v; }

	virtual nlohmann::json dump() override;

	static ValIntSP mk(const nlohmann::json &msg);

	static ValIntSP mk(int32_t v);

private:
	int64_t					m_val;

};

} /* namespace lls */

