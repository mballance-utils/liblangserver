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
 * DocumentManager.cpp
 *
 *  Created on: Oct 6, 2020
 *      Author: ballance
 */

#include "DocumentManager.h"

namespace lls {

DocumentManager::DocumentManager() {

}

DocumentManager::~DocumentManager() {
	// TODO Auto-generated destructor stub
}

DocumentSP DocumentManager::openDocument(
		const std::string			&uri,
		const std::string			&content) {
	std::map<std::string,DocumentSP>::iterator it;

	if ((it=m_docmap.find(uri)) == m_docmap.end()) {
		it = m_docmap.insert({uri, DocumentSP(new Document(uri, content))}).first;
	} else {
		it->second->content(content);
	}

	return it->second;
}

DocumentSP DocumentManager::getDocument(
			const std::string	&uri) {
	std::map<std::string,DocumentSP>::iterator it;

	if ((it=m_docmap.find(uri)) != m_docmap.end()) {
		return it->second;
	} else {
		return 0;
	}
}

void DocumentManager::closeDocument(
			const std::string	&uri) {
	std::map<std::string,DocumentSP>::iterator it;

	if ((it=m_docmap.find(uri)) != m_docmap.end()) {
		m_docmap.erase(it);
	}
}

} /* namespace lls */
