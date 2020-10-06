/*
 * TextDocumentItem.h
 *
 *  Created on: Oct 5, 2020
 *      Author: ballance
 */

#pragma once
#include "Val.h"
#include "ValInt.h"
#include "ValStr.h"

namespace lls {

class TextDocumentItem;
typedef std::shared_ptr<TextDocumentItem> TextDocumentItemSP;
class TextDocumentItem : public Val {
public:
	TextDocumentItem(const nlohmann::json &msg);

	virtual ~TextDocumentItem();

	ValStrSP uri() const { return m_uri; }

	void uri(ValStrSP v) { m_uri = v; }

	ValStrSP languageId() const { return m_languageId; }

	void languageId(ValStrSP v) { m_languageId = v; }

	ValIntSP version() const { return m_version; }

	void version(ValIntSP v) { m_version = v; }

	ValStrSP text() const { return m_text; }

	void text(ValStrSP v) { m_text = v; }

	static TextDocumentItemSP mk(const nlohmann::json &msg);


private:
	ValStrSP			m_uri;

	ValStrSP			m_languageId;

	ValIntSP			m_version;

	ValStrSP			m_text;

};

} /* namespace lls */

