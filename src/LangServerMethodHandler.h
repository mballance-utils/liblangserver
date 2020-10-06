/*
 * LangServer.h
 *
 *  Created on: Sep 21, 2020
 *      Author: ballance
 */

#pragma once
#include <map>
#include <functional>
#include <string>

#include "ILangServer.h"
#include "IMessageTransport.h"
#include "IRegisterMethod.h"
#include "nlohmann/json_fwd.hpp"

namespace lls {

/**
 * Implements processing and handling of LSP messages
 */
class LangServerMethodHandler : public virtual IMessageTransport {
public:
	LangServerMethodHandler(
			IMessageTransport 	*out,
			ILangServer			*srv);

	virtual ~LangServerMethodHandler();

	void register_methods(
			IRegisterMethod		*dispatcher);

	/**
	 * Accept in-bound messages
	 */
	virtual void send(const nlohmann::json &msg) override;

private:

	virtual void initialize(const nlohmann::json &msg);

	virtual void didOpenTextDocument(const nlohmann::json &msg);

private:
	IMessageTransport							*m_out;
	ILangServer									*m_srv;
};

}

