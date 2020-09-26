/*
 * TestServer.h
 *
 *  Created on: Sep 24, 2020
 *      Author: ballance
 */

#pragma once
#include <stdint.h>

class TestServer {
public:
	TestServer();

	virtual ~TestServer();

	/**
	 * Starts a server on loopback and returns the port
	 */
	int32_t start();

	/**
	 * Accepts a client connection, returning the socket
	 */
	int32_t accept();

private:
	int32_t			m_serv_sock;
};

