/*
 * IServer.h
 *
 *  Created on: Oct 1, 2020
 *      Author: ballance
 */

#pragma once
#include "InitializeParams.h"
#include "ServerCapabilities.h"

namespace lls {

class ILangServer {
public:

	virtual ~ILangServer() { }

	virtual ServerCapabilitiesSP initialize(InitializeParamsSP params) = 0;

};

}
