/*
 * IMessageTransport.h
 *
 *  Created on: Sep 21, 2020
 *      Author: ballance
 */

#pragma once
#include <string>
#include "nlohmann/json_fwd.hpp"

namespace lls {

class IMessageTransport {
public:
	virtual ~IMessageTransport() { }

	virtual void send(const nlohmann::json &msg) = 0;

};

}

