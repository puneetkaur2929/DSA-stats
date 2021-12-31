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
#define tup tuple<TreeNode* ,int,int>
class Solution {
public:
    int pre(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        stack<tup>s;
        int max_diff=0;
        s.push(make_tuple(root,root->val,root->val));
        while(!s.empty()){
            tup current=s.top();
            s.pop();
            auto node=get<0>(current);
            int curr_max=get<1>(current);
            int curr_min=get<2>(current);
            if(node->right){
                s.push(make_tuple(node->right,max(curr_max,node->right->val),min(node->right->val,curr_min)));
            }
            if(node->left){
                s.push(make_tuple(node->left,max(curr_max,node->left->val),min(node->left->val,curr_min)));
            }
            if(node->right==NULL && node->left==NULL){
                max_diff=max(max_diff,(curr_max-curr_min));
            }
        }
        return max_diff;
    }
    int maxAncestorDiff(TreeNode* root) {
       return pre(root);
    }
};