/*
 * WorkspaceFolder.h
 *
 *  Created on: Oct 1, 2020
 *      Author: ballance
 */

#pragma once
#include "Val.h"
#include "ValStr.h"

namespace lls {

class WorkspaceFolder;
typedef std::shared_ptr<WorkspaceFolder> WorkspaceFolderSP;

class WorkspaceFolder : public Val {
public:
	WorkspaceFolder(const nlohmann::json &msg);

	virtual ~WorkspaceFolder();

	ValStrSP uri() const { return m_uri; }

	ValStrSP name() const { return m_name; }

	virtual nlohmann::json dump();

	static WorkspaceFolderSP mk(const nlohmann::json &msg);

private:

	ValStrSP			m_uri;
	ValStrSP			m_name;

};

} /* namespace lls */

