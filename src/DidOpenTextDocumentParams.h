/*
 * DidOpenTextDocumentParams.h
 *
 *  Created on: Oct 5, 2020
 *      Author: ballance
 */

#pragma once
#include "Val.h"
#include "TextDocumentItem.h"

namespace lls {

class DidOpenTextDocumentParams;
typedef std::shared_ptr<DidOpenTextDocumentParams> DidOpenTextDocumentParamsSP;
class DidOpenTextDocumentParams : public Val {
public:
	DidOpenTextDocumentParams(const nlohmann::json &msg);

	virtual ~DidOpenTextDocumentParams();

	TextDocumentItemSP textDocument() const {
		return m_textDocument;
	}

	static DidOpenTextDocumentParamsSP mk(const nlohmann::json &msg);

private:
	TextDocumentItemSP					m_textDocument;


};

} /* namespace lls */

