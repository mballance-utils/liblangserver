/*
 * TextDocumentContentChangeEvent.h
 *
 *  Created on: Oct 5, 2020
 *      Author: ballance
 */

#pragma once
#include "Range.h"
#include "Val.h"
#include "ValStr.h"
#include "ValVector.h"

namespace lls {

class TextDocumentContentChangeEvent;
typedef std::shared_ptr<TextDocumentContentChangeEvent> TextDocumentContentChangeEventSP;
class TextDocumentContentChangeEvent : public Val {
public:
	TextDocumentContentChangeEvent(const nlohmann::json &msg);

	virtual ~TextDocumentContentChangeEvent();

	RangeSP range() const { return m_range; }

	ValStrSP text() const { return m_text; }

	static TextDocumentContentChangeEventSP mk(const nlohmann::json &msg);

private:
	RangeSP											m_range;
	ValStrSP										m_text;

};

} /* namespace lls */

