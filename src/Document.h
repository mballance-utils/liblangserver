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
 * Document.h
 *
 *  Created on: Oct 6, 2020
 *      Author: ballance
 */

#pragma once
#include <memory>
#include <string>

namespace lls {

class Document;
typedef std::shared_ptr<Document> DocumentSP;
class Document {
public:
	Document(
			const std::string &uri,
			const std::string &content);

	virtual ~Document();

	const std::string &content() const {
		return m_content;
	}

	void content(const std::string &v) {
		m_content = v;
	}

private:
	std::string					m_uri;
	std::string					m_content;
};

} /* namespace lls */

