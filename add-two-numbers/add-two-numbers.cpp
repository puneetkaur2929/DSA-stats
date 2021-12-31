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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* headans=new ListNode;
        int carry=0;
        ListNode* temp=headans;
        
        while(l1!=NULL || l2!=NULL || carry){
            int ans=0;
             if(l2!=NULL){
                ans+=l2->val;
                l2=l2->next;
            }
          if(l1!=NULL){
                ans+=l1->val;
                l1=l1->next;
            }
            ans+=carry;
            carry=ans/10;
             ListNode* in=new ListNode(ans%10);
                temp->next=in;
                temp=temp->next;
            
        }
        return headans->next;
    }
};