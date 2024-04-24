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

void Node::mergeBranch(const Node& fanIn) {
    list.insert(fanIn.list.begin(), fanIn.list.end());
}

void Node::mergeAnd(const Node& fanIn1, const Node& fanIn2) {
    if (trueValue) {
        list.insert(fanIn1.list.begin(), fanIn1.list.end());
        list.insert(fanIn2.list.begin(), fanIn2.list.end());
    } else {
        if (fanIn1.trueValue) {
            for (const auto& entry : fanIn2.list) {
                auto it = fanIn1.list.find(entry.first);
                if (it==fanIn1.list.end()) list.insert(entry);
            }
        } else if (fanIn2.trueValue) {
            for (const auto& entry : fanIn1.list) {
                auto it = fanIn2.list.find(entry.first);
                if (it==fanIn2.list.end()) list.insert(entry);
            }  
        } else {
            for (const auto& entry : fanIn2.list) {
                auto it = fanIn1.list.find(entry.first);
                if (it!=fanIn1.list.end()) list.insert(entry);
            }
        }
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
    for (int i = 0; i < 16; ++i) {
        // Assign input values based on the bit representation of i

        nodeList["x1"].trueValue = (i & 8) ? true : false;
        nodeList["x2"].trueValue = (i & 4) ? true : false;
        nodeList["x3"].trueValue = (i & 2) ? true : false;
        nodeList["x4"].trueValue = (i & 1) ? true : false;

        trueValueSimulation();
        for (int i=0; i<10; i++) {
            nodeList[nodeName[i]].addSelfFault();
        }
        
        nodeList["y21"].mergeBranch(nodeList["x2"]);
        nodeList["y22"].mergeBranch(nodeList["x2"]);



        
        
    }
}