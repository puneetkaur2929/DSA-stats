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
#define  pp pair<int,ListNode*>
class Solution {
public:
 
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return NULL;
        }
        priority_queue<pp,vector<pp>,greater<pp>>p;
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=NULL){
               p.push({lists[i]->val,lists[i]}); 
            }
            
        }
        
        ListNode* head=new ListNode(0);
       ListNode* temp=head;
        while(!p.empty()){
            ListNode* tp=p.top().second;
            p.pop();
            if(tp->next!=NULL){
                p.push({tp->next->val,tp->next});
            }
             temp->next=tp;
            temp=temp->next;
        }
        return head->next;
    }
};