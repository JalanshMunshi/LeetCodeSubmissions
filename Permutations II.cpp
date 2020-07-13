class Solution {
private:
    void helper(vector<int> nums, set<vector<int>> &ans, int i)
    {
        if(i == nums.size())
            ans.insert(nums);
        else
            for(int j=i; j<nums.size(); j++)
            {
                swap(nums[i], nums[j]);
                helper(nums, ans, i + 1);
            }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> ans;
        helper(nums, ans, 0);
        vector<vector<int>> ret;
        for(auto v : ans)
            ret.push_back(v);
        return ret;
    }
};