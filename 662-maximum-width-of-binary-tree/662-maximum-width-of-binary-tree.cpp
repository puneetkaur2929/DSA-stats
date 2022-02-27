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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        int ans=1;
        while(!q.empty()){
            auto fn=q.front();
            auto bn=q.back();
            int count=q.size();
            ans=max(ans,(bn.second-fn.second)+1);
            for(int i=0;i<count;i++){
                auto node=q.front();
                int curridx=node.second-fn.second;
                q.pop();
                if(node.first->left){
                    q.push({node.first->left,(long long )2*curridx+1});
                }
                 if(node.first->right){
                    q.push({node.first->right,(long long )2*curridx+2});
                }
            }
            
        }
        return ans;
    }
};