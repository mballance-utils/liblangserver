/*
 * SocketMessageTransport.cpp
 *
 *  Created on: Sep 21, 2020
 *      Author: ballance
 */

#include "SocketMessageTransport.h"
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>

SocketMessageTransport::SocketMessageTransport(int32_t socket) :
	m_msgbuf(0), m_msg_state(0), m_msg_length(0),
	m_socket(socket), m_in(0) {
	// TODO Auto-generated constructor stub
	m_msgbuf_sz = 0;
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

	// Poll for data
	while (true) {
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
				msgbuf_append(tmp[i]);
				if (tmp[i] == '\n') {
					m_msg_state = 2;
				}
			} break;

			case 2: { // Collecting length up to second '\n'
				msgbuf_append(tmp[i]);
				if (tmp[i] == '\n') {
					// TODO: length of packet
					m_msg_state = 3;
					m_msgbuf_idx = 0;
				}
			} break;

			case 3: { // Collecting body data

			} break;
			default: {
				m_msgbuf_idx = 0;
				m_msg_state = 0;
			}
	}

	return 0;
}

void SocketMessageTransport::send(const std::string &msg) {
	std::string msg_wrapper = "Content-Length: " + msg;

	const char *data = msg_wrapper.c_str();
	::send(m_socket, data, strlen(data), 0);

}

const std::string	SocketMessageTransport::HEADER_PREFIX = "Content-Length: ";

