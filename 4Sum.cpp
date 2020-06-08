class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> ans;
        set<vector<int>> s; 
        if(nums.size() < 4)
            return ans;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-2; i++)
        {
            if(i>0 && nums[i] == nums[i-1])
                continue;
            for(int j=i+1; j<nums.size()-1; j++)
            {
                if(j>i+1 && nums[j] == nums[j-1])
                    continue;
                int start = j + 1, end = nums.size() - 1;
                while(start < end)
                {
                    int t = nums[i] + nums[j] + nums[start] + nums[end];
                    if(t > target)
                        end--;
                    else if(t < target)
                        start++;
                    else
                    {
                        s.insert({nums[i], nums[j], nums[start], nums[end]});
                        start++;
                        end--;
                    }
                }
            }
        }
        for(auto v : s)
            ans.push_back(v);
        return ans;
    }
};