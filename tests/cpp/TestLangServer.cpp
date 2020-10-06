/**
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */
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
		lls::IClientConnection	*connection,
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
