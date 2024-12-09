#include <07_project/production.hpp>

using namespace std;

#ifndef PRODUCTION_HASH_H
#define PRODUCTION_HASH_H

template <typename SymbolType>
struct hash<Production<SymbolType>> {
    size_t operator()(const Production<SymbolType>& production) const {
        size_t hash1 = hash<SymbolType>()(production.getPredecessor());
        size_t hash2 = 0;
        for (const SymbolType successer : production.getSuccessor()) {
            hash2 += hash<SymbolType>()(successer);
        }
        return hash1 ^ hash2;
    }
};

#endif