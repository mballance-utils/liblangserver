/*
 * RequestMessage.h
 *
 *  Created on: Sep 29, 2020
 *      Author: ballance
 */

#pragma once
#include "Message.h"
#include "Val.h"
#include "ValInt.h"
#include "ValStr.h"

namespace lls {

class RequestMessage : public Message {
public:
	RequestMessage(const nlohmann::json &msg);

	RequestMessage(int32_t id, const std::string &method);

	virtual ~RequestMessage();

	int64_t id() const { return m_id->val(); }

	void id(int64_t i) { m_id->val(i); }

	const std::string &method() const { return m_method->val(); }

	void method(const std::string &m) { m_method->val(m); }

	ValSP params() const { return m_params; }

	void params(ValSP p) { m_params = p; }

	virtual void load(const nlohmann::json &msg);

	virtual void dump(nlohmann::json &msg);

	virtual nlohmann::json dump();

protected:
	ValIntSP			m_id;
	ValStrSP			m_method;

	ValSP				m_params;

};

} /* namespace lls */

