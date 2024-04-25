# Deductive Fault Simulation

This code implements a deductive fault simulation for a given circuit model. The simulation is performed based on a circuit consisting of nodes and gates, where each node represents a signal in the circuit.

## Files

- **node.h/cpp**: Define the `Node` class and `Fault` struct. Nodes represent signals in the circuit, and each node can have multiple faults associated with it. The `Node` class contains methods to handle fault merging and fault list management.

- **circuit.h/cpp**: Define the `Circuit` class, which manages the circuit simulation. It contains methods for true-value simulation, logic simulation, deductive fault simulation, and printing results. It also manages fault lists and calculates average statistics.

- **hw1.cpp**: Main program entry point. It creates an instance of the `Circuit` class and calls its methods to perform the simulation and print results.

- **makefile**: Defines the compilation rules to build the executable.

## Classes and Structures

- **Node**: Represents a signal in the circuit. It contains information about the signal's name, true value, associated faults, and fault list.

- **Fault**: Represents a fault in the circuit. It contains information about the fault's name, stuck-at value, and occurrence count.

- **Circuit**: Manages the circuit simulation. It contains methods for true-value simulation, logic simulation, deductive fault simulation, and printing results. It also manages fault lists and calculates average statistics.

## How to Use

To use the deductive fault simulation, follow these steps:

1. Compile the program using the provided `makefile`. Run `make` in the terminal.

2. Execute the compiled program by running `./hw1.o`.

3. The program will perform the following tasks:
   - (a) Truth Table: Prints the truth table of the circuit.
   - (b) Deductive Fault Simulation: Performs fault simulation for all input vectors and prints the detected faults for each input pattern.
   - (c) Average #fault per input vector: Calculates and prints the average number of faults per input vector.
   - (e) Average #pattern per fault: Calculates and prints the average number of patterns per fault.

## Dependencies

- **C++ Standard Library**: The program uses features from the C++11 standard library, including containers like `vector`, `unordered_map`, and `string`.

## Note

- The circuit model is predefined in the code. Modify the circuit representation in the source files (`circuit.cpp`, `circuit.h`) to simulate a different circuit.

- The program assumes a specific format for fault names and input signals. Modify the fault and input signal definitions in the source files accordingly if necessary.