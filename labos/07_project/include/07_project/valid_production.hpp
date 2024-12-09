#include <07_project/production.hpp>
#include <iostream>
#include <unordered_set>
using namespace std;

#ifndef VALID_PRODUCTION_H
#define VALID_PRODUCTION_H

// This function verifies that all symbols in the production
// (Predecessor and all symbols in the successor) are
// in the given alphabet.
// If all symbols are in the alphabet, this function returns true,
// otherwise, this function returns false.
// The time-complexity of this function should be be O(N)
// where N is the total number of symbols in the production
// (predecessor + successors)
template <typename SymbolType>
bool isValidProduction(const Production<SymbolType>& production, const unordered_set<SymbolType>& alphabet) {
    // Check if the predecessor is in the alphabet
    if (alphabet.find(production.getPredecessor()) == alphabet.end()) return false;

    // Check if the successor is in the alphabet
    for (const SymbolType successor : production.getSuccessor())
        if (alphabet.find(successor) == alphabet.end()) return false;

    return true;
}

#endif