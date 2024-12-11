#include <07_project/valid_production.hpp>

using namespace std;

template <typename SymbolType>
bool isValidProduction(const Production<SymbolType>& production, const unordered_set<SymbolType>& alphabet) {
    // Check if the predecessor is in the alphabet
    if (alphabet.find(production.getPredecessor()) == alphabet.end()) return false;

    // Check if the successor is in the alphabet
    for (const SymbolType successor : production.getSuccessor())
        if (alphabet.find(successor) == alphabet.end()) return false;

    return true;
}

template bool isValidProduction<const char*>(const Production<const char*>&, const std::unordered_set<const char*>&);
