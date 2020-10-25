/*
 * TextDocumentPositionParams.h
 *
 *  Created on: Oct 25, 2020
 *      Author: ballance
 */

#pragma once
#include "Position.h"
#include "TextDocumentIdentifier.h"
#include "Val.h"

namespace lls {

class TextDocumentPositionParams;
typedef std::shared_ptr<TextDocumentPositionParams> TextDocumentPositionParamsSP;
class TextDocumentPositionParams : public Val {
public:
	TextDocumentPositionParams(const nlohmann::json &msg);

	virtual ~TextDocumentPositionParams();

	static TextDocumentPositionParamsSP mk(const nlohmann::json &msg);

private:

	TextDocumentIdentifierSP		m_textDocument;
	PositionSP						m_position;

};

} /* namespace lls */

