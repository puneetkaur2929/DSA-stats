/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prev=NULL;
       stack<ListNode*>s;
        if(head==NULL){
            return NULL;
        }
        int l=0;
        while(temp!=NULL){
            s.push(temp);
            l++;
            temp=temp->next;
        }
        if(k>=l){
            k=k%l;
        }
        while(k!=0 && s.size()>0){
            ListNode* last=s.top();
            s.pop();
            last->next=head;
            head=last;
            s.top()->next=NULL;
            k--;
        }
        return head;
    }
};