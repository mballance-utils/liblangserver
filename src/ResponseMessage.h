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

class ResponseMessage;
typedef std::shared_ptr<ResponseMessage> ResponseMessageSP;
class ResponseMessage : public Message {
public:
	ResponseMessage();

	ResponseMessage(ValIntSP id);

	virtual ~ResponseMessage();

	ValSP result() const { return m_result; }

	void result(ValSP r) { m_result = r; }

	virtual void load(const nlohmann::json &msg);

	virtual nlohmann::json dump();

	static ResponseMessageSP mk(ValIntSP id);

protected:
	ValIntSP				m_id;
	ValSP					m_result;

};

} /* namespace lls */

