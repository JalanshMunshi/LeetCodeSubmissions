class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        vector<int> ans;
        if(nums.size() == 0)
            return ans;
        vector<int> count(nums.size(), 1), prev(nums.size(), -1);
        int maxIndex = 0;
        sort(nums.begin(), nums.end());
        for(int i=1; i<nums.size(); i++)
        {
            for(int j=0; j<i; j++)
            {
                if(nums[i] % nums[j] == 0)
                {
                    if(count[i] < count[j] + 1)
                    {
                        count[i] = count[j] + 1;
                        prev[i] = j;
                    }
                }
            }
            if(count[maxIndex] < count[i])
                maxIndex = i;
        }
        while(maxIndex >= 0)
        {
            ans.push_back(nums[maxIndex]);
            maxIndex = prev[maxIndex];
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};