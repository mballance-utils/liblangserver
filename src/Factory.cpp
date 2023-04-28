/*
 * Factory.cpp
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
#include "Factory.h"
#include "lls/FactoryExt.h"
#include "ServerMessageDispatcher.h"

namespace lls {


Factory::Factory() : m_factory(0) {

}

Factory::~Factory() {

}

dmgr::IDebugMgr *Factory::getDebugMgr() {
    return m_factory->getDebugMgr();
}

IServerMessageDispatcher *Factory::mkNBServerMessageDispatcher(
        jrpc::IMessageTransport     *transport,
        IServer                     *server) {
    return new ServerMessageDispatcher(
        this, 
        m_factory->mkNBSocketServerMessageDispatcher(transport),
        server);
}

IFactory *Factory::inst() {
    if (!m_inst) {
        m_inst = std::unique_ptr<IFactory>(new Factory());
    }
    return m_inst.get();
}

std::unique_ptr<IFactory> Factory::m_inst;

}

lls::IFactory *lls_getFactory() {
    return lls::Factory::inst();
}
