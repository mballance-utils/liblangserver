/*
 * CompletionOptions.cpp
 *
 *  Created on: Oct 4, 2020
 *      Author: ballance
 */

#include "CompletionOptions.h"
#include "nlohmann/json.hpp"

namespace lls {

CompletionOptions::CompletionOptions() {
	// TODO Auto-generated constructor stub

}

CompletionOptions::~CompletionOptions() {
	// TODO Auto-generated destructor stub
}

nlohmann::json CompletionOptions::dump() {
	nlohmann::json msg;

	WorkDoneProgressOptions::dump(msg);
	if (m_triggerCharacters) {
		msg["triggerCharacters"] = m_triggerCharacters->dump();
	}
	if (m_allCommitCharacters) {
		msg["allCommitCharacters"] = m_allCommitCharacters->dump();
	}
	if (m_resolveProvider) {
		msg["resolveProvider"] = m_resolveProvider->dump();
	}

	return msg;
}

CompletionOptionsSP CompletionOptions::mk() {
	return CompletionOptionsSP(new CompletionOptions());
}

} /* namespace lls */
