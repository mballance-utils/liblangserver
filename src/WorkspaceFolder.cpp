/*
 * WorkspaceFolder.cpp
 *
 *  Created on: Oct 1, 2020
 *      Author: ballance
 */

#include "WorkspaceFolder.h"
#include "nlohmann/json.hpp"

namespace lls {

WorkspaceFolder::WorkspaceFolder(const nlohmann::json &msg) {
	// TODO Auto-generated constructor stub

}

WorkspaceFolder::~WorkspaceFolder() {
	// TODO Auto-generated destructor stub
}

nlohmann::json WorkspaceFolder::dump() {
	;
}

WorkspaceFolderSP WorkspaceFolder::mk(const nlohmann::json &msg) {
	return WorkspaceFolderSP(new WorkspaceFolder(msg));
}

} /* namespace lls */
