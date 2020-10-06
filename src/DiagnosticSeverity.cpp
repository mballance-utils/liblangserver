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
 * DiagnosticSeverity.cpp
 *
 *  Created on: Oct 5, 2020
 *      Author: ballance
 */

#include "DiagnosticSeverity.h"

namespace lls {

DiagnosticSeverity::DiagnosticSeverity(int64_t v) : ValInt(v) {
	// TODO Auto-generated constructor stub

}

DiagnosticSeverity::~DiagnosticSeverity() {
	// TODO Auto-generated destructor stub
}

const DiagnosticSeveritySP DiagnosticSeverity::Error =
		DiagnosticSeveritySP(new DiagnosticSeverity(1));
const DiagnosticSeveritySP DiagnosticSeverity::Warning =
		DiagnosticSeveritySP(new DiagnosticSeverity(2));
const DiagnosticSeveritySP DiagnosticSeverity::Information =
		DiagnosticSeveritySP(new DiagnosticSeverity(3));
const DiagnosticSeveritySP DiagnosticSeverity::Hint =
		DiagnosticSeveritySP(new DiagnosticSeverity(4));

} /* namespace lls */
