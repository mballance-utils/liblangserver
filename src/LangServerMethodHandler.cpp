/*
 * LangServer.cpp
 *
 *  Created on: Sep 21, 2020
 *      Author: ballance
 */

#include "LangServerMethodHandler.h"

#include "DidChangeTextDocumentParams.h"
#include "DidOpenTextDocumentParams.h"
#include "InitializeParams.h"
#include "RequestMessage.h"
#include "ResponseMessage.h"
#include "InitializeResult.h"
#include "nlohmann/json.hpp"

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
	dispatcher->register_method("initialize",
			std::bind(&LangServerMethodHandler::initialize,this,std::placeholders::_1));
}

void LangServerMethodHandler::send(const nlohmann::json &msg) {
	// Receive a message
}

void LangServerMethodHandler::publishDiagnostics(PublishDiagnosticsParamsSP params) {
	RequestMessage msg(0, ValStr::mk(std::string("textDocument/publishDiagnostics")));
	msg.params(params);
	m_out->send(msg.dump());
}

void LangServerMethodHandler::initialize(const nlohmann::json &msg) {
	InitializeParamsSP params(InitializeParams::mk(msg["params"]));

	ServerCapabilitiesSP capabilities = m_srv->initialize(this, params);
	InitializeResultSP result = InitializeResult::mk(capabilities);

	ResponseMessageSP resp = ResponseMessage::mk(ValInt::mk(msg["id"]));
	resp->result(result);

	fprintf(stdout, "response: %s\n",
			resp->dump().dump().c_str());
	m_out->send(resp->dump());

}

void LangServerMethodHandler::didChangeTextDocument(const nlohmann::json &msg) {
	fprintf(stdout, "--> didChangetextDocument\n");
	fflush(stdout);

	DidChangeTextDocumentParamsSP params =
			DidChangeTextDocumentParams::mk(msg["params"]);
	m_srv->didChangeTextDocument(params);

	fprintf(stdout, "<-- didChangetextDocument\n");
	fflush(stdout);
}

void LangServerMethodHandler::didOpenTextDocument(const nlohmann::json &msg) {

	fprintf(stdout, "didOpenTextDocument\n");
	fflush(stdout);

	fprintf(stdout, "--> construct\n");
	fflush(stdout);
	DidOpenTextDocumentParamsSP params =
			DidOpenTextDocumentParams::mk(msg["params"]);
	fprintf(stdout, "<-- construct\n");
	fflush(stdout);

	m_srv->didOpenTextDocument(params);
}

}
