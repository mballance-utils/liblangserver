/*
 * TestTypes.cpp
 *
 *  Created on: Oct 6, 2020
 *      Author: ballance
 */

#include "TestTypes.h"
#include "nlohmann/json.hpp"
#include "ValStr.h"
#include "ValVector.h"
#include "PublishDiagnosticsParams.h"

namespace lls {

TestTypes::TestTypes() {
	// TODO Auto-generated constructor stub

}

TestTypes::~TestTypes() {
	// TODO Auto-generated destructor stub
}

TEST_F(TestTypes, vector_1) {
	ValVector<ValStr>::SP val = ValVector<ValStr>::mk();
	val->push_back(ValStr::mk("hello"));

}

TEST_F(TestTypes, PublishDiagnosticsParams) {
	ValVector<Diagnostic>::SP diagnostics = ValVector<Diagnostic>::mk();
	diagnostics->push_back(Diagnostic::mk(
			Range::mk(
					Position::mk(ValInt::mk(0), ValInt::mk(0)),
					Position::mk(ValInt::mk(4), ValInt::mk(0))),
			ValStr::mk("Error")));
	PublishDiagnosticsParamsSP params = PublishDiagnosticsParams::mk(
			ValStr::mk("file://foo/bar"),
			diagnostics);

	fprintf(stdout, "params: %s\n", params->dump().dump().c_str());

}

} /* namespace lls */
