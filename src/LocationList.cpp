/*
 * LocationList.cpp
 *
 * Copyright 2023 Matthew Ballance and Contributors
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may 
 * not use this file except in compliance with the License.  
 * You may obtain a copy of the License at:
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software 
 * distributed under the License is distributed on an "AS IS" BASIS, 
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  
 * See the License for the specific language governing permissions and 
 * limitations under the License.
 *
 * Created on:
 *     Author:
 */
#include "LocationList.h"


namespace lls {


LocationList::LocationList(
    std::vector<ILocationUP>        &locations) {
    for (std::vector<ILocationUP>::iterator
        it=locations.begin();
        it!=locations.end(); it++) {
        m_locations.push_back(std::move(*it));
    }
}

LocationList::~LocationList() {

}

const nlohmann::json &LocationList::toJson() {
    m_json.clear();
    m_json = nlohmann::json::array();

    for (std::vector<ILocationUP>::const_iterator
        it=m_locations.begin();
        it!=m_locations.end(); it++) {
        m_json.push_back((*it)->toJson());
    }

    return m_json;
}

}
