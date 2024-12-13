#include <07_project/l-system_interpreter.hpp>
#include <catch2/catch.hpp>

using namespace std;

TEST_CASE("Test L-system generated output with A=AB & B=A") {
    const vector<string> lsystemOutputCheck_5N = {"A", "B", "A", "A", "B", "A", "B", "A"};

    // Create productions
    string predecessor1 = "A";
    string successor1 = "AB";
    Production<string> production1(predecessor1, successor1);

    string predecessor2 = "B";
    string successor2 = "A";
    Production<string> production2(predecessor2, successor2);

    // Create Lsystem
    vector<string> axiom = {"B"};

    unordered_set<Production<string>> productions;
    productions.insert(production1);
    productions.insert(production2);

    unordered_set<string> alphabet = {"A", "B"};

    LSystemInterpreter<string> lsystem(axiom, productions, alphabet);

    // Generate Lsystem output
    vector<string> lsystemOutput;
    for (size_t i = 0; i < 5; i++) lsystemOutput = lsystem();

    // Check if output is correct
    REQUIRE(lsystemOutput == lsystemOutputCheck_5N);
}

TEST_CASE("Test L-system state when reset") {
    const float degrees = 90;

    // Create production
    string predecessor = "F";
    string successor = "F-F+F+FF-F-F+F";
    Production<string> production(predecessor, successor);

    // Create Lsystem
    vector<string> axiom = {"F", "-", "F", "-", "F", "-", "F"};

    unordered_set<Production<string>> productions;
    productions.insert(production);

    unordered_set<string> alphabet = {"F", "-", "+"};

    LSystemInterpreter<string> lsystem(axiom, productions, alphabet);

    // Configure the angle of the turtle
    lsystem.setTurtleAngle(degrees);

    // Generate Lsystem output
    vector<string> lsystemOutput;
    for (size_t i = 0; i < 3; i++) lsystemOutput = lsystem();

    lsystem.reset();
    REQUIRE(lsystem.getCurrentState() == axiom);
};