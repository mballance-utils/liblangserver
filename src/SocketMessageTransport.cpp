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
#include <sys/socket.h>

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

	// Poll for data

	while (true) {

		sz = ::recv(m_socket, tmp, 1024, 0);

		fprintf(stdout, "sz=%d\n", sz);

		if (sz <= 0) {
			fprintf(stdout, "sz=%d errno=%d\n", sz, errno);
			break;
		} else {
			ret = 1;
		}

		fprintf(stdout, "received %d bytes\n", sz);

		// Process data
		for (uint32_t i=0; i<sz; i++) {
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
					fprintf(stdout, "State 1: append %c\n", tmp[i]);
					msgbuf_append(tmp[i]);
					if (isspace(tmp[i])) {
						msgbuf_append(0);
						fprintf(stdout, "header=%s\n", m_msgbuf);
						m_msg_length = strtoul(m_msgbuf, 0, 10);
						fprintf(stdout, "len=%d\n", m_msg_length);
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
						fprintf(stdout, "Received message: %s\n", m_msgbuf);
						m_in->send(m_msgbuf);
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

	fprintf(stdout, "return ret=%d\n", ret);
	return ret;
}

void SocketMessageTransport::send(const std::string &msg) {
	char tmp[64];
	sprintf(tmp, "Content-Length: %d\r\n\r\n", msg.size());

	::send(m_socket, tmp, strlen(tmp), 0);
	::send(m_socket, msg.c_str(), msg.size(), 0);

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

