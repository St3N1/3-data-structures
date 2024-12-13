#include <07_project/production_hash.hpp>

using namespace std;

// Operator
template <typename SymbolType>
size_t hash<Production<SymbolType>>::operator()(const Production<SymbolType>& production) const {
    size_t hash1 = hash<SymbolType>()(production.getPredecessor());
    size_t hash2 = hash<SymbolType>()(production.getSuccessor());
    return hash1 ^ hash2;
}

template class hash<Production<string>>;
