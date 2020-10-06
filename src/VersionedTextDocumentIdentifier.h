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
 * VersionedTextDocumentIdentifier.h
 *
 *  Created on: Oct 5, 2020
 *      Author: ballance
 */

#pragma once
#include "Val.h"
#include "ValInt.h"
#include "TextDocumentIdentifier.h"

namespace lls {

class VersionedTextDocumentIdentifier;
typedef std::shared_ptr<VersionedTextDocumentIdentifier> VersionedTextDocumentIdentifierSP;
class VersionedTextDocumentIdentifier : public TextDocumentIdentifier {
public:
	VersionedTextDocumentIdentifier(const nlohmann::json &msg);

	virtual ~VersionedTextDocumentIdentifier();

	ValIntSP version() const { return m_version; }

	void version(ValIntSP v) { m_version = v; }

	static VersionedTextDocumentIdentifierSP mk(const nlohmann::json &msg);

private:
	ValIntSP			m_version;
};

} /* namespace lls */

