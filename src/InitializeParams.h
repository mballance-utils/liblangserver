/*
 * InitializeParams.h
 *
 *  Created on: Sep 30, 2020
 *      Author: ballance
 */

#pragma once
#include "ClientInfo.h"
#include "ValStr.h"
#include "ValVector.h"
#include "WorkDoneProgressParams.h"
#include "WorkspaceFolder.h"

namespace lls {

class InitializeParams;
typedef std::shared_ptr<InitializeParams> InitializeParamsSP;

class InitializeParams : public WorkDoneProgressParams {
public:
	InitializeParams(const nlohmann::json &msg);

	virtual ~InitializeParams();

	ClientInfoSP clientInfo() const { return m_clientInfo; }

	ValStrSP rootPath() const { return m_rootPath; }

	ValStrSP rootUri() const { return m_rootUri; }

	static InitializeParamsSP mk(const nlohmann::json &msg);

private:
	ClientInfoSP					m_clientInfo;
	ValStrSP						m_rootPath;
	ValStrSP						m_rootUri;
	ValStrSP						m_trace;
	ValVector<WorkspaceFolder>::SP	m_workspaceFolders;


};

} /* namespace lls */

