/*
 * LangServer.h
 *
 *  Created on: Sep 21, 2020
 *      Author: ballance
 */

#pragma once
#include "IMessageTransport.h"

class LangServer : public virtual IMessageTransport {
public:
	LangServer(IMessageTransport *out);

	virtual ~LangServer();

	/**
	 * Accept in-bound messages
	 */
	virtual void send(const std::string &msg) override;

private:
	IMessageTransport			*m_out;
};

