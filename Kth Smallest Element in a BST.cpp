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
    //function for a previous submission. Lesser optimized version.
    // int helper(TreeNode *root, int k, int &n)
    // {
    //     if(root)
    //     {
    //         int t = helper(root->left, k, n);
    //         if(t != -1)
    //             return t;
    //         n++;
    //         if(k == n)
    //             return root->val;
    //         return helper(root->right, k, n);
    //     }
    //     return -1;
    // }
    int kthSmallest(TreeNode* root, int k) {
        
        // int n = 0;
        // return helper(root, k, n);
        //optimized code. 
        stack<TreeNode*> s;
        while(!s.empty() || root)
        {
            while(root)
            {
                s.push(root);
                root = root->left;
            }
            TreeNode *t = s.top();
            k--;
            if(!k)
                return t->val;
            root = t->right;
            s.pop();
        }
        return -1;
    }
};