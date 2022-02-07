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
    int count;
    int res=-1;
    void inorder(TreeNode* root,int k){
        if(root){
         inorder(root->left,k);
           count++;
        if(count==k){
            res=root->val;
            return ;
        }
        inorder(root->right,k);
           }
    }
    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL){
            return 0;
        }
        count=0;
        inorder(root,k);
        return res;
    }
};