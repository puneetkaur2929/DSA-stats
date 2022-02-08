/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* ans;
    void inor(TreeNode* ori,TreeNode* cop,TreeNode* tar){
        if(ori==NULL || cop==NULL){
            return;
        }
        inor(ori->left,cop->left,tar);
        if(ori==tar && cop->val==tar->val){
            ans=cop;
            return ;
        }
        inor(ori->right,cop->right,tar);
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        inor(original,cloned,target);
        return ans;
    }
};