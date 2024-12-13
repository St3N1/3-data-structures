#include <07_project/production.hpp>
#include <07_project/production_hash.hpp>
#include <07_project/valid_production.hpp>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <unordered_set>
#include <vector>

#ifndef LSYSTEM_H
#define LSYSTEM_H

// This class represents the actual L-System.
// It contains an axiom (Initial state), A set of productions
// (Replacement rules) and an alphabet (List of allowed symbols).
template <typename SymbolType>
class LSystemInterpreter {
   public:
    // This constructor takes an axiom, a set of productions and
    // an alphabet and stores these in the fields.
    LSystemInterpreter(const std::vector<SymbolType>& axiom, const std::unordered_set<Production<SymbolType>>& productions, const std::unordered_set<SymbolType>& alphabet);

    void reset();
    void setTurtleAngle(float degrees);
    void runPythonTurtle();

    std::vector<SymbolType> operator()() const;

    std::vector<SymbolType> getAxiom() const;
    std::unordered_set<Production<SymbolType>> getProductions() const;
    std::unordered_set<SymbolType> getAlphabet() const;
    std::vector<SymbolType> getCurrentState() const;

   private:
    std::vector<SymbolType> generate(const std::vector<SymbolType>& currentState) const;

    void applyProductions(std::vector<SymbolType>& newState, const SymbolType& letter) const;
    void writeToFile(const std::vector<SymbolType>& state) const;
    void insertProduction(const Production<SymbolType>& production);
    void setCurrentState(const std::vector<SymbolType>& state);

   private:
    std::vector<SymbolType> m_axiom;
    std::unordered_set<Production<SymbolType>> m_productions;
    std::unordered_set<SymbolType> m_alphabet;
    std::vector<SymbolType> m_currentState;
    float m_degrees;
};

#endif