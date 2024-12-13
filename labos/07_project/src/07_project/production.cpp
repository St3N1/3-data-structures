#include <07_project/production.hpp>

using namespace std;

// Production default
template <typename SymbolType>
Production<SymbolType>::Production() = default;

// Production
template <typename SymbolType>
Production<SymbolType>::Production(const SymbolType& predecessor, const SymbolType& successor) : m_predecessor(predecessor), m_successor(successor){};

// Operator
template <typename SymbolType>
bool Production<SymbolType>::operator==(const Production& other) const {
    return m_predecessor == other.getPredecessor() && m_successor == other.getSuccessor();
}

// GetPredecessor
template <typename SymbolType>
SymbolType Production<SymbolType>::getPredecessor() const { return m_predecessor; }

// GetSuccessor
template <typename SymbolType>
SymbolType Production<SymbolType>::getSuccessor() const { return m_successor; }

template class Production<string>;
