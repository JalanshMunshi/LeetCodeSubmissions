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
    int ans = 0;
    void pathSum(TreeNode *root, int sum, int cur) {
        if(root) {
            int t = cur + root->val;
            if(t == sum)
                ans++;
            pathSum(root->left, sum, t);
            pathSum(root->right, sum, t);
        }
    }
public:
    int pathSum(TreeNode* root, int sum) {
        if(root == NULL)
            return 0;
        pathSum(root, sum, 0);
        pathSum(root->left, sum);
        pathSum(root->right, sum);
        return ans;
    }
};