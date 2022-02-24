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
    ListNode* merge(ListNode* l1,ListNode* l2){
        ListNode* head2=new ListNode(0);
        ListNode* temp=head2;
        while(l1 && l2){
            if(l1->val<=l2->val){
                temp->next=l1;
                l1=l1->next;
            }
            else{
                temp->next=l2;
                l2=l2->next;
            }
            temp=temp->next;
        }
        if(l1){
            temp->next=l1;
            l1=l1->next;
            
        }
          if(l2){
            temp->next=l2;
              l2=l2->next;
            
        }
        return head2->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* slow=head;
        ListNode* fast=head;
       ListNode* temp=NULL;
       
        while(fast!=NULL && fast->next!=NULL){
            temp=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
       
        temp->next=NULL;
        ListNode* l1 = sortList(head);   
        ListNode* l2 = sortList(slow);    
        
        return merge(l1, l2);  
       
        
         
    }
};