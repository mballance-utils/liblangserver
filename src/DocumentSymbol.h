/**
 * DocumentSymbol.h
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
#include "lls/IDocumentSymbol.h"
#include "Json.h"

namespace lls {


class DocumentSymbol :
    public virtual IDocumentSymbol,
    public virtual Json {
public:
    DocumentSymbol(
        const std::string           &name,
        SymbolKind                  kind,
        IRangeUP                    &range,
        IRangeUP                    &selectionRange);

    virtual ~DocumentSymbol();

    virtual const std::string &getName() override {
        return m_name;
    }

    virtual SymbolKind getKind() override {
        return m_kind;
    }

    virtual IRange *getRange() override {
        return m_range.get();
    }

    virtual IRange *getSelectionRange() override {
        return m_selectionRange.get();
    }

    virtual void addChild(IDocumentSymbolUP &c) override {
        m_children.push_back(std::move(c));
    }

    virtual std::vector<IDocumentSymbolUP> &getChildren() override {
        return m_children;
    }

    virtual const nlohmann::json &toJson() override;

private:
    std::string                         m_name;
    SymbolKind                          m_kind;
    IRangeUP                            m_range;
    IRangeUP                            m_selectionRange;
    std::vector<IDocumentSymbolUP>      m_children;

};

}


