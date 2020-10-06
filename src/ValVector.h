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
#include "ValVectorBase.h"

namespace lls {

template <class T> class ValVector : public ValVectorBase {
public:
	typedef std::shared_ptr<ValVector<T>> SP;
public:

	ValVector() { }

	const std::vector<std::shared_ptr<T>> &children() const {
		return std::dynamic_pointer_cast<std::vector<std::shared_ptr<T>>>(
				ValVectorBase::children());
	}

	std::shared_ptr<T> children(uint32_t idx) const {
		return std::dynamic_pointer_cast<std::shared_ptr<T>>(
				ValVectorBase::children(idx));
	}

	static SP mk(const nlohmann::json &msg) {
		return std::dynamic_pointer_cast<ValVector<T>>(
				ValVectorBase::mk(
						[&](const nlohmann::json &sm) {
							return ValSP(new T(sm));
						}, msg));
	}

};

}

