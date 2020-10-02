/*
 * TestClient.cpp
 *
 *  Created on: Sep 24, 2020
 *      Author: ballance
 */

#include "TestClient.h"
#include <pthread.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include "nlohmann/json.hpp"

TestClient::TestClient(int32_t port) :
	m_port(port), m_sock(-1), m_close_on_complete(true) {
	// TODO Auto-generated constructor stub

}

TestClient::~TestClient() {
	// TODO Auto-generated destructor stub
}

int32_t TestClient::start_client(std::function<void (TestClient*)> client) {
	m_client = client;

	// First, connect to the socket
	struct sockaddr_in serv_addr;

	m_sock = socket(AF_INET, SOCK_STREAM, 0);

	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
	serv_addr.sin_port = m_port;

	if (connect(m_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
		perror("connect failure");
		return -1;
	}
	fprintf(stdout, "connected %d\n", m_sock);
	fflush(stdout);

	if (pthread_create(&m_thread, 0, &TestClient::thread_main, this) != 0) {
		return -1;
	}

	return 0;
}

int32_t TestClient::close() {
	pthread_join(m_thread, 0);

	if (m_sock != -1) {
		::close(m_sock);
	}

	return 0;
}

void TestClient::send(const nlohmann::json &msg) {
	char header[128];

	std::string body = msg.dump();
	fprintf(stdout, "body=%s sz=%d\n", body.c_str(), body.size());
	int len = sprintf(header, "Content-Length: %d\r\n\r\n", body.size());

	int ret = ::send(m_sock, header, len, 0);
	ret = ::send(m_sock, body.c_str(), body.size(), 0);
}

void *TestClient::thread_main(void *ud) {
	TestClient *t = static_cast<TestClient *>(ud);
	t->m_client(t);

	if (t->m_close_on_complete) {
		::close(t->m_sock);
		t->m_sock = -1;
	}
	return 0;
}

