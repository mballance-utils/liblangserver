/*
 * Range.h
 *
 *  Created on: Oct 5, 2020
 *      Author: ballance
 */

#pragma once
#include "Val.h"
#include "Position.h"

namespace lls {

class Range;
typedef std::shared_ptr<Range> RangeSP;
class Range {
public:
	Range(const nlohmann::json &msg);

	Range(
		PositionSP		start,
		PositionSP		end);

	virtual ~Range();

	PositionSP start() const { return m_start; }

	void start(PositionSP v) { m_start = v; }

	PositionSP end() const { return m_end; }

	void end(PositionSP v) { m_end = v; }

	virtual nlohmann::json dump();

	static RangeSP mk(PositionSP start, PositionSP end);

	static RangeSP mk(const nlohmann::json &msg);

private:
	PositionSP			m_start;
	PositionSP			m_end;

};

}
