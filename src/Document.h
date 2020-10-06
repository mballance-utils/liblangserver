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

