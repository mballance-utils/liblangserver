/*
 * MarkupKind.cpp
 *
 *  Created on: Oct 25, 2020
 *      Author: ballance
 */

#include "MarkupKind.h"

namespace lls {

MarkupKind::MarkupKind(const std::string &val) : ValStr(val) {
	// TODO Auto-generated constructor stub

}

MarkupKind::~MarkupKind() {
	// TODO Auto-generated destructor stub
}

MarkupKindSP MarkupKind::PlainText = MarkupKindSP(new MarkupKind("plaintext"));
MarkupKindSP MarkupKind::Markdown = MarkupKindSP(new MarkupKind("markdown"));

} /* namespace lls */
