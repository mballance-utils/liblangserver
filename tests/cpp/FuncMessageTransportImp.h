/*
 * FuncMessageTransportImp.h
 *
 *  Created on: Sep 24, 2020
 *      Author: ballance
 */

#pragma once
#include <functional>
#include "IMessageTransport.h"
#include "nlohmann/json_fwd.hpp"

class FuncMessageTransportImp : public virtual IMessageTransport {
public:
	FuncMessageTransportImp(std::function<void(const nlohmann::json &)> recv);

	virtual ~FuncMessageTransportImp();

	virtual void send(const nlohmann::json &msg) override;

private:
	std::function<void(const nlohmann::json &)>		m_recv;
};

