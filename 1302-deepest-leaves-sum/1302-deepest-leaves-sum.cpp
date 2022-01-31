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

    int deepestLeavesSum(TreeNode* root) {
            
    if (root == NULL) return 0;
    queue<TreeNode *> q;
    q.push(root);
    int nodesum=0;
    while (q.empty() == false){
        int nodeCount = q.size();
            nodesum=0;
        while (nodeCount > 0)
        {
            TreeNode *node = q.front();
            nodesum+=node->val;
            q.pop();
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
            nodeCount--;
        }
    }
        return nodesum;
        
    }
};