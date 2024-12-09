#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#ifndef PRODUCTION_H
#define PRODUCTION_H

using namespace std;

// This class represents a single production.
// A production is a replacement rule, it tells us which symbol
// to look for, and what (sequence of) symbol(s) to replace it with.
// The original symbol is usually called a “predecessor”.
// The (sequence of) symbol(s) is usually called a “successor”.
template <typename SymbolType>
class Production {
   public:
    Production() = default;

    // Production(const SymbolType& predecessor, const SymbolType& successor) : m_predecessor(predecessor), m_successor(successor) {};
    Production(const SymbolType& predecessor, const SymbolType& successor) : m_predecessor(predecessor) {
        char a[strlen(successor)];
        strncpy(a, successor, strlen(successor));

        for (size_t i = 0; i < strlen(successor); i++) {
            // FIXME
            // BUG

            cout << successor[i] << endl;
            // SymbolType temp(1, successor[i]);
            // SymbolType a = temp.at(i);
            // SymbolType ptr = &successor[i];
            // m_successor.push_back(a);
        }
    };

    bool operator==(const Production& other) const {
        return m_predecessor == other.getPredecessor() && m_successor == other.getSuccessor();
    }

    SymbolType getPredecessor() const { return m_predecessor; }
    vector<SymbolType> getSuccessor() const { return m_successor; }

   private:
    SymbolType m_predecessor;
    vector<SymbolType> m_successor;
};

#endif
