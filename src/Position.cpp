/*
 * Position.cpp
 *
 *  Created on: Oct 5, 2020
 *      Author: ballance
 */

#include "Position.h"
#include "nlohmann/json.hpp"

namespace lls {

Position::Position(
		ValIntSP			line,
		ValIntSP			character) :
		m_line(line), m_character(character) {
	// TODO Auto-generated constructor stub

}

Position::~Position() {
	// TODO Auto-generated destructor stub
}

nlohmann::json Position::dump() {
	nlohmann::json msg;
	msg["line"] = m_line->dump();
	msg["character"] = m_character->dump();

	return msg;
}


}
