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
     void level(TreeNode*root,vector<double>&a){
    if(root==NULL){
            return;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int cou=q.size();
           double av=0;
            for(int i=0;i<cou;i++){
                auto t=q.front();
                av+=t->val;
                q.pop();
                if(t->left){
                    q.push(t->left);
                }
                if(t->right){
                    q.push(t->right);
                }
            }
            av=av/cou;
            a.push_back(av);
        }
        
    }
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>a;
        level(root,a);
        return a;
    }
};