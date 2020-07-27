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
    int lastPost;
    TreeNode* helper(vector<int> &inorder, vector<int> &postorder, int start, int end)
    {
        if(start > end)
            return NULL;
        TreeNode *root = new TreeNode(postorder[lastPost]);
        lastPost--;
        if(start == end) // leaf node condition
            return root;
        auto it = find(inorder.begin(), inorder.end(), root->val);
        int index = it - inorder.begin();
        root->right = helper(inorder, postorder, index + 1, end);
        root->left = helper(inorder, postorder, start, index - 1);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        lastPost = postorder.size() - 1;
        return helper(inorder, postorder, 0, lastPost);
    }
};