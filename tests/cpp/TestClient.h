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

class TestClient : public lls::IMessageTransport {
public:
	TestClient(int32_t port);

	virtual ~TestClient();

	int32_t start_client(std::function<void(TestClient *)> client);

	int32_t close();

	virtual void send(const nlohmann::json &msg) override;

private:
	static void *thread_main(void *ud);

private:
	int32_t									m_port;
	int32_t									m_sock;
	pthread_t								m_thread;
	std::function<void(TestClient*)>		m_client;
	bool									m_close_on_complete;
};

