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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push(make_pair(root,make_pair(0,0)));
        map<int,map<int,multiset<int>>>m;
        while(!q.empty()){
            auto tp=q.front();
            q.pop();
            auto node=tp.first;
            int ver=tp.second.first;
            int level=tp.second.second;
           m[ver][level].insert(node->val);
            if(node->left){
                q.push(make_pair(node->left,make_pair(ver-1,level+1)));
            }
             if(node->right){
                q.push(make_pair(node->right,make_pair(ver+1,level+1)));
            }
        }
        for(auto itr:m){
            vector<int>inter;
            // sort((itr.second).begin(),(itr.second).end());
            for(auto itr1:itr.second){
                inter.insert(inter.end(),itr1.second.begin(),itr1.second.end());
            }
            ans.push_back(inter);
        }
        return ans;
    }
};