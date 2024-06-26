/**
 * Hover.h
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
#include "lls/IHover.h"
#include "Json.h"

namespace lls {



class Hover :
    public virtual IHover,
    public virtual Json {
public:
    Hover(
        IJsonUP         &contents,
        IRangeUP        &range
    );

    virtual ~Hover();

    virtual IJson *getContents() override {
        return m_contents.get();
    }

    virtual IRange *getRange() override {
        return m_range.get();
    }

    virtual const nlohmann::json &toJson() override;

    static IHoverUP mk(const nlohmann::json &m);

private:
    IJsonUP                 m_contents;
    IRangeUP                m_range;
};

}


