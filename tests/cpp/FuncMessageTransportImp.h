/*
 * FuncMessageTransportImp.h
 *
 *  Created on: Sep 24, 2020
 *      Author: ballance
 */

#pragma once
#include <functional>
#include "IMessageTransport.h"

class FuncMessageTransportImp : public virtual IMessageTransport {
public:
	FuncMessageTransportImp(std::function<void(const std::string &)> recv);

	virtual ~FuncMessageTransportImp();

	virtual void send(const std::string &msg) override;

private:
	std::function<void(const std::string &)>		m_recv;
};

