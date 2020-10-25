/*
 * HoverParams.cpp
 *
 *  Created on: Oct 25, 2020
 *      Author: ballance
 */

#include "HoverParams.h"
#include "nlohmann/json.hpp"

namespace lls {

HoverParams::HoverParams(const nlohmann::json &msg) : TextDocumentPositionParams(msg) {
	// TODO Auto-generated constructor stub

}

HoverParams::~HoverParams() {
	// TODO Auto-generated destructor stub
}

HoverParamsSP HoverParams::mk(const nlohmann::json &msg) {
	return HoverParamsSP(new HoverParams(msg));
}

} /* namespace lls */
