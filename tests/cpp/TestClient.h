/*
 * TestClient.h
 *
 *  Created on: Sep 24, 2020
 *      Author: ballance
 */

#pragma once
#include <stdint.h>
#include <functional>
#include <pthread.h>
#include "IMessageTransport.h"

class TestClient : public IMessageTransport {
public:
	TestClient(int32_t port);

	virtual ~TestClient();

	int32_t start_client(std::function<void(TestClient *)> client);

	int32_t close();

	virtual void send(const std::string &msg) override;

private:
	static void *thread_main(void *ud);

private:
	int32_t									m_port;
	int32_t									m_sock;
	pthread_t								m_thread;
	std::function<void(TestClient*)>		m_client;
	bool									m_close_on_complete;
};

