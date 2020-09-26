/*
 * TestSocketMessageTransport.cpp
 *
 *  Created on: Sep 23, 2020
 *      Author: ballance
 */
#include <string>
#include <vector>

#include <pthread.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>

#include "FuncMessageTransportImp.h"
#include "TestSocketMessageTransport.h"
#include "SocketMessageTransport.h"
#include <fcntl.h>

#include "TestServer.h"
#include "TestClient.h"

TestSocketMessageTransport::TestSocketMessageTransport() {
	// TODO Auto-generated constructor stub

}

TestSocketMessageTransport::~TestSocketMessageTransport() {
	// TODO Auto-generated destructor stub
}

TEST_F(TestSocketMessageTransport, smoke) {
	TestServer server;

	int32_t port = server.start();

	TestClient client(port);


	// Client runs asynchronously
	ASSERT_EQ(client.start_client([&] (TestClient *t) {
		t->send(R"({"jsonrpc":"2.0","id":"1","method":"initialize","params":{"processId":null,"rootUri":null}})");
	}), 0);

	// Client must be running before we accept a connection
	int32_t srv_fd = server.accept();

//	if(fcntl(srv_fd, F_GETFL) & O_NONBLOCK) {
//	    // socket is non-blocking
//	}
//
//	// Put the socket in non-blocking mode:
//	if(fcntl(srv_fd, F_SETFL, fcntl(srv_fd, F_GETFL) | O_NONBLOCK) < 0) {
//	    // handle error
//	}

	SocketMessageTransport transport(srv_fd);

	std::vector<std::string> msgs;
	FuncMessageTransportImp msg_recv([&](const std::string &msg) {
		msgs.push_back(msg);
	});
	transport.init(&msg_recv);

	while (transport.process(0)) {
		//
	}

	ASSERT_EQ(msgs.size(), 1);

	ASSERT_EQ(client.close(), 0);

//	pthread_t thread;
//	client_data cd;
//	struct sockaddr_in serv_addr;
//
//	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
//
//	cd.input.push_back(R"(Content-Length: 91
//
//{"jsonrpc":"2.0","id":"1","method":"initialize","params":{"processId":null,"rootUri":null}})");
//
//	memset(&serv_addr, 0, sizeof(serv_addr));
//
//	serv_addr.sin_family = AF_INET;
//	serv_addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
//	serv_addr.sin_port = 0;
//
//	if ((bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr))) < 0) {
//		perror("Error binding");
//	}
//
//	socklen_t size = sizeof(serv_addr);
//	getsockname(sockfd, (struct sockaddr *) &serv_addr, &size);
//
//	fprintf(stdout, "port: %d\n", serv_addr.sin_port);
//	fflush(stdout);
//	cd.port = serv_addr.sin_port;
//	ASSERT_EQ(pthread_create(&thread, 0, &client_f, &cd), 0);
//
//	listen(sockfd, 1);
//
//	unsigned int clilen = sizeof(serv_addr);
//	int servfd = accept(sockfd, (struct sockaddr *)&serv_addr, &clilen);
//
//	fprintf(stdout, "connected\n");
//
//	char buf[1024];
//
//	int len = ::recv(servfd, buf, sizeof(buf), 0);
//
//	fprintf(stdout, "Recv %d\n", len);
//
//
//	pthread_join(thread, 0);
}

