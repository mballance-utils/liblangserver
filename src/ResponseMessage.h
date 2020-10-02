/*
 * ResponseMessage.h
 *
 *  Created on: Sep 29, 2020
 *      Author: ballance
 */

#pragma once
#include "Message.h"
#include "Val.h"
#include "ValInt.h"

namespace lls {

class ResponseMessage : public Message {
public:
	ResponseMessage();

	ResponseMessage(ValIntSP id);

	virtual ~ResponseMessage();

	virtual void load(const nlohmann::json &msg);

	virtual nlohmann::json dump();

protected:
	ValIntSP				m_id;
	ValSP					m_result;

};

} /* namespace lls */

