#include "node.h"

void Node::addSelfFault() {
    if (trueValue) list.insert(faults[0]);
    else list.insert(faults[1]);
}

void Node::mergeBranchInv(const Node& fanIn) {
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

void Node::mergeNor(const Node& fanIn1, const Node& fanIn2) {
    if (trueValue) {
        list.insert(fanIn1.list.begin(), fanIn1.list.end());
        list.insert(fanIn2.list.begin(), fanIn2.list.end());
    } else {
        if (fanIn1.trueValue && fanIn2.trueValue) {
            for (const auto& entry : fanIn2.list) {
                auto it = fanIn1.list.find(entry.first);
                if (it!=fanIn1.list.end()) list.insert(entry);
            }
        } else if (fanIn2.trueValue) {
            for (const auto& entry : fanIn2.list) {
                auto it = fanIn1.list.find(entry.first);
                if (it==fanIn1.list.end()) list.insert(entry);
            }  
        } else {
            for (const auto& entry : fanIn1.list) {
                auto it = fanIn2.list.find(entry.first);
                if (it!=fanIn2.list.end()) list.insert(entry);
            }
        }
    }
}

void Node::mergeOr3(const Node& fanIn1, const Node& fanIn2, const Node& fanIn3) {
    if (!trueValue) {
        list.insert(fanIn1.list.begin(), fanIn1.list.end());
        list.insert(fanIn2.list.begin(), fanIn2.list.end());
        list.insert(fanIn3.list.begin(), fanIn3.list.end());
    } else {
        if (fanIn1.trueValue && !fanIn2.trueValue && !fanIn3.trueValue) {
            for (const auto& entry : fanIn1.list) {
                auto it2 = fanIn2.list.find(entry.first);
                auto it3 = fanIn3.list.find(entry.first);
                if (it2==fanIn2.list.end() && it3==fanIn3.list.end()) list.insert(entry);
            }
        } else if (fanIn2.trueValue && !fanIn1.trueValue && !fanIn3.trueValue) {
            for (const auto& entry : fanIn2.list) {
                auto it1 = fanIn1.list.find(entry.first);
                auto it3 = fanIn3.list.find(entry.first);
                if (it1==fanIn1.list.end() && it3==fanIn3.list.end()) list.insert(entry);
            }  
        } else if (fanIn3.trueValue && !fanIn1.trueValue && !fanIn2.trueValue) {
            for (const auto& entry : fanIn3.list) {
                auto it1 = fanIn1.list.find(entry.first);
                auto it2 = fanIn2.list.find(entry.first);
                if (it1==fanIn1.list.end() && it2==fanIn2.list.end()) list.insert(entry);
            }  
        } else if (fanIn1.trueValue && fanIn2.trueValue && !fanIn3.trueValue) {
            for (const auto& entry : fanIn1.list) {
                auto it2 = fanIn2.list.find(entry.first);
                auto it3 = fanIn3.list.find(entry.first);
                if (it2!=fanIn2.list.end() && it3==fanIn3.list.end()) list.insert(entry);
            }
        } else if (fanIn2.trueValue && fanIn3.trueValue && !fanIn1.trueValue) {
            for (const auto& entry : fanIn2.list) {
                auto it1 = fanIn1.list.find(entry.first);
                auto it3 = fanIn3.list.find(entry.first);
                if (it1==fanIn1.list.end() && it3!=fanIn3.list.end()) list.insert(entry);
            }  
        } else if (fanIn3.trueValue && fanIn1.trueValue && !fanIn2.trueValue) {
            for (const auto& entry : fanIn3.list) {
                auto it1 = fanIn1.list.find(entry.first);
                auto it2 = fanIn2.list.find(entry.first);
                if (it1!=fanIn1.list.end() && it2==fanIn2.list.end()) list.insert(entry);
            }  
        } else {
            for (const auto& entry : fanIn3.list) {
                auto it1 = fanIn1.list.find(entry.first);
                auto it2 = fanIn2.list.find(entry.first);
                if (it1!=fanIn1.list.end() && it2!=fanIn2.list.end()) list.insert(entry);
            }
        }
    }
}

void Node::print() const {
    cout << "Node " << name << "(" << trueValue << ") : ";
    for (const auto& entry: list) {
        cout << entry.first << " ";
    }
    cout << endl;
}

void Node::cleanList() {
    list.clear();
}