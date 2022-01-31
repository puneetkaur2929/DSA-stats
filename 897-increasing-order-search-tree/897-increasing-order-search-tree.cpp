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
    void inorder(TreeNode*root,vector<TreeNode*>&a){
        if(root==NULL){
            return;
        }
        inorder(root->left,a);
        a.insert(a.end(),root);
        inorder(root->right,a);
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector<TreeNode*>ans;
        if(root==NULL){
            return root;
        }
        inorder(root,ans);
        root=ans[0];
        for(int i=0;i<ans.size()-1;i++){
            auto node=ans[i];
            node->left=NULL;
            node->right=ans[i+1];
        }
        ans[ans.size()-1]->left=NULL;
        ans[ans.size()-1]->right=NULL;
        return root;
    }
};