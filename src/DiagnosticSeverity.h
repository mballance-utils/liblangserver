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
 * DiagnosticSeverity.h
 *
 *  Created on: Oct 5, 2020
 *      Author: ballance
 */

#pragma once
#include "ValInt.h"
#ifndef SRC_DIAGNOSTICSEVERITY_H_
#define SRC_DIAGNOSTICSEVERITY_H_

namespace lls {

class DiagnosticSeverity;
typedef std::shared_ptr<DiagnosticSeverity> DiagnosticSeveritySP;
class DiagnosticSeverity : public ValInt {
public:
	DiagnosticSeverity(int64_t v);

	virtual ~DiagnosticSeverity();
//
//	/**
//		 * Reports an error.
//		 */
//		export const Error: 1 = 1;
//		/**
//		 * Reports a warning.
//		 */
//		export const Warning: 2 = 2;
//		/**
//		 * Reports an information.
//		 */
//		export const Information: 3 = 3;
//		/**
//		 * Reports a hint.
//		 */
//		export const Hint: 4 = 4;

	static const DiagnosticSeveritySP		Error;
	static const DiagnosticSeveritySP		Warning;
	static const DiagnosticSeveritySP		Information;
	static const DiagnosticSeveritySP		Hint;


};

} /* namespace lls */

#endif /* SRC_DIAGNOSTICSEVERITY_H_ */
