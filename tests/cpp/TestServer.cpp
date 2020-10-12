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
 * TestServer.cpp
 *
 *  Created on: Sep 24, 2020
 *      Author: ballance
 */

#include "TestServer.h"
#include <stdio.h>
#ifndef _WIN32
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>
#include <pthread.h>
#else
#include <winsock2.h>
#include <ws2tcpip.h>
#endif
#include <string.h>

TestServer::TestServer() : m_serv_sock(-1) {
	// TODO Auto-generated constructor stub

}

TestServer::~TestServer() {
	// TODO Auto-generated destructor stub
}

int32_t TestServer::start() {
	struct sockaddr_in serv_addr;

	m_serv_sock = socket(AF_INET, SOCK_STREAM, 0);

	memset(&serv_addr, 0, sizeof(serv_addr));

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
	serv_addr.sin_port = 0;

	if ((bind(m_serv_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr))) < 0) {
		perror("Error binding");
	}

	socklen_t size = sizeof(serv_addr);
	getsockname(m_serv_sock, (struct sockaddr *) &serv_addr, &size);

	listen(m_serv_sock, 1);

	return serv_addr.sin_port;
}

int32_t TestServer::accept() {
	struct sockaddr_in serv_addr;

	int clilen = sizeof(serv_addr);
	int servfd = ::accept(m_serv_sock, (struct sockaddr *)&serv_addr, &clilen);

	fprintf(stdout, "connected\n");

	return servfd;
}

