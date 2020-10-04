/*
 * CompletionOptions.h
 *
 *  Created on: Oct 4, 2020
 *      Author: ballance
 */

#pragma once
#include "WorkDoneProgressOptions.h"
#include "ValBool.h"
#include "ValStr.h"
#include "ValVector.h"

namespace lls {

class CompletionOptions;
typedef std::shared_ptr<CompletionOptions> CompletionOptionsSP;
class CompletionOptions : public WorkDoneProgressOptions {
public:
	CompletionOptions();

	virtual ~CompletionOptions();

	ValVector<ValStr>::SP triggerCharacters() const {
		return m_triggerCharacters;
	}

	void triggerCharacters(ValVector<ValStr>::SP v) {
		m_triggerCharacters = v;
	}

	ValVector<ValStr>::SP allCommitCharacters() const {
		return m_allCommitCharacters;
	}

	void allCommitCharacters(ValVector<ValStr>::SP v) {
		m_allCommitCharacters = v;
	}

	ValBoolSP resolveProvider() const {
		return m_resolveProvider;
	}

	void resolveProvider(ValBoolSP v) {
		m_resolveProvider = v;
	}

	virtual nlohmann::json dump();

	static CompletionOptionsSP mk();

private:
	ValVector<ValStr>::SP		m_triggerCharacters;
	ValVector<ValStr>::SP		m_allCommitCharacters;
	ValBoolSP					m_resolveProvider;

};

} /* namespace lls */

