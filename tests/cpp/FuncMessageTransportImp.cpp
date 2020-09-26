/*
 * FuncMessageTransportImp.cpp
 *
 *  Created on: Sep 24, 2020
 *      Author: ballance
 */

#include "FuncMessageTransportImp.h"

FuncMessageTransportImp::FuncMessageTransportImp(
		std::function<void(const std::string &)> recv) : m_recv(recv) {
	// TODO Auto-generated constructor stub

}

FuncMessageTransportImp::~FuncMessageTransportImp() {
	// TODO Auto-generated destructor stub
}

void FuncMessageTransportImp::send(const std::string &msg) {
	m_recv(msg);
}

