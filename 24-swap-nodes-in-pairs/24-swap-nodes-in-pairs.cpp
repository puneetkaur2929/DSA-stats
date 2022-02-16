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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* slow=head;
        ListNode* fast=head->next;
        ListNode* prev=NULL;
        head=head->next;
        while(slow!=NULL && fast!=NULL){
            if(prev){
                prev->next=fast;
            }
            slow->next=fast->next;
            fast->next=slow;
            prev=slow;
            slow=slow->next;
             fast= (slow!=NULL)?slow->next:NULL;
            
        }
        return head;
    }
};