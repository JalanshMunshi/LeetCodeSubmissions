// Backtracking approach
class Solution {
private:
    void helper(vector<int> nums, vector<vector<int>> &ans, int i)
    {
        if(i == nums.size())
            ans.push_back(nums);
        else
            for(int j=i; j<nums.size(); j++)
            {
                swap(nums[i], nums[j]);
                helper(nums, ans, i + 1);
            }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;
        helper(nums, ans, 0);
        return ans;
    }
};

// STL approach
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<int> orig = nums;
        vector<vector<int>> ans;
        ans.push_back(nums);
        while(1)
        {
            next_permutation(nums.begin(), nums.end());
            if(nums == orig)
                break;
            ans.push_back(nums);
        }
        return ans;
    }
};