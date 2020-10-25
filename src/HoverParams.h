/*
 * HoverParams.h
 *
 *  Created on: Oct 25, 2020
 *      Author: ballance
 */

#pragma once
#include "TextDocumentPositionParams.h"

namespace lls {

class HoverParams;
typedef std::shared_ptr<HoverParams> HoverParamsSP;
class HoverParams : public TextDocumentPositionParams {
public:
	HoverParams(const nlohmann::json &msg);

	virtual ~HoverParams();

	static HoverParamsSP mk(const nlohmann::json &msg);

private:

};

} /* namespace lls */

