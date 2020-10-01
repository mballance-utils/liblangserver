/*
 * ReqInitialize.h
 *
 *  Created on: Sep 27, 2020
 *      Author: ballance
 */

#pragma once
#include "nlohmann/json.hpp"

namespace lls {

class ReqInitialize {
public:
	ReqInitialize();

	virtual ~ReqInitialize();

	double			version;
	uint32_t		id;
	std::string		method;

};

/*
void to_json(nlohmann::json &h, const ReqInitialize &ri) {
	j = nlohmann::json{
		{"id">)
	}
}
 */

} /* namespace lls */

