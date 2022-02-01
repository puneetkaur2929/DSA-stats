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
     void level(TreeNode*root,vector<vector<int>>&a){
        if(root==NULL){
            return;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int cou=q.size();
            vector<int>in;
            for(int i=0;i<cou;i++){
                auto t=q.front();
                in.push_back(t->val);
                q.pop();
                if(t->left){
                    q.push(t->left);
                }
                if(t->right){
                    q.push(t->right);
                }
            }
            a.push_back(in);
        }
        
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
         vector<vector<int>>a;
        level(root,a);
        reverse(a.begin(),a.end());
        return a;
    }
};