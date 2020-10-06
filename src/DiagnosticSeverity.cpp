/*
 * DiagnosticSeverity.cpp
 *
 *  Created on: Oct 5, 2020
 *      Author: ballance
 */

#include "DiagnosticSeverity.h"

namespace lls {

DiagnosticSeverity::DiagnosticSeverity(int64_t v) : ValInt(v) {
	// TODO Auto-generated constructor stub

}

DiagnosticSeverity::~DiagnosticSeverity() {
	// TODO Auto-generated destructor stub
}

const DiagnosticSeveritySP DiagnosticSeverity::Error =
		DiagnosticSeveritySP(new DiagnosticSeverity(1));
const DiagnosticSeveritySP DiagnosticSeverity::Warning =
		DiagnosticSeveritySP(new DiagnosticSeverity(2));
const DiagnosticSeveritySP DiagnosticSeverity::Information =
		DiagnosticSeveritySP(new DiagnosticSeverity(3));
const DiagnosticSeveritySP DiagnosticSeverity::Hint =
		DiagnosticSeveritySP(new DiagnosticSeverity(4));

} /* namespace lls */
