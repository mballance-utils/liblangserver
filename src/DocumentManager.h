/*
 * DocumentManager.h
 *
 *  Created on: Oct 6, 2020
 *      Author: ballance
 */

#pragma once
#include <map>
#include "Document.h"

namespace lls {

class DocumentManager {
public:
	DocumentManager();

	virtual ~DocumentManager();

	DocumentSP openDocument(
			const std::string	&uri,
			const std::string	&content);

	DocumentSP getDocument(
			const std::string	&uri);

	void closeDocument(
			const std::string	&uri);

private:
	std::map<std::string, DocumentSP>	m_docmap;

};

} /* namespace lls */

