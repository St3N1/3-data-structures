#include <07_project/production.hpp>

#ifndef PRODUCTION_HASH_H
#define PRODUCTION_HASH_H

template <typename SymbolType>
struct std::hash<Production<SymbolType>> {
    size_t operator()(const Production<SymbolType>& production) const;
};

#endif