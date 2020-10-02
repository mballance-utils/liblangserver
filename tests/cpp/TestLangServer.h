/*
 * TestLangServer.h
 *
 *  Created on: Oct 1, 2020
 *      Author: ballance
 */

#pragma once
#include "BaseLangServer.h"

class TestLangServer : public lls::BaseLangServer {
public:
	TestLangServer();

	virtual ~TestLangServer();

	virtual lls::ServerCapabilitiesSP initialize(lls::InitializeParamsSP params) override;


};

