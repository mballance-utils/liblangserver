/*
 * Hover.cpp
 *
 *  Created on: Oct 25, 2020
 *      Author: ballance
 */

#include "Hover.h"
#include "nlohmann/json.hpp"

namespace lls {

Hover::Hover(
		MarkupContentSP		contents,
		RangeSP				range) : m_contents(contents), m_range(range) {
	// TODO Auto-generated constructor stub

}

Hover::~Hover() {
	// TODO Auto-generated destructor stub
}


nlohmann::json Hover::dump() {
	nlohmann::json msg;
	msg["contents"] = m_contents->dump();

	if (m_range) {
		msg["range"] = m_range->dump();
	}

	return msg;
}

HoverSP Hover::mk(
			MarkupContentSP		contents,
			RangeSP				range) {
	return HoverSP(new Hover(contents, range));
}

} /* namespace lls */
