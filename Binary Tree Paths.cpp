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
    void traverse(TreeNode *root, vector<string> &ans, string s)
    {
        if(root)
        {
            if(root->left == NULL && root->right == NULL)
            {
                s += to_string(root->val);
                ans.push_back(s);
                return;
            }
            s += to_string(root->val) + "->";
            traverse(root->left, ans, s);
            traverse(root->right, ans, s);
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<string> ans;
        string s = "";
        traverse(root, ans, s);
        return ans;
    }
};