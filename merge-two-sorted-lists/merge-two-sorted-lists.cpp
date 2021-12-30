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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
         ListNode* head=new ListNode;
         ListNode* a=l1;
         ListNode* b=l2;
        if(l1==NULL && l2==NULL){
            return NULL;
        }
        else if(l1==NULL && l2!=NULL){
            return l2;
        }
        else if(l1!=NULL && l2==NULL ){
            return l1;
        }
        if(a->val<=b->val){
            head->next=a;
             ListNode* ans=head;
                head=head->next;
                a=a->next;
        }
        else{
             head->next=b;
             ListNode* ans=head;
                head=head->next;
                b=b->next;
        }
        ListNode* ans=head;
        while(a!=NULL && b!=NULL){
            if(a->val<=b->val){
                head->next=a;
                head=head->next;
                a=a->next;
            }
            else{
                head->next=b;
                head=head->next;
                b=b->next;
            }
        }
        while(a!=NULL){
             head->next=a;
                head=head->next;
                a=a->next;
            
        }
        while(b!=NULL){
             head->next=b;
                head=head->next;
                b=b->next;
        }
        return ans;
    }
};