/*
 * TestInitialize.cpp
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
#include "TestInitialize.h"
#include "lls/impl/ServerBase.h"


namespace lls {


TestInitialize::TestInitialize() {

}

TestInitialize::~TestInitialize() {

}

TEST_F(TestInitialize, smoke) {
    enableDebug(false);

    class Initializer;
    using InitializerUP=std::unique_ptr<Initializer>;
    class Initializer : public ServerBase {
    public:
        bool initialize_invoked = false;

        Initializer(
            jrpc::IEventLoop        *loop,
            IFactory                *factory) : ServerBase(loop, factory) { }

        virtual ~Initializer() { }

	    virtual IInitializeResultUP initialize(IInitializeParamsUP &params) override {
            auto check = [&] {
                ASSERT_TRUE(params.get());
            };
            check();
            initialize_invoked = true;

            IServerCapabilitiesUP capabilities(m_factory->mkServerCapabilities());
            IServerInfoUP serverInfo;
            return IInitializeResultUP(m_factory->mkInitializeResult(capabilities, serverInfo));
        }
    };

    jrpc::IEventLoopUP loop(m_factory->getFactory()->mkEventLoop());

    // TODO: Setup a server+client
    std::pair<jrpc::IMessageTransportUP,jrpc::IMessageTransportUP> srv_client =
        mkTransportPair(loop.get());

    // Create a ClientMessageDispatcher
    IClientMessageDispatcherUP client_d(m_factory->mkClientMessageDispatcher(
        srv_client.second.get(),
        0 // No client listener provided
    ));

    InitializerUP server(new Initializer(loop.get(), m_factory));
    IServerMessageDispatcherUP server_d(m_factory->mkNBServerMessageDispatcher(
        srv_client.first.get(),
        server.get()
    ));

    IInitializeParamsUP initialize_params(m_factory->mkInitializeParams(
        1000,
        0,
        "",
        "/my/path",
        "docUri",
        {}
    ));

    client_d->initialize(initialize_params);

    ASSERT_TRUE(server->initialize_invoked);

    
//    m_factory->mk

    // struct params {
    //     list<unique bar>          h_list;
    //     list<component : bar>     t_list;
    //     action : base             T;
    // }
    //
    // Need similar capability for forming element equality
    //
    // *d_out == (d_type){
    //   .a == 5;
    //   .* == *d_in.*;
    // };
    //
    // my_t<(p_type){.WIDTH=10, .*=upper_params.*}
    //
    //

    // Create a ServerMessageDispatcher
    // Uses ServerBase
}

}
