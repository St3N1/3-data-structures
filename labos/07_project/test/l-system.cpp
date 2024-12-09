#include <07_project/l-system_interpreter.hpp>
#include <catch2/catch.hpp>
using namespace std;

TEST_CASE("Test L-system with A=AB & B=A") {
    const vector<const char*> lsystemOutputCheck_5N = {"A", "B", "A", "A", "B", "A", "B", "A"};

    // Create productions
    const char* predecessor1 = "A";
    const char* successor1 = "AB";
    Production<const char*> production1(predecessor1, successor1);

    const char* predecessor2 = "B";
    const char* successor2 = "A";
    Production<const char*> production2(predecessor2, successor2);

    // Create Lsystem
    vector<const char*> axiom = {"B"};

    unordered_set<Production<const char*>> productions;
    productions.insert(production1);
    productions.insert(production2);

    unordered_set<const char*> alphabet = {"A", "B"};

    LSystemInterpreter<const char*> lsystem(axiom, productions, alphabet);

    // Generate Lsystem output
    // vector<const char*> lsystemOutput = lsystem(5);

    // Check if output is correct
    // REQUIRE(lsystemOutput == lsystemOutputCheck_5N);
}

TEST_CASE("Test L-system state when reset") {
    const float degrees = 90;

    // Create production
    const char* predecessor = "F";
    const char* successor = "F-F+F+FF-F-F+F";
    Production<const char*> production(predecessor, successor);

    // Create Lsystem
    vector<const char*> axiom = {"F", "-", "F", "-", "F", "-", "F"};

    unordered_set<Production<const char*>> productions;
    productions.insert(production);

    unordered_set<const char*> alphabet = {"F", "-", "+"};

    LSystemInterpreter<const char*> lsystem(axiom, productions, alphabet);

    // Generate Lsystem output
    vector<const char*> lsystemOutput;

    lsystem.setTurtleAngle(degrees);

    lsystemOutput = lsystem(1);
    // lsystem.runPythonTurtle();

    lsystemOutput = lsystem(1);
    // lsystem.runPythonTurtle();

    lsystem.reset();
    REQUIRE(lsystem.getCurrentState() == axiom);
};

TEST_CASE() {
    const float degrees = 90;

    // Create productions
    const char* predecessor1 = "F";
    const char* successor1 = "F+G+";
    Production<const char*> production1(predecessor1, successor1);

    const char* predecessor2 = "G";
    const char* successor2 = "-F-G";
    Production<const char*> production2(predecessor2, successor2);

    // Create Lsystem
    vector<const char*> axiom = {"F"};

    unordered_set<Production<const char*>> productions;
    productions.insert(production1);
    productions.insert(production2);

    unordered_set<const char*> alphabet = {"F", "-", "+", "G"};

    LSystemInterpreter<const char*> lsystem(axiom, productions, alphabet);

    // Generate Lsystem output
    vector<const char*> lsystemOutput;

    lsystem.setTurtleAngle(degrees);

    lsystemOutput = lsystem(10);
    // lsystem.runPythonTurtle();
}

TEST_CASE() {
    const float degrees = 25.7;

    // Create productions
    const char* predecessor1 = "F";
    const char* successor1 = "F[+F]F[-F]F";
    Production<const char*> production1(predecessor1, successor1);

    // Create Lsystem
    vector<const char*> axiom = {"F"};

    unordered_set<Production<const char*>> productions;
    productions.insert(production1);

    unordered_set<const char*> alphabet = {"F"};

    LSystemInterpreter<const char*> lsystem(axiom, productions, alphabet);

    // Generate Lsystem output
    vector<const char*> lsystemOutput;

    lsystemOutput = lsystem(5);
    lsystem.setTurtleAngle(degrees);
    // lsystem.runPythonTurtle();
}