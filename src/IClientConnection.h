/*
 * IClientNotification.h
 *
 *  Created on: Oct 5, 2020
 *      Author: ballance
 */

#pragma once
#include "PublishDiagnosticsParams.h"

namespace lls {

/**
 * Interface used by the server implementation to publish information to the client
 */
class IClientConnection {
public:

	virtual ~IClientConnection() { }

	virtual void publishDiagnostics(PublishDiagnosticsParamsSP params) = 0;
};

}

