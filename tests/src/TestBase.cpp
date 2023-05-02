/*
 * TestBase.cpp
 *
 * Copyright 2022 Matthew Ballance and Contributors
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may 
 * not use this file except in compliance with the License.  
 * You may obtain a copy of the License at:
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software 
 * distributed under the License is distributed on an "AS IS" BASIS, 
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  
 * See the License for the specific language governing permissions and 
 * limitations under the License.
 *
 * Created on:
 *     Author:
 */
#include "TestBase.h"
#include "dmgr/FactoryExt.h"
#include "lls/FactoryExt.h"
#include "jrpc/FactoryExt.h"
#include <netinet/in.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>


namespace lls {


TestBase::TestBase() {

}

TestBase::~TestBase() {

}

void TestBase::SetUp() {
    dmgr::IFactory *dmgr_f = dmgr_getFactory();
    jrpc::IFactory *jrpc_f = jrpc_getFactory();

    jrpc_f->init(dmgr_f->getDebugMgr());

    m_factory = lls_getFactory();
    m_factory->init(jrpc_f);

    enableDebug(false);

}

void TestBase::enableDebug(bool en) {
    m_factory->getDebugMgr()->enable(en);
}

std::pair<jrpc::IMessageTransportUP, jrpc::IMessageTransportUP> TestBase::mkTransportPair(
    jrpc::IEventLoop    *loop) {

    jrpc::IFactory *rpc_f = m_factory->getFactory();
    std::pair<int32_t, int32_t> srv_port_sock = rpc_f->mkSocketServer();

    int client_fd = rpc_f->mkSocketClientConnection(srv_port_sock.first);

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    addr.sin_port = 0; // pick any port

    // Now, wait for a readable event
    int addrlen = sizeof(addr);
    int server_sock = accept(srv_port_sock.second, 
        (struct sockaddr *)&addr, (socklen_t *)&addrlen); 

    return {
        jrpc::IMessageTransportUP(rpc_f->mkNBSocketMessageTransport(loop, server_sock)),
        jrpc::IMessageTransportUP(rpc_f->mkNBSocketMessageTransport(loop, client_fd))
    };
}

}
