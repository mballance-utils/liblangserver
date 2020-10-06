/*
 * Range.cpp
 *
 *  Created on: Oct 5, 2020
 *      Author: ballance
 */

#include "Range.h"
#include "nlohmann/json.hpp"

namespace lls {

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

}
