#include <07_project/production.hpp>
#include <07_project/production_hash.hpp>
#include <07_project/valid_production.hpp>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <unordered_set>
#include <vector>

using namespace std;

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
    LSystemInterpreter(const vector<SymbolType>& axiom, const unordered_set<Production<SymbolType>>& productions, const unordered_set<SymbolType>& alphabet)
        : m_axiom(axiom), m_productions(productions), m_alphabet(alphabet), m_currentState(axiom) {
        unordered_set<SymbolType> predecessorsCheck;
        unordered_set<SymbolType> alphabetCheck = m_alphabet;

        for (const Production production : m_productions) {
            SymbolType predecessor = production.getPredecessor();

            // Check for valid production
            if (!isValidProduction(production, m_alphabet)) throw invalid_argument("Invalid production");

            // Check for predecessor duplicates
            if (!predecessorsCheck.insert(predecessor).second) throw invalid_argument("Duplicate predecessor found");

            // Remove predecessor from a temporary alphabet
            if (alphabet.contains(predecessor)) alphabetCheck.erase(predecessor);
        }

        // Insert the leftovers in temporary alphabet in productions
        for (const SymbolType symbol : alphabetCheck) {
            Production<SymbolType> production(symbol, symbol);
            insertProduction(production);
        };

        predecessorsCheck.clear();
        alphabetCheck.clear();
    };

    void reset() { m_currentState = m_axiom; }

    void runPythonTurtle() {
        if (!m_degrees) throw("Angle is not set, use 'setTurtleAngle'");
        system(("python3 ../python/main.py " + to_string(m_degrees)).c_str());
    }

    vector<SymbolType> operator()(int n) const {
        // Generate new state
        for (size_t i = 0; i < n; i++) const_cast<LSystemInterpreter*>(this)->m_currentState = (generate(m_currentState));

        // Write new state to a file
        writeToFile(m_currentState);

        return m_currentState;
    };

    void setTurtleAngle(float degrees) { m_degrees = degrees; }

    vector<SymbolType> getAxiom() const { return m_axiom; }
    unordered_set<Production<SymbolType>> getProductions() const { return m_productions; }
    unordered_set<SymbolType> getAlphabet() const { return m_alphabet; }
    vector<SymbolType> getCurrentState() const { return m_currentState; }

   private:
    vector<SymbolType> generate(const vector<SymbolType>& nextState) const {
        vector<SymbolType> newState;
        for (const SymbolType letter : nextState) applyProductions(newState, letter);
        return newState;
    }

    void applyProductions(vector<SymbolType>& newState, const SymbolType letter) const {
        for (const Production production : m_productions) {
            if (letter == production.getPredecessor()) {
                for (const SymbolType successor : production.getSuccessor()) newState.push_back(successor);
            }
        }
    }

    void writeToFile(const vector<SymbolType>& state) const {
        ofstream MyFile("../python/L-system.txt");
        for (const SymbolType symbol : state) MyFile << symbol;
        MyFile.close();
    }

    void insertProduction(const Production<SymbolType>& production) { m_productions.insert(production); }
    void setCurrentState(const vector<SymbolType>& state) { m_currentState = state; }

   private:
    vector<SymbolType> m_axiom;
    unordered_set<Production<SymbolType>> m_productions;
    unordered_set<SymbolType> m_alphabet;
    vector<SymbolType> m_currentState;
    float m_degrees;
};

#endif