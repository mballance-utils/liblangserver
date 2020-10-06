/*
 * DidChangeTextDocumentParams.h
 *
 *  Created on: Oct 5, 2020
 *      Author: ballance
 */

#pragma once
#include "Val.h"
#include "VersionedTextDocumentIdentifier.h"
#include "TextDocumentContentChangeEvent.h"
#include "ValVector.h"

namespace lls {

class DidChangeTextDocumentParams;
typedef std::shared_ptr<DidChangeTextDocumentParams> DidChangeTextDocumentParamsSP;
class DidChangeTextDocumentParams : public Val {
public:
	DidChangeTextDocumentParams(const nlohmann::json &msg);

	virtual ~DidChangeTextDocumentParams();

	VersionedTextDocumentIdentifierSP textDocument() const {
		return m_textDocument;
	}

	static DidChangeTextDocumentParamsSP mk(const nlohmann::json &msg);

private:
	VersionedTextDocumentIdentifierSP				m_textDocument;
	ValVector<TextDocumentContentChangeEvent>::SP	m_contentChanges;

};

} /* namespace lls */

