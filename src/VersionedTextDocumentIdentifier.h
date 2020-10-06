/*
 * VersionedTextDocumentIdentifier.h
 *
 *  Created on: Oct 5, 2020
 *      Author: ballance
 */

#pragma once
#include "Val.h"
#include "ValInt.h"
#include "TextDocumentIdentifier.h"

namespace lls {

class VersionedTextDocumentIdentifier;
typedef std::shared_ptr<VersionedTextDocumentIdentifier> VersionedTextDocumentIdentifierSP;
class VersionedTextDocumentIdentifier : public TextDocumentIdentifier {
public:
	VersionedTextDocumentIdentifier(const nlohmann::json &msg);

	virtual ~VersionedTextDocumentIdentifier();

	ValIntSP version() const { return m_version; }

	void version(ValIntSP v) { m_version = v; }

	static VersionedTextDocumentIdentifierSP mk(const nlohmann::json &msg);

private:
	ValIntSP			m_version;
};

} /* namespace lls */

