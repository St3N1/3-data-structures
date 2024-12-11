#include <07_project/production.hpp>

using namespace std;

template <typename SymbolType>
Production<SymbolType>::Production() = default;

template <typename SymbolType>
Production<SymbolType>::Production(const SymbolType& predecessor, const vector<SymbolType>& successor) : m_predecessor(predecessor), m_successor(successor){};

template <typename SymbolType>
bool Production<SymbolType>::operator==(const Production& other) const {
    return m_predecessor == other.getPredecessor() && m_successor == other.getSuccessor();
}

template <typename SymbolType>
SymbolType Production<SymbolType>::getPredecessor() const { return m_predecessor; }

template <typename SymbolType>
vector<SymbolType> Production<SymbolType>::getSuccessor() const { return m_successor; }

template class Production<const char*>;
