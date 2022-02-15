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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count=0;
        ListNode* temp=head;
        ListNode* node=new ListNode;
        while(temp!=NULL){
            count++;
            temp=temp->next; 
        }
          if(n==1 && count==1){
              head=NULL;
              return head;
          }
        if(n==count){
            node=head;
            head=head->next;
            delete(node);
            return head;
        }
        ListNode* temp1=head;
        int time=count-n-1;
        while(time!=0){
            temp1=temp1->next;
            time--;
        }
        node=temp1->next;
        
        temp1->next=temp1->next->next;
        delete(node);
        
        return head; 
    }
};