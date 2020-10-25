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
 * LangServer.cpp
 *
 *  Created on: Sep 21, 2020
 *      Author: ballance
 */

#include "LangServerMethodHandler.h"

#include "DidChangeTextDocumentParams.h"
#include "DidOpenTextDocumentParams.h"
#include "HoverParams.h"
#include "InitializeParams.h"
#include "RequestMessage.h"
#include "ResponseMessage.h"
#include "InitializeResult.h"
#include "nlohmann/json.hpp"
#include "ValNull.h"

#define EN_DEBUG_LANG_SERVER_METHOD_HANDLER

#ifdef EN_DEBUG_LANG_SERVER_METHOD_HANDLER
#define DEBUG_ENTER(fmt, ...) \
	fprintf(stdout, "--> LangServerMethodHandler::" fmt, ##__VA_ARGS__); \
	fprintf(stdout, "\n"); \
	fflush(stdout);
#define DEBUG_LEAVE(fmt, ...) \
	fprintf(stdout, "<-- LangServerMethodHandler::" fmt, ##__VA_ARGS__); \
	fprintf(stdout, "\n"); \
	fflush(stdout);
#define DEBUG_MSG(fmt, ...) \
	fprintf(stdout, "LangServerMethodHandler:: " fmt, ##__VA_ARGS__); \
	fprintf(stdout, "\n"); \
	fflush(stdout);
#else
#define DEBUG_ENTER(fmt, ...)
#define DEBUG_LEAVE(fmt, ...)
#define DEBUG_MSG(fmt, ...)
#endif

namespace lls {

LangServerMethodHandler::LangServerMethodHandler(
		IMessageTransport 	*out,
		ILangServer			*srv) : m_out(out), m_srv(srv) {

}

LangServerMethodHandler::~LangServerMethodHandler() {
	// TODO Auto-generated destructor stub
}

void LangServerMethodHandler::register_methods(IRegisterMethod *dispatcher) {
	dispatcher->register_method("textDocument/didChange",
			std::bind(&LangServerMethodHandler::didChangeTextDocument,
					this, std::placeholders::_1));
	dispatcher->register_method("textDocument/didOpen",
			std::bind(&LangServerMethodHandler::didOpenTextDocument,
					this, std::placeholders::_1));
	dispatcher->register_method("textDocument/hover",
			std::bind(&LangServerMethodHandler::hoverRequest,
					this, std::placeholders::_1));
	dispatcher->register_method("initialize",
			std::bind(&LangServerMethodHandler::initialize,this,std::placeholders::_1));
}

void LangServerMethodHandler::send(const nlohmann::json &msg) {
	// Receive a message
}

void LangServerMethodHandler::publishDiagnostics(PublishDiagnosticsParamsSP params) {
	DEBUG_ENTER("publishDiagnostics");
	RequestMessage msg(0, ValStr::mk(std::string("textDocument/publishDiagnostics")));
	msg.params(params);
	DEBUG_MSG(" -- message: %s", msg.dump().dump().c_str());
	m_out->send(msg.dump());
	DEBUG_LEAVE("publishDiagnostics");
}

void LangServerMethodHandler::initialize(const nlohmann::json &msg) {
	DEBUG_ENTER("initialize");
	InitializeParamsSP params(InitializeParams::mk(msg["params"]));

	ServerCapabilitiesSP capabilities = m_srv->initialize(this, params);
	InitializeResultSP result = InitializeResult::mk(capabilities);

	ResponseMessageSP resp = ResponseMessage::mk(ValInt::mk(msg["id"]));
	resp->result(result);

	DEBUG_MSG("response: %s", resp->dump().dump().c_str());

	m_out->send(resp->dump());

	DEBUG_LEAVE("initialize");
}

void LangServerMethodHandler::didChangeTextDocument(const nlohmann::json &msg) {
	DEBUG_ENTER("didChangetextDocument");

	DidChangeTextDocumentParamsSP params =
			DidChangeTextDocumentParams::mk(msg["params"]);
	m_srv->didChangeTextDocument(params);

	DEBUG_LEAVE("didChangetextDocument");
}

void LangServerMethodHandler::didOpenTextDocument(const nlohmann::json &msg) {
	DEBUG_ENTER("didOpenTextDocument");

	DidOpenTextDocumentParamsSP params =
			DidOpenTextDocumentParams::mk(msg["params"]);

	m_srv->didOpenTextDocument(params);
	DEBUG_LEAVE("didOpenTextDocument");
}

void LangServerMethodHandler::hoverRequest(const nlohmann::json &msg) {
	DEBUG_ENTER("hoverRequest");
	HoverParamsSP params = HoverParams::mk(msg["params"]);

	HoverSP hover = m_srv->hoverRequest(params);

	ResponseMessageSP resp = ResponseMessage::mk(ValInt::mk(msg["id"]));
	if (hover) {
		resp->result(hover);
	} else {
		resp->result(ValNull::null);
	}

	DEBUG_MSG("response: %s", resp->dump().dump().c_str());

	m_out->send(resp->dump());

	DEBUG_LEAVE("hoverRequest");
}

}
