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

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>m;
         if(inorder.size()==0 && preorder.size()==0){
            return NULL;
        }
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
       TreeNode* root=build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,m);
        return root;
      
    }
        TreeNode* build(vector<int>&pre,int prestart,int preend,vector<int>&inor,int instart,int inend,unordered_map<int,int>&m){
//         base case
        if(prestart>preend || instart>inend){
            return NULL;
        }
     
        TreeNode* root=new TreeNode(pre[prestart]);
        int leftin=m[pre[prestart]];
        int numsleft=leftin-instart;
        root->left=build(pre,prestart+1,prestart+numsleft,inor,instart,leftin-1,m);
        root->right=build(pre,prestart+numsleft+1,preend,inor,leftin+1,inend,m);
        return root;
        
    }
};