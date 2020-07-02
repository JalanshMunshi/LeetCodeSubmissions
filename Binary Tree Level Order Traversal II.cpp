// Better version using deque
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        vector<vector<int>> ans;
        if(!root)
            return ans;
        deque<TreeNode*> q;
        q.push_back(root);
        while(q.size() > 0)
        {
            int levelSize = q.size();
            vector<int> level;
            for(int i=0; i<levelSize; i++)
            {
                TreeNode *t = q.front();
                q.pop_front();
                level.push_back(t->val);
                if(t->left)
                    q.push_back(t->left);
                if(t->right)
                    q.push_back(t->right);
            }
            ans.push_back(level);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// Initially submitted
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
    void bfs(TreeNode *root, map<int, vector<int>> &ans, int level)
    {
        if(root)
        {
            ans[level].push_back(root->val);
            if(root->left)
                bfs(root->left, ans, level + 1);
            if(root->right)
                bfs(root->right, ans, level + 1);
        }
    }
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        map<int, vector<int>> ans;
        bfs(root, ans, 0);
        vector<vector<int>> ret;
        for(auto it=ans.rbegin(); it!=ans.rend(); it++)
            ret.push_back(it->second);
        return ret;
    }
};