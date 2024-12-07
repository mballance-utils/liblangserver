/**
 * ServerMessageDispatcher.h
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
#pragma once
#include "dmgr/IDebugMgr.h"
#include "lls/IFactory.h"
#include "lls/IMessageDispatcher.h"
#include "lls/IServer.h"
#include "lls/IServerMessageDispatcher.h"

namespace lls {



class ServerMessageDispatcher : public virtual IServerMessageDispatcher {
public:
    ServerMessageDispatcher(
        IFactory                    *factory,
        jrpc::IMessageDispatcher    *dispatch,
        IServer                     *server
    );

    virtual ~ServerMessageDispatcher();

    // Client API implementation

    virtual void publishDiagnosticsNotification(
        IPublishDiagnosticsParamsUP         &params) override;

    virtual void sendNotification(
        const std::string               &method,
        IJson                           *params) override;

    virtual void sendRspSuccess(
        const std::string               &id,
        IJson                           *result) override;

    virtual void sendRspError(
        const std::string               &id,
        int32_t                         code,
        const std::string               &msg,
        IJson                           *data) override;

private:
    void initializeRequest(jrpc::IReqMsgUP &msg);

    void initializedRequest(jrpc::IReqMsgUP &msg);

    void didOpenNotification(jrpc::IReqMsgUP &msg);

    void didChangeNotification(jrpc::IReqMsgUP &msg);

    void didSaveNotification(jrpc::IReqMsgUP &msg);

    void didCloseNotification(jrpc::IReqMsgUP &msg);

    void declaration(jrpc::IReqMsgUP &msg);

    void definition(jrpc::IReqMsgUP &msg);
    
    void documentSymbolRequest(jrpc::IReqMsgUP &msg);

    void hoverRequest(jrpc::IReqMsgUP &msg);

    void shutdown(jrpc::IReqMsgUP &msg);

    void exit(jrpc::IReqMsgUP &msg);

private:
    static dmgr::IDebug             *m_dbg;
    IFactory                        *m_factory;
    jrpc::IMessageDispatcher        *m_dispatch;
    IServer                         *m_server;

};

}


