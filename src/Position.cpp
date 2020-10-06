/*
 * Position.cpp
 *
 *  Created on: Oct 5, 2020
 *      Author: ballance
 */

#include "Position.h"
#include "nlohmann/json.hpp"

namespace lls {

Position::Position(const nlohmann::json &msg) {
	m_line = ValInt::mk(msg["line"]);
	m_character = ValInt::mk(msg["character"]);
}

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

PositionSP Position::mk(const nlohmann::json &msg) {
	return PositionSP(new Position(msg));
}

PositionSP Position::mk(ValIntSP line, ValIntSP character) {
	return PositionSP(new Position(line, character));
}


}
