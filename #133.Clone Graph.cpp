#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    unordered_map<Node*,Node*>cloned;
    void dfs(Node * node){
        if(!node)return;
        for(Node * neigh : node->neighbors){
            if(cloned.find(neigh)==cloned.end()){
                int lol = neigh->val;
                cloned[neigh]= new Node(lol);
                dfs(neigh);
            }
            
            cloned[node]->neighbors.push_back(cloned[neigh]);
        }
    }
    Node* cloneGraph(Node* node) {
        if(!node)return nullptr;
        cloned[node]= new Node(node->val);
        dfs(node);
        return cloned[node];

    }
};