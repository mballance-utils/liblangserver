/**
 * Position.h
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
#include "lls/IPosition.h"
#include "Json.h"

namespace lls {



class Position :
    public virtual IPosition,
    public virtual Json {
public:
    Position(
        int32_t     line,
        int32_t     character);

    virtual ~Position();

    virtual int32_t getLine() override {
        return m_line;
    }

    virtual int32_t getCharacter() override {
        return m_character;
    }

    virtual const nlohmann::json &toJson() override;

    static IPositionUP mk(const nlohmann::json &m);

private:
    int32_t             m_line;
    int32_t             m_character;

};

}


