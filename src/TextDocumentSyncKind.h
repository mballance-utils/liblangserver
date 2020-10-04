/*
 * TextDocumentSyncKind.h
 *
 *  Created on: Oct 3, 2020
 *      Author: ballance
 */

#pragma once
#include "ValInt.h"

namespace lls {

class TextDocumentSyncKind;
typedef std::shared_ptr<TextDocumentSyncKind> TextDocumentSyncKindSP;
class TextDocumentSyncKind : public ValInt {
public:
	TextDocumentSyncKind(int64_t v);

	TextDocumentSyncKind(const nlohmann::json &msg);

	virtual ~TextDocumentSyncKind();

	static TextDocumentSyncKindSP mk(const nlohmann::json &msg);

	static const TextDocumentSyncKindSP	None;
	static const TextDocumentSyncKindSP	Full;
	static const TextDocumentSyncKindSP	Incremental;

};

} /* namespace lls */

