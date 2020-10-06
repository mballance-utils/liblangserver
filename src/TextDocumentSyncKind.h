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
 * TextDocumentSyncKind.h
 *
 *  Created on: Oct 3, 2020
 *      Author: ballance
 */

#pragma once
#include "ValInt.h"

namespace lls {

class TextDocumentSyncKind;
typedef std::shared_ptr<TextDocumentSyncKind> TextDocumentSyncKindSP;
class TextDocumentSyncKind : public ValInt {
public:
	TextDocumentSyncKind(int64_t v);

	TextDocumentSyncKind(const nlohmann::json &msg);

	virtual ~TextDocumentSyncKind();

	static TextDocumentSyncKindSP mk(const nlohmann::json &msg);

	static const TextDocumentSyncKindSP	None;
	static const TextDocumentSyncKindSP	Full;
	static const TextDocumentSyncKindSP	Incremental;

};

} /* namespace lls */

