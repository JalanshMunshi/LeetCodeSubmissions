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
    void mirrorTree(TreeNode* root)
    {
        if(root)
        {
            TreeNode *temp;
            mirrorTree(root->left);
            mirrorTree(root->right);
            temp = root->left;
            root->left = root->right;
            root->right = temp;
        }
    }
    
    TreeNode* invertTree(TreeNode* root) {
        
        mirrorTree(root);
        return root;
    }
};