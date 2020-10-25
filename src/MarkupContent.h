/*
 * MarkupContent.h
 *
 *  Created on: Oct 25, 2020
 *      Author: ballance
 */

#pragma once
#include "MarkupKind.h"
#include "Val.h"
#include "ValStr.h"

namespace lls {

class MarkupContent;
typedef std::shared_ptr<MarkupContent> MarkupContentSP;
class MarkupContent : public Val {
public:
	MarkupContent(
			MarkupKindSP	kind,
			ValStrSP		value);

	virtual ~MarkupContent();

	MarkupKindSP kind() const { return m_kind; }

	void kind(MarkupKindSP k) { m_kind = k; }

	ValStrSP value() const { return m_value; }

	void value(ValStrSP v) { m_value = v; }

	virtual nlohmann::json dump();

	static MarkupContentSP mk(
			MarkupKindSP	kind,
			ValStrSP		value);

private:
	MarkupKindSP			m_kind;
	ValStrSP				m_value;

};

} /* namespace lls */

