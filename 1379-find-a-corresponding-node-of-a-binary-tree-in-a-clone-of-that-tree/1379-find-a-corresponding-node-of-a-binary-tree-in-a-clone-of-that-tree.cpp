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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(original==NULL){
            return NULL;
        }
        queue<TreeNode*>q1;
        queue<TreeNode*>q2;
        q1.push(original);
        q2.push(cloned);
        while(q1.front()!=target){
            TreeNode* one=q1.front();
            q1.pop();
            if(one->left){
                q1.push(one->left);
            }
             if(one->right){
                q1.push(one->right);
            }
            TreeNode* one1=q2.front();
            q2.pop();
            if(one1->left){
                q2.push(one1->left);
            }
             if(one1->right){
                q2.push(one1->right);
            }
            
        }
        return q2.front();
    }
};