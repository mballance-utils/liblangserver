/*
 * Hover.h
 *
 *  Created on: Oct 25, 2020
 *      Author: ballance
 */

#pragma once
#include "MarkupContent.h"
#include "Val.h"
#include "Range.h"

namespace lls {

class Hover;
typedef std::shared_ptr<Hover> HoverSP;
class Hover : public Val {
public:
	Hover(
			MarkupContentSP		contents,
			RangeSP				range);

	virtual ~Hover();

	MarkupContentSP contents() const { return m_contents; }

	void contents(MarkupContentSP c) { m_contents = c; }

	RangeSP range() const { return m_range; }

	void range(RangeSP r) { m_range = r; }

	virtual nlohmann::json dump();

	static HoverSP mk(
			MarkupContentSP		contents,
			RangeSP				range);

private:
	MarkupContentSP			m_contents;
	RangeSP					m_range;

};

} /* namespace lls */

