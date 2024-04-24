#include "circuit.h"

Circuit::Circuit() {
    string stuckAt0("_0");
    string stuckAt1("_1");
    string faultName;
    Fault* newFault;

    for (int i=0; i<10; i++) {

        Node newNode(nodeName[i]);

        faultName = nodeName[i] + stuckAt0;
        newFault = new Fault(faultName, false); 
        faultList.insert(pair<string, Fault*>(faultName, newFault));
        newNode.faults.push_back(pair<string, Fault*>(faultName, newFault));

        faultName = nodeName[i] + stuckAt1;
        newFault = new Fault(faultName, true); 
        faultList.insert(pair<string, Fault*>(faultName, newFault));
        newNode.faults.push_back(pair<string, Fault*>(faultName, newFault));
        
        nodeList.insert(pair<string, Node>(nodeName[i], newNode));
    }
}


void Circuit::trueValueSimulation () {
    nodeList["y21"].trueValue = nodeList["x2"].trueValue;
    nodeList["y22"].trueValue = nodeList["x2"].trueValue;
    nodeList["a"].trueValue = nodeList["y21"].trueValue && nodeList["x1"].trueValue;
    nodeList["b"].trueValue = !(nodeList["y22"].trueValue || nodeList["x3"].trueValue);
    nodeList["c"].trueValue = !nodeList["x4"].trueValue;
    nodeList["z"].trueValue = nodeList["a"].trueValue || nodeList["b"].trueValue || nodeList["c"].trueValue;
}

void Circuit::deductiveSimulation() {
    cout << "x1\tx2\tx3\tx4\ty21\ty22\ta\tb\tc\tz" << endl;

    for (int i = 0; i < 16; ++i) {
        // Assign input values based on the bit representation of i

        nodeList["x1"].trueValue = (i & 8) ? true : false;
        nodeList["x2"].trueValue = (i & 4) ? true : false;
        nodeList["x3"].trueValue = (i & 2) ? true : false;
        nodeList["x4"].trueValue = (i & 1) ? true : false;

        trueValueSimulation();
        for (int i=0; i<10; i++) {
            cout << nodeList[nodeName[i]].trueValue << "\t";
            nodeList[nodeName[i]].cleanList();
            nodeList[nodeName[i]].addSelfFault();
        }
        cout << endl;

        
        nodeList["y21"].mergeBranchInv(nodeList["x2"]);
        nodeList["y22"].mergeBranchInv(nodeList["x2"]);

        nodeList["a"].mergeAnd(nodeList["y21"], nodeList["x1"]);
        nodeList["b"].mergeNor(nodeList["y22"], nodeList["x3"]);
        
        nodeList["c"].mergeBranchInv(nodeList["x4"]);
        nodeList["z"].mergeOr3(nodeList["a"], nodeList["b"], nodeList["c"]);

    }
}

void Circuit::printAllNode() {
    for (int i=0; i<10; i++) {
        nodeList[nodeName[i]].print();
    }
}
