/*
 * TestLangServer.cpp
 *
 *  Created on: Oct 1, 2020
 *      Author: ballance
 */

#include "TestLangServer.h"


TestLangServer::TestLangServer() {
	// TODO Auto-generated constructor stub

}

TestLangServer::~TestLangServer() {
	// TODO Auto-generated destructor stub
}


lls::ServerCapabilitiesSP TestLangServer::initialize(
		lls::InitializeParamsSP params) {
	lls::ServerCapabilitiesSP ret = lls::ServerCapabilities::mk();

	ret->textDocumentSync(lls::TextDocumentSyncOptions::mk(
			lls::ValBool::true_v,
			lls::TextDocumentSyncKind::Full));

	lls::CompletionOptionsSP completionOptions = lls::CompletionOptions::mk();
	completionOptions->resolveProvider(lls::ValBool::true_v);

	ret->completionProvider(completionOptions);

	fprintf(stdout, "TestLangServer::initialize\n");

	return ret;
}
