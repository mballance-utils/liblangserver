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
 * SocketMessageTransport.cpp
 *
 *  Created on: Sep 21, 2020
 *      Author: ballance
 */

#include "SocketMessageTransport.h"
#include <string>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#ifndef _WIN32
#include <sys/socket.h>
#else
#include <winsock.h>
#endif
#include "nlohmann/json.hpp"

#undef EN_DEBUG_SOCKET_MESSAGE_TRANSPORT

#ifdef EN_DEBUG_SOCKET_MESSAGE_TRANSPORT
#define DEBUG_ENTER(fmt, ...) \
	fprintf(stdout, "--> SocketMessageTransport::" fmt, ##__VA_ARGS__); \
	fprintf(stdout, "\n"); \
	fflush(stdout);
#define DEBUG_LEAVE(fmt, ...) \
	fprintf(stdout, "<-- SocketMessageTransport::" fmt, ##__VA_ARGS__); \
	fprintf(stdout, "\n"); \
	fflush(stdout);
#define DEBUG_MSG(fmt, ...) \
	fprintf(stdout, "SocketMessageTransport:: " fmt, ##__VA_ARGS__); \
	fprintf(stdout, "\n"); \
	fflush(stdout);
#else
#define DEBUG_ENTER(fmt, ...)
#define DEBUG_LEAVE(fmt, ...)
#define DEBUG_MSG(fmt, ...)
#endif

namespace lls {

SocketMessageTransport::SocketMessageTransport(int32_t socket) :
	m_msgbuf(0), m_msg_state(0), m_msg_length(0),
	m_socket(socket), m_in(0) {
	// TODO Auto-generated constructor stub
	m_msgbuf_idx = 0;
	m_msgbuf_max = 1024;
	m_msgbuf = new char[m_msgbuf_max];
}

SocketMessageTransport::~SocketMessageTransport() {
	if (m_msgbuf) {
		delete [] m_msgbuf;
	}
}

void SocketMessageTransport::init(IMessageTransport *in) {
	m_in = in;
}

int32_t SocketMessageTransport::process(int timeout_ms) {
	char tmp[1024];
	int32_t sz;
	int32_t ret = 0;

	DEBUG_ENTER("process");

	// Poll for data

	while (true) {

		sz = ::recv(m_socket, tmp, 1024, 0);

		DEBUG_MSG("sz=%d", sz);

		if (sz <= 0) {
			DEBUG_MSG("sz=%d errno=%d", sz, errno);
			break;
		} else {
			ret = 1;
		}

		DEBUG_MSG("received %d bytes", sz);

		// Process data
		for (int32_t i=0; i<sz; i++) {
			switch (m_msg_state) {
			case 0: { // Waiting for a header
				if (tmp[i] == HEADER_PREFIX.at(m_msgbuf_idx)) {
					m_msgbuf_idx++;
				} else {
					m_msgbuf_idx = 0;
				}
				if (m_msgbuf_idx == HEADER_PREFIX.size()) {
					m_msgbuf_idx = 0;
					m_msg_state = 1;
				}
			} break;

			case 1: { // Collecting length up to first '\n'
				if (m_msgbuf_idx == 0 && isspace(tmp[i])) {
					// Skip leading whitespace
				} else {
					DEBUG_MSG("State 1: append %c", tmp[i]);
					msgbuf_append(tmp[i]);
					if (isspace(tmp[i])) {
						msgbuf_append(0);
						DEBUG_MSG("header=%s", m_msgbuf);
						m_msg_length = strtoul(m_msgbuf, 0, 10);
						DEBUG_MSG("len=%d", m_msg_length);
						// Reset the buffer to collect the payload
						m_msgbuf_idx = 0;
						m_msg_state = 2;
					}
				}

			} break;

			case 2: { // Collecting body data
				if (m_msgbuf_idx == 0 && isspace(tmp[i])) {
					// Skip leading whitespace
				} else {
					msgbuf_append(tmp[i]);
					if (m_msgbuf_idx >= m_msg_length) {
						msgbuf_append(0);
						DEBUG_MSG("Received message: \"%s\"", m_msgbuf);
						nlohmann::json msg;
						try {
							msg = nlohmann::json::parse(m_msgbuf);
							m_in->send(msg);
						} catch (const std::exception &e) {
							fprintf(stdout, "Failed to parse msg \"%s\" %s\n",
									m_msgbuf, e.what());
						}
						m_msg_state = 0;
						m_msgbuf_idx = 0;
					}
				}
			} break;

			default: {
				m_msgbuf_idx = 0;
				m_msg_state = 0;
			}
			}
		}
	}

	DEBUG_LEAVE("process %d", ret);
	return ret;
}

void SocketMessageTransport::send(const nlohmann::json &msg) {
	char tmp[64];
	std::string body = msg.dump();
	sprintf(tmp, "Content-Length: %d\r\n\r\n", body.size());

	::send(m_socket, tmp, strlen(tmp), 0);
	::send(m_socket, body.c_str(), body.size(), 0);
}

void SocketMessageTransport::msgbuf_resize_append(char c) {
	// Confirm that we need to resize
	if (m_msgbuf_idx+1 >= m_msgbuf_max) {
		// yup, must resize
		char *tmp = m_msgbuf;
		m_msgbuf = new char[m_msgbuf_max+1024];

		memcpy(m_msgbuf, tmp, m_msgbuf_idx);
		m_msgbuf_max += 1024;

		delete [] tmp;
	}

	m_msgbuf[m_msgbuf_idx++] = c;
}

const std::string	SocketMessageTransport::HEADER_PREFIX = "Content-Length: ";

}

