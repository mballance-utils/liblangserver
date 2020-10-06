/*
 * DiagnosticSeverity.h
 *
 *  Created on: Oct 5, 2020
 *      Author: ballance
 */

#pragma once
#include "ValInt.h"
#ifndef SRC_DIAGNOSTICSEVERITY_H_
#define SRC_DIAGNOSTICSEVERITY_H_

namespace lls {

class DiagnosticSeverity;
typedef std::shared_ptr<DiagnosticSeverity> DiagnosticSeveritySP;
class DiagnosticSeverity : public ValInt {
public:
	DiagnosticSeverity(int64_t v);

	virtual ~DiagnosticSeverity();
//
//	/**
//		 * Reports an error.
//		 */
//		export const Error: 1 = 1;
//		/**
//		 * Reports a warning.
//		 */
//		export const Warning: 2 = 2;
//		/**
//		 * Reports an information.
//		 */
//		export const Information: 3 = 3;
//		/**
//		 * Reports a hint.
//		 */
//		export const Hint: 4 = 4;

	static const DiagnosticSeveritySP		Error;
	static const DiagnosticSeveritySP		Warning;
	static const DiagnosticSeveritySP		Information;
	static const DiagnosticSeveritySP		Hint;


};

} /* namespace lls */

#endif /* SRC_DIAGNOSTICSEVERITY_H_ */
