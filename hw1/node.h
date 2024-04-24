#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

struct Fault {
    string name;
    bool stuckAt;
    int count;
    Fault() {};
    ~Fault() {};
    Fault(string& _name, bool _stuckAt): count(0), name(_name), stuckAt(_stuckAt) {}    
};
class Circuit;

class Node {
private:
    string name;
    bool trueValue;
    vector<pair<string, Fault*>> faults;
    unordered_map<string, Fault*> list;
    friend Circuit;

public:
    Node(){};
    Node(string& _name): name(_name), trueValue(false) {};
    void cleanList();
    void addSelfFault();
    void mergeBranchInv(const Node& fanIn);
    void mergeAnd(const Node& fanIn1, const Node& fanIn2);
    void mergeNor(const Node& fanIn1, const Node& fanIn2);
    void mergeOr3(const Node& fanIn1, const Node& fanIn2, const Node& fanIn3);
    void print() const;
};