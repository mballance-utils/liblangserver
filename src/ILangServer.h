/*
 * IServer.h
 *
 *  Created on: Oct 1, 2020
 *      Author: ballance
 */

#pragma once
#include "DidChangeTextDocumentParams.h"
#include "DidOpenTextDocumentParams.h"
#include "IClientConnection.h"
#include "InitializeParams.h"
#include "ServerCapabilities.h"

namespace lls {

class ILangServer {
public:

	virtual ~ILangServer() { }

	virtual ServerCapabilitiesSP initialize(
			IClientConnection		*connection,
			InitializeParamsSP 		params) = 0;

	virtual void didChangeTextDocument(DidChangeTextDocumentParamsSP params) = 0;

	virtual void didOpenTextDocument(DidOpenTextDocumentParamsSP params) = 0;

};

}
