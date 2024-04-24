#include <iostream>
#include <vector>

using namespace std;

// Function to simulate NOR gate
bool nor(bool a, bool b) {
    return !(a || b);
}

// Function to simulate NOT gate
bool not_gate(bool a) {
    return !a;
}

// Function to simulate AND gate
bool and_gate(bool a, bool b) {
    return a && b;
}

// Function to simulate OR gate
bool or_gate(bool a, bool b) {
    return a || b;
}

// Function to simulate stuck-at-0 fault
bool stuck_at_0(bool signal) {
    return false; // Always returns 0
}

// Function to simulate stuck-at-1 fault
bool stuck_at_1(bool signal) {
    return true; // Always returns 1
}

int main() {
    // Primary input signals
    bool x1, x2, x3, x4;

    // Output signals of logic gates
    bool a, b, c, z;

    // Branch signals
    bool y21, y22;
    
    // Truth table
    cout << "x1\tx2\tx3\tx4\ta\tb\tc\tz\n";

    // Iterate over all possible input combinations
    for (int i = 0; i < 16; ++i) {
        // Assign input values based on the bit representation of i
        x1 = (i & 8) ? true : false;
        x2 = (i & 4) ? true : false;
        x3 = (i & 2) ? true : false;
        x4 = (i & 1) ? true : false;

        // Calculate gate outputs
        a = and_gate(x1, x2);
        b = nor(x2, x3);
        c = not_gate(x4);
        z = or_gate(or_gate(a, b), c);

        // Output the truth table row
        cout << x1 << "\t" << x2 << "\t" << x3 << "\t" << x4 << "\t" << a << "\t" << b << "\t" << c << "\t" << z << "\n";
    }

    

    return 0;
}
