/*
 * IMessageTransport.h
 *
 *  Created on: Sep 21, 2020
 *      Author: ballance
 */

#pragma once
#include <string>

class IMessageTransport {
public:
	virtual ~IMessageTransport() { }

	virtual void send(const std::string &msg) = 0;

};
