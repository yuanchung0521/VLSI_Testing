#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

struct Fault {
    string name;
    bool stuckAt;
    int count;

    Fault(string& _name, bool _stuckAt): count(0), name(_name), stuckAt(_stuckAt) {}    
};

struct Node {

    string name;
    bool trueValue;
    vector<pair<string, Fault*>> faults;
    unordered_map<string, Fault*> list;

    Node(string& _name): name(_name), trueValue(false) {};
    void addSelfFault();
};


class Circuit {
private:
    string nodeName[10] = {"x1", "x2", "x3", "x4", "y21", "y22", "a", "b", "c", "z"};
    unordered_map<string, Fault*> faultList;
    unordered_map<string, Node> nodeList;
    
public:
    Circuit();
    void deductiveSimulation();
};