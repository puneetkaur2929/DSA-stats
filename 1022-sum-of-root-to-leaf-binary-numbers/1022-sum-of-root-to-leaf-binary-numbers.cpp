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
    int sumRootToLeaf(TreeNode* root) {
        int ans=0;
       stack<pair<TreeNode*,int>>s; 
        s.push(make_pair(root,0));
        while(!s.empty()){
            auto curr=s.top();
            s.pop();
            auto curr_node=curr.first;
            auto val=curr.second;
            val=val*2+curr_node->val;
            if(curr_node->left){
                s.push(make_pair(curr_node->left,val));
            }
            if(curr_node->right){
                s.push(make_pair(curr_node->right,val));
            }
            if(!curr_node->left && !curr_node->right){
                ans+=val;
            }
        }
        return ans;
    }
};