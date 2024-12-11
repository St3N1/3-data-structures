#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#ifndef PRODUCTION_H
#define PRODUCTION_H

// This class represents a single production.
// A production is a replacement rule, it tells us which symbol
// to look for, and what (sequence of) symbol(s) to replace it with.
// The original symbol is usually called a “predecessor”.
// The (sequence of) symbol(s) is usually called a “successor”.
template <typename SymbolType>
class Production {
   public:
    Production();
    Production(const SymbolType& predecessor, const std::vector<SymbolType>& successor);

    bool operator==(const Production& other) const;

    SymbolType getPredecessor() const;
    std::vector<SymbolType> getSuccessor() const;

   private:
    SymbolType m_predecessor;
    std::vector<SymbolType> m_successor;
};

#endif
