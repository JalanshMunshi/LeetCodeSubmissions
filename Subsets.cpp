// Refer this post - https://leetcode.com/problems/subsets/discuss/729973/C%2B%2B-or-2-Solutions-with-explanation
// Backtracking solution
class Solution {
private:
    void helper(vector<int> nums, vector<vector<int>> &ans, vector<int> sub, int start)
    {
        ans.push_back(sub);
        for(int i=start; i<nums.size(); i++)
        {
            sub.push_back(nums[i]);
            helper(nums, ans, sub, i + 1);
            sub.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        if(!n)
            return ans;
        sort(ans.begin(), ans.end());
        vector<int> sub;
        helper(nums, ans, sub, 0);
        return ans;
    }
};
// Basic solution
class Solution {
private:
    void helper(vector<int> nums, vector<vector<int>> &ans, int i, int n)
    {
        if(i == n)
            return;
        int t = nums[i]; //current element that needs to be added to the ans
        vector<vector<int>> temp = ans;
        for(auto v : temp)
        {
            v.push_back(t);
            ans.push_back(v);
        }
        helper(nums, ans, i + 1, n);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        if(!n)
            return ans;
        ans.push_back({});
        helper(nums, ans, 0, n);
        return ans;
    }
};