/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
   void tra(TreeNode * n,vector<int>&s){
        if(n==NULL){
            return;
        }
        if(n->left!=NULL){
            tra(n->left,s);
        }
        s.push_back(n->val);
        if(n->right!=NULL){
            tra(n->right,s);
        }
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>f;
        vector<int>t;
        vector<int>ans;
        tra(root1,f);
        tra(root2,t);
        int i=0;
        int j=0;
        while(i<f.size() && j<t.size()){
            if(f[i]<=t[j]){
                ans.push_back(f[i]);
                i++;
            }
            else if(f[i]>t[j]){
                ans.push_back(t[j]);
                j++;
            }
        }
        while(i<f.size()){
            ans.push_back(f[i++]);
        }
        while(j<t.size()){
            ans.push_back(t[j++]);
        }
        return ans;
    }
};