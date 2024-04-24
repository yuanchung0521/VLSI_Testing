#include "circuit.h"

int main() {

    Circuit circuit;
    // (a)
    circuit.logicSimulation();

    // (b)
    circuit.deductiveSimulation();
    
    // (c)
    circuit.printAvgFaultPerInput();

    // (d) is shown in (b)
    // (e) 
    circuit.printAvgPatternPerFault();
    
    // (f) is shown in (e)

    return 0;
}
