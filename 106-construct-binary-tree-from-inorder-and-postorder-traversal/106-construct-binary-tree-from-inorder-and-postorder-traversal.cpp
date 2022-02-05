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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()==0 && postorder.size()==0){
            return NULL;
        }
        unordered_map<int,int>m;
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
        int instart =0;
        int postend=0;
        int inend=inorder.size()-1;
        int poststart =inorder.size()-1;
        TreeNode* root=buildhelp(inorder,instart,inend,postorder,poststart,postend,m);
        return root;
    }
    TreeNode* buildhelp(vector<int>&inor,int instart,int inend,vector<int>&post,int poststart,int postend,unordered_map<int,int>&m  ){
        if(instart>inend || poststart < postend){
            return NULL;
        }
        TreeNode* root=new TreeNode(post[poststart]);
        int inroot=m[post[poststart]];
        int leftnode=inroot-instart;
       
         root->left=buildhelp(inor,instart,inroot-1,post,postend+leftnode-1,postend,m);
         root->right=buildhelp(inor,inroot+1,inend,post,poststart-1,postend+leftnode,m);
        return root;
    }
};