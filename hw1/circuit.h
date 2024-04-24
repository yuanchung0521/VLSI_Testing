#include "node.h"

class Circuit {
private:
    float avgFaultPerInput;
    float avgPatternPerFault;
    string nodeName[10] = {"x1", "x2", "x3", "x4", "y21", "y22", "a", "b", "c", "z"};
    unordered_map<string, Fault*> faultList;
    unordered_map<string, Node> nodeList;
    
public:
    Circuit();
    ~Circuit() {};
    void trueValueSimulation();     // go throgh the circuit and assign true value to each node
    void logicSimulation();         // for (a) to print the truth table
    void deductiveSimulation();     // for (b) do the whole deductive simulation
    void printFaultDetected();      // print the output's fault list
    void printAllNode();        
    void printAvgFaultPerInput();   // for (c) to output the avg fault per intput vector
    void printAvgPatternPerFault(); // for (e) to calculate and output the avg patter per fault
};