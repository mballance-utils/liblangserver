/*
 * MarkupContent.cpp
 *
 *  Created on: Oct 25, 2020
 *      Author: ballance
 */

#include "MarkupContent.h"
#include "nlohmann/json.hpp"

namespace lls {

MarkupContent::MarkupContent(
		MarkupKindSP		kind,
		ValStrSP			value) : m_kind(kind), m_value(value) {
	// TODO Auto-generated constructor stub

}

MarkupContent::~MarkupContent() {
	// TODO Auto-generated destructor stub
}

nlohmann::json MarkupContent::dump() {
	nlohmann::json msg;

	msg["kind"] = m_kind->dump();
	msg["value"] = m_value->dump();

	return msg;
}

MarkupContentSP MarkupContent::mk(
			MarkupKindSP	kind,
			ValStrSP		value) {
	return MarkupContentSP(new MarkupContent(
			kind, value));
}

} /* namespace lls */
