class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int ans = 0;
        if(nums.size() <= 1)
            return ans;
        for(int i=0; i<nums.size(); i++)
            for(int j=i+1; j<nums.size(); j++)
            {
                if(nums[i] == nums[j] && i < j)
                    ans++;
            }
        return ans;
    }
};