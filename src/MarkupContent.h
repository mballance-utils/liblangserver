/**
 * MarkupContent.h
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
#pragma once
#include "lls/IMarkupContent.h"
#include "Json.h"

namespace lls {



class MarkupContent :
    public virtual IMarkupContent,
    public virtual Json {
public:
    MarkupContent(
        MarkupKind          kind,
        const std::string   &value);

    virtual ~MarkupContent();

    virtual MarkupKind getKind() override {
        return m_kind;
    }

    virtual const std::string &getValue() override {
        return m_value;
    }

    virtual const nlohmann::json &toJson() override;

private:
    MarkupKind              m_kind;
    std::string             m_value;
};

}


