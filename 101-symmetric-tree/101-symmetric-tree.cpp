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
    bool inor(TreeNode* t1,TreeNode* t2){
        if(t1==NULL || t2==NULL){
            return t1==t2?true:false;
        }
        if(t1->val!=t2->val){
            return false;
        }
        return inor(t1->left,t2->right) && inor(t1->right,t2->left);
    }
    bool isSymmetric(TreeNode* root) {
        return inor(root->left,root->right);
    }
};