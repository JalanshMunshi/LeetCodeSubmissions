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
    int widthOfBinaryTree(TreeNode* root) {
        int ans = 0;
        if(!root)
            return ans;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        while(!q.empty())
        {
            int c = q.size(), left = q.front().second, right;
            for(int i=0; i<c; i++)
            {
                TreeNode* t = q.front().first;
                right = q.front().second;
                q.pop();
                if(t->left)
                    q.push({t->left, (unsigned int)2 * right});
                if(t->right)
                    q.push({t->right, (unsigned int)2 * right + 1});
            }
            ans = max(right - left +  1, ans);
        }
        return ans;
    }
};