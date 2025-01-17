#include <07_project/l-system_interpreter.hpp>

using namespace std;

int main() {
    const float degrees = 22.5;

    // Create productions
    string predecessor = "F";
    string successor = "FF-[-F+F+F]+[+F-F-F]";
    Production<string> production(predecessor, successor);

    // Create Lsystem
    vector<string> axiom = {"F"};

    unordered_set<Production<string>> productions;
    productions.insert(production);

    unordered_set<string> alphabet = {"F", "[", "]", "-", "+"};

    LSystemInterpreter<string> lsystem(axiom, productions, alphabet);

    // Configure the angle of the turtle
    lsystem.setTurtleAngle(degrees);

    // Grow the 'tree' step by step
    vector<string> lsystemOutput;

    for (size_t i = 0; i < 5; i++) {
        lsystemOutput = lsystem();
        lsystem.runPythonTurtle();
    }

    // Reset the 'tree'
    lsystem.reset();

    // Grow the 'tree' again step by step
    for (size_t i = 0; i < 5; i++) {
        lsystemOutput = lsystem();
        lsystem.runPythonTurtle();
    }

    return 0;
}
