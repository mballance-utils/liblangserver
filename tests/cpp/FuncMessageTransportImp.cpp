/*
 * FuncMessageTransportImp.cpp
 *
 *  Created on: Sep 24, 2020
 *      Author: ballance
 */

#include "FuncMessageTransportImp.h"
#include "nlohmann/json.hpp"

FuncMessageTransportImp::FuncMessageTransportImp(
		std::function<void(const nlohmann::json &)> recv) : m_recv(recv) {
	// TODO Auto-generated constructor stub

}

FuncMessageTransportImp::~FuncMessageTransportImp() {
	// TODO Auto-generated destructor stub
}

void FuncMessageTransportImp::send(const nlohmann::json &msg) {
	m_recv(msg);
}

