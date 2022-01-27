class Node {
    public:
    Node* left;
    Node* right;
};
class Trie {
public:
    Node* root;
    Trie() {
        root=new Node();
    }
    
    void insert(int n) {
        Node*temp=root;
      for(int i=31;i>=0;i--){
          int bit=(n>>i)&1;
          if(bit==0){
              if(temp->left==NULL){
                  temp->left=new Node();
              }
              temp=temp->left;
          }
          else{
              if(temp->right==NULL){
                  temp->right=new Node();
              }
              temp=temp->right;
          }
      }
    }
    int helper(int val){
        int cur=0;
        Node* temp=root;
         for(int i=31;i>=0;i--){
          int bit=(val>>i)&1;
             if(bit==0){
                 if(temp->right!=NULL){
                     temp=temp->right;
                     cur+=(1<<i);
                 }
                 else{
                     temp=temp->left;
                 }
             }
              else if(bit==1){
                 if(temp->left!=NULL){
                     temp=temp->left;
                     cur+=(1<<i);
                 }
                 else{
                     temp=temp->right;
                 }
             }
         }
        return cur;
        
    }
    int max_xor(vector<int>nums,int n){
        int ans=0;
        for(int i=0;i<n;i++){
            int value=nums[i];
            insert(value);
            int curr=helper(value);
            ans=max(ans,curr);
        }
        return ans;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie* obj=new Trie();
        return obj->max_xor(nums,nums.size());
        
    }
};