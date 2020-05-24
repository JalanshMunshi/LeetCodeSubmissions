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
    TreeNode* bstInsert(TreeNode *root, int x)
    {
        if(!root)
            root = new TreeNode(x);
        else if(x < root->val)
            root->left = bstInsert(root->left, x);
        else
            root->right = bstInsert(root->right, x);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        TreeNode *root = NULL;
        for(auto i : preorder)
            root = bstInsert(root, i);
        return root;
    }
};