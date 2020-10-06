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
 * testlangserver_main.cpp
 *
 *  Created on: Oct 3, 2020
 *      Author: ballance
 */

#include "LangServerMethodHandler.h"
#include "MessageDispatcher.h"
#include "SocketMessageTransport.h"
#include "TestLangServer.h"
#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

int main(int argc, char **argv) {
	int32_t port = -1;
	int32_t sock;

	for (uint32_t i=1; i<argc; i++) {
		if (argv[i][0] == '-') {
			if (!strcmp(argv[i], "-port")) {
				i++;
				port = atoi(argv[i]);
			} else {
				fprintf(stdout, "Error: unknown option %s\n", argv[i]);
				exit(1);
			}
		} else {
			fprintf(stdout, "Error: unknown argument %s\n", argv[i]);
			exit(1);
		}
	}

	if (port == -1) {
		fprintf(stdout, "no port specified\n");
		exit(1);
	}

	fprintf(stdout, "Hello from langserver port=%d\n", port);
	fflush(stdout);

	// First, connect to the socket
	struct sockaddr_in serv_addr;

	sock = socket(AF_INET, SOCK_STREAM, 0);

	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
	serv_addr.sin_port = htons(port);

	fprintf(stdout, "--> langserver connecting...\n");
	fflush(stdout);
	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
		perror("connect failure");
		exit(1);
	}
	fprintf(stdout, "connected %d\n", sock);
	fflush(stdout);

	TestLangServer server;

	lls::MessageDispatcher dispatcher;
	lls::SocketMessageTransport transport(sock);

	transport.init(&dispatcher);

	lls::LangServerMethodHandler lsp_method_handler(
			&transport,
			&server);

	lsp_method_handler.register_methods(&dispatcher);

	while (transport.process(0)) {
		//
	}

	exit(0);
}


