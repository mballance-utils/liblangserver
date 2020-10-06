/*
 * PublishDiagnosticsParams.cpp
 *
 *  Created on: Oct 5, 2020
 *      Author: ballance
 */

#include "PublishDiagnosticsParams.h"

namespace lls {

PublishDiagnosticsParams::PublishDiagnosticsParams(
		ValStrSP					uri,
		ValVector<Diagnostic>::SP	diagnostics) :
				m_uri(uri), m_diagnostics(diagnostics) {

}

PublishDiagnosticsParams::~PublishDiagnosticsParams() {
	// TODO Auto-generated destructor stub
}

} /* namespace lls */
