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
 * TextDocumentItem.cpp
 *
 *  Created on: Oct 5, 2020
 *      Author: ballance
 */

#include "TextDocumentItem.h"
#include "nlohmann/json.hpp"

namespace lls {

TextDocumentItem::TextDocumentItem(const nlohmann::json &msg) {
	m_uri = ValStr::mk(msg["uri"]);
	m_languageId = ValStr::mk(msg["languageId"]);
	m_version = ValInt::mk(msg["version"]);
	m_text = ValStr::mk(msg["text"]);
}

TextDocumentItem::~TextDocumentItem() {
	// TODO Auto-generated destructor stub
}

TextDocumentItemSP TextDocumentItem::mk(const nlohmann::json &msg) {
	return TextDocumentItemSP(new TextDocumentItem(msg));
}

} /* namespace lls */
