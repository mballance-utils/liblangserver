/*
 * Range.cpp
 *
 *  Created on: Oct 5, 2020
 *      Author: ballance
 */

#include "Range.h"
#include "nlohmann/json.hpp"

namespace lls {

Range::Range(const nlohmann::json &msg) {
	m_start = Position::mk(msg["start"]);
	m_end = Position::mk(msg["end"]);
}

Range::Range(
		PositionSP		start,
		PositionSP		end) : m_start(start), m_end(end) {
	// TODO Auto-generated constructor stub

}

Range::~Range() {
	// TODO Auto-generated destructor stub
}

nlohmann::json Range::dump() {
	nlohmann::json msg;
	msg["start"] = m_start->dump();
	msg["end"] = m_end->dump();

	return msg;
}

RangeSP Range::mk(const nlohmann::json &msg) {
	return RangeSP(new Range(msg));
}

}
