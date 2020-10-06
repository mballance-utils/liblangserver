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
 * SocketMessageTransport.h
 *
 *  Created on: Sep 21, 2020
 *      Author: ballance
 */

#pragma once
#include <string>
#include "IMessageTransport.h"

namespace lls {

class SocketMessageTransport : public IMessageTransport {
public:
	SocketMessageTransport(
			int32_t			socket);

	virtual ~SocketMessageTransport();

	void init(IMessageTransport *in);

	int32_t process(int32_t timeout_ms=-1);

	virtual void send(const nlohmann::json &msg) override;

private:
	void msgbuf_append(char c) {
		if (m_msgbuf_idx+1 < m_msgbuf_max) {
			m_msgbuf[m_msgbuf_idx++] = c;
		} else {
			msgbuf_resize_append(c);
		}
	}

	void msgbuf_resize_append(char c);

private:
	char						*m_msgbuf;
	uint32_t					m_msgbuf_idx;
	uint32_t					m_msgbuf_max;
	uint32_t					m_msg_state;
	uint32_t					m_msg_length;
	int32_t						m_socket;
	IMessageTransport			*m_in;

	static const std::string	HEADER_PREFIX;

};

}

