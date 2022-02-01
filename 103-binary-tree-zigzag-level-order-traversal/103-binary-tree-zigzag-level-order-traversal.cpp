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
        bool lr=true;
        while(!q.empty()){
            int cou=q.size();
            vector<int>in(cou);
            for(int i=0;i<cou;i++){
                auto t=q.front();
                int index=lr ? i : cou-1-i;
                in[index]=t->val;
                q.pop();
                if(t->left){
                    q.push(t->left);
                }
                if(t->right){
                    q.push(t->right);
                }
            }
            lr=!lr;
            a.push_back(in);
        }
        
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         vector<vector<int>>a;
        level(root,a);
        return a;
    }
};