/*
 * TextDocumentIdentifier.h
 *
 *  Created on: Oct 5, 2020
 *      Author: ballance
 */

#pragma once
#include "Val.h"
#include "ValStr.h"

namespace lls {

class TextDocumentIdentifier;
typedef std::shared_ptr<TextDocumentIdentifier> TextDocumentIdentifierSP;
class TextDocumentIdentifier : public Val {
public:
	TextDocumentIdentifier(const nlohmann::json &msg);

	virtual ~TextDocumentIdentifier();

	ValStrSP uri() const { return m_uri; }

	void uri(ValStrSP v) { m_uri = v; }

	static TextDocumentIdentifierSP mk(const nlohmann::json &msg);

private:
	ValStrSP				m_uri;
};

} /* namespace lls */

