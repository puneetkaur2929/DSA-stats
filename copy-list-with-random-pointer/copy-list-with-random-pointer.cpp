/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*>m;
        Node* temp=head;
        Node* temp2=head;
        while(temp!=NULL){
            Node* copy=new Node(temp->val);
            m[temp]=copy;
            temp=temp->next;
        }
        while(temp2!=NULL){
            m[temp2]->next=m[temp2->next];
            m[temp2]->random=m[temp2->random];
            temp2=temp2->next;
        }
        return m[head];
    }
};