/*
 * PublishDiagnosticsParams.h
 *
 *  Created on: Oct 5, 2020
 *      Author: ballance
 */

#pragma once
#include "Diagnostic.h"
#include "Val.h"
#include "ValStr.h"
#include "ValVector.h"

namespace lls {

class PublishDiagnosticsParams;
typedef std::shared_ptr<PublishDiagnosticsParams> PublishDiagnosticsParamsSP;
class PublishDiagnosticsParams : public Val {
public:
	PublishDiagnosticsParams(
			ValStrSP 					uri,
			ValVector<Diagnostic>::SP 	diagnostics);

	virtual ~PublishDiagnosticsParams();

	ValStrSP uri() const { return m_uri; }

	const ValVector<Diagnostic>::SP diagnostics() const {
		return m_diagnostics;
	}

private:
	ValStrSP					m_uri;
	ValVector<Diagnostic>::SP	m_diagnostics;


};

} /* namespace lls */

