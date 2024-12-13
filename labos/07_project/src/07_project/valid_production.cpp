#include <07_project/valid_production.hpp>

using namespace std;

// IsValidProduction
template <typename SymbolType>
bool isValidProduction(const Production<SymbolType>& production, const unordered_set<SymbolType>& alphabet) {
    // Check if the predecessor is in the alphabet
    if (alphabet.find(production.getPredecessor()) == alphabet.end()) return false;

    // Check if the successor is in the alphabet
    for (char& successor : production.getSuccessor()) {
        string s(1, successor);
        if (alphabet.find(s) == alphabet.end()) return false;
    }

    return true;
}

template bool isValidProduction<string>(const Production<string>&, const unordered_set<string>&);
