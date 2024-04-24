#include "simulation.h"

Circuit::Circuit() {
    string stuckAt0("StuckAt0");
    string stuckAt1("StuckAt1");
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

void Node::addSelfFault() {
    if (trueValue) list.insert(faults[0]);
    else list.insert(faults[1]);
}

void Circuit::deductiveSimulation() {
    for (int i = 0; i < 16; ++i) {
        // Assign input values based on the bit representation of i

        nodeList["x1"].trueValue = (i & 8) ? true : false;
        nodeList["x2"].trueValue = (i & 4) ? true : false;
        nodeList["x3"].trueValue = (i & 2) ? true : false;
        nodeList["x4"].trueValue = (i & 1) ? true : false;

        for (int i=0; i<10; i++) {
            nodeList[nodeName[i]].addSelfFault();
        }
    }
}