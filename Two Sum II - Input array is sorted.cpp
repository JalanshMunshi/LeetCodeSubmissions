class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int start = 0, end = nums.size() - 1;
        vector<int> ans;
        while(start < end)
        {
            int t = nums[start] + nums[end];
            if(t > target)
                end--;
            else if(t < target)
                start++;
            else
            {
                ans.push_back(start + 1);
                ans.push_back(end + 1);
                return ans;
            }
        }
        return ans;
    }
};