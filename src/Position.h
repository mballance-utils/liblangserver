/*
 * Position.h
 *
 *  Created on: Oct 5, 2020
 *      Author: ballance
 */

#pragma once
#include "Val.h"
#include "ValInt.h"

namespace lls {

class Position;
typedef std::shared_ptr<Position> PositionSP;
class Position : public Val {
public:
	Position(
			ValIntSP		line,
			ValIntSP		character);

	virtual ~Position();

	ValIntSP line() const { return m_line; }

	void line(ValIntSP l) { m_line = l; }

	ValIntSP character() const { return m_character; }

	void character(ValIntSP v) { m_character = v; }

	virtual nlohmann::json dump();

	static PositionSP mk(
			ValIntSP line,
			ValIntSP character);

private:
	ValIntSP			m_line;
	ValIntSP			m_character;

};

}
