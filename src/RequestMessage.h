/*
 * RequestMessage.h
 *
 *  Created on: Sep 29, 2020
 *      Author: ballance
 */

#pragma once
#include "Message.h"

namespace lls {

class RequestMessage : public Message {
public:
	RequestMessage();

	virtual ~RequestMessage();

	int32_t id() const { return m_id; }

	void id(int32_t i) { m_id = i; }

	const std::string &method() const { return m_method; }

	void method(const std::string &m) { m_method = m; }

	virtual void load(const nlohmann::json &msg);

	virtual void dump(nlohmann::json &msg);

protected:
	int32_t			m_id;
	std::string		m_method;
	// TODO: params

		/**
		 * The method's params.
		 */
//params?: array | object;
};

} /* namespace lls */

