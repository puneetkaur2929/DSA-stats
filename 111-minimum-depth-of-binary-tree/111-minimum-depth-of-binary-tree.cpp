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
    int minDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        queue<pair<TreeNode*,int>>q;
        q.push({root,1});
        while(!q.empty()){
            TreeNode* fn=q.front().first;
            int count=q.front().second;
            q.pop();
            if(!fn->left && !fn->right){
                return count;
            }
            if(fn->left){
                q.push({fn->left,count+1});
            }
             if(fn->right){
                q.push({fn->right,count+1});
            }
        }
        return 0;
    }
};