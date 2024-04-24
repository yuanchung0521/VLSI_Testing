#include "node.h"

class Circuit {
private:
    vector<bool> maxFaultInput;
    vector<Fault*> maxFault;
    string nodeName[10] = {"x1", "x2", "x3", "x4", "y21", "y22", "a", "b", "c", "z"};
    unordered_map<string, Fault*> faultList;
    unordered_map<string, Node> nodeList;
    
public:
    Circuit();
    ~Circuit() {};
    void trueValueSimulation();
    void deductiveSimulation();
    void printNode(string& nodeName) const;
    void printAllNode();
};