/*
// Definition for a Node.
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
*/

class Solution {
public:
    void helper(Node* curr,Node* copy,vector<Node*> &vis){
        vis[copy->val]=copy;
         for(auto it:curr->neighbors){
            if(vis[it->val]==NULL){
                Node* nn=new Node(it->val);
                (copy->neighbors).push_back(nn);
                helper(it,nn,vis);
            }
            else{
                (copy->neighbors).push_back(vis[it->val]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL){
            return node;
        }
        vector<Node*>vis(1000,NULL);
        Node* copy=new Node(node->val);
        vis[copy->val]=copy;
        for(auto it:node->neighbors){
            if(vis[it->val]==NULL){
                Node* nn=new Node(it->val);
                (copy->neighbors).push_back(nn);
                helper(it,nn,vis);
            }
            else{
                (copy->neighbors).push_back(vis[it->val]);
            }
        }
        return copy;
        
    }
};