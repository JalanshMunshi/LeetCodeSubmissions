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
private:
    void helper(TreeNode *root, long num, long &ans)
    {
        if(!root)
            return;
        num = root->val + num * 10;
        if(root->left == NULL && root->right == NULL)
        {
            ans += num;
            return;
        }
        helper(root->left, num, ans);
        helper(root->right, num, ans);
    }
public:
    int sumNumbers(TreeNode* root) {
        
        long ans = 0;
        helper(root, 0, ans);
        return ans;
    }
};