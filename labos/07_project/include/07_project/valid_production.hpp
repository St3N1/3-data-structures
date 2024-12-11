#include <07_project/production.hpp>
#include <iostream>
#include <unordered_set>

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
bool isValidProduction(const Production<SymbolType>& production, const std::unordered_set<SymbolType>& alphabet);

#endif