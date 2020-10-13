#include <bits/stdc++.h>

using namespace std;

// Graphs'
class Node {
    public:
    int val;
    vector <Node*> nbors;
    
    Node() {
        val = 0;
        nbors = vector<Node*>();
    }
    Node(int x) {
        val = x;
        nbors = vector<Node*>();
    }
    Node(int x, vector <Node*> nodes) {
        val = x;
        nbors = nodes;
    }
};

int main() {
    
    return 0;
}