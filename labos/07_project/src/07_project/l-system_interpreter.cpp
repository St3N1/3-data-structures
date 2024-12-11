#include <07_project/l-system_interpreter.hpp>

using namespace std;

template <typename SymbolType>
LSystemInterpreter<SymbolType>::LSystemInterpreter(const vector<SymbolType>& axiom, const unordered_set<Production<SymbolType>>& productions, const unordered_set<SymbolType>& alphabet)
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
    for (SymbolType symbol : alphabetCheck) {
        Production<SymbolType> production(symbol, vector<SymbolType>(1, symbol));
        insertProduction(production);
    };

    predecessorsCheck.clear();
    alphabetCheck.clear();
};

template <typename SymbolType>
void LSystemInterpreter<SymbolType>::reset() { m_currentState = m_axiom; }

template <typename SymbolType>
void LSystemInterpreter<SymbolType>::setTurtleAngle(float degrees) { m_degrees = degrees; }

template <typename SymbolType>
void LSystemInterpreter<SymbolType>::runPythonTurtle() {
    if (!m_degrees) throw("Angle is not set, use 'setTurtleAngle'");
    system(("python3 ../python/main.py " + to_string(m_degrees)).c_str());
}

template <typename SymbolType>
vector<SymbolType> LSystemInterpreter<SymbolType>::operator()(int n) const {
    // Generate new state
    for (size_t i = 0; i < n; i++) const_cast<LSystemInterpreter*>(this)->m_currentState = generate(m_currentState);

    // Write new state to a file
    writeToFile(m_currentState);

    return m_currentState;
};

template <typename SymbolType>
vector<SymbolType> LSystemInterpreter<SymbolType>::getAxiom() const { return m_axiom; }

template <typename SymbolType>
unordered_set<Production<SymbolType>> LSystemInterpreter<SymbolType>::getProductions() const { return m_productions; }

template <typename SymbolType>
unordered_set<SymbolType> LSystemInterpreter<SymbolType>::getAlphabet() const { return m_alphabet; }

template <typename SymbolType>
vector<SymbolType> LSystemInterpreter<SymbolType>::getCurrentState() const { return m_currentState; }

template <typename SymbolType>
vector<SymbolType> LSystemInterpreter<SymbolType>::generate(const vector<SymbolType>& currentState) const {
    vector<SymbolType> newState;
    for (const SymbolType& letter : currentState) applyProductions(newState, letter);
    return newState;
}

template <typename SymbolType>
void LSystemInterpreter<SymbolType>::applyProductions(vector<SymbolType>& newState, const SymbolType& letter) const {
    for (const Production production : m_productions) {
        if (letter == production.getPredecessor()) {
            for (const SymbolType successor : production.getSuccessor()) newState.push_back(successor);
        }
    }
}

template <typename SymbolType>
void LSystemInterpreter<SymbolType>::writeToFile(const vector<SymbolType>& state) const {
    ofstream MyFile("../python/L-system.txt");
    for (const SymbolType symbol : state) MyFile << symbol;
    MyFile.close();
}

template <typename SymbolType>
void LSystemInterpreter<SymbolType>::insertProduction(const Production<SymbolType>& production) { m_productions.insert(production); }

template <typename SymbolType>
void LSystemInterpreter<SymbolType>::setCurrentState(const vector<SymbolType>& state) { m_currentState = state; }

template class LSystemInterpreter<const char*>;
