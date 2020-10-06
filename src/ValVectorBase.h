/**
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */
/*
 * ValVector.h
 *
 *  Created on: Oct 1, 2020
 *      Author: ballance
 */

#pragma once
#include <functional>
#include "Val.h"

namespace lls {

class ValVectorBase;
typedef std::shared_ptr<ValVectorBase> ValVectorBaseSP;
class ValVectorBase : public Val {
public:
	ValVectorBase();

	ValVectorBase(
			std::function<ValSP(const nlohmann::json &)> 	ctor,
			const nlohmann::json 							&msg);

	virtual ~ValVectorBase();

	const std::vector<ValSP> &children() const {
		return m_children;
	}

	ValSP children(uint32_t idx) const {
		return m_children.at(idx);
	}

	virtual nlohmann::json dump();

	static ValVectorBaseSP mk(
			std::function<ValSP(const nlohmann::json &)> 	ctor,
			const nlohmann::json 							&msg);

private:
	std::vector<ValSP>				m_children;

};


} /* namespace lls */

