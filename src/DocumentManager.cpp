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
