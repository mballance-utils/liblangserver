/*
 * MarkupKind.h
 *
 *  Created on: Oct 25, 2020
 *      Author: ballance
 */

#pragma once
#include "ValStr.h"

namespace lls {

class MarkupKind;
typedef std::shared_ptr<MarkupKind> MarkupKindSP;
class MarkupKind : public ValStr {
public:

	virtual ~MarkupKind();

	static MarkupKindSP PlainText;
	static MarkupKindSP Markdown;

private:
	MarkupKind(const std::string &val);

};

} /* namespace lls */

