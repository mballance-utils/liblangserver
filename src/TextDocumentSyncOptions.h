/*
 * TextDocumentSyncOptions.h
 *
 *  Created on: Oct 3, 2020
 *      Author: ballance
 */

#pragma once
#include "Val.h"
#include "ValBool.h"
#include "TextDocumentSyncKind.h"

namespace lls {

class TextDocumentSyncOptions;
typedef std::shared_ptr<TextDocumentSyncOptions> TextDocumentSyncOptionsSP;
class TextDocumentSyncOptions : public Val {
public:
	TextDocumentSyncOptions(
			ValBoolSP				openClose,
			TextDocumentSyncKindSP	change);

	TextDocumentSyncOptions(const nlohmann::json &msg);

	virtual ~TextDocumentSyncOptions();

	ValBoolSP openClose() const { return m_openClose; }

	void openClose(ValBoolSP v) { m_openClose = v; }

	virtual nlohmann::json dump();

	static TextDocumentSyncOptionsSP mk(
			ValBoolSP				openClose,
			TextDocumentSyncKindSP	change);

private:
	ValBoolSP					m_openClose;
	TextDocumentSyncKindSP		m_change;
};

} /* namespace lls */

