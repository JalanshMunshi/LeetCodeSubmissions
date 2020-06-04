class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i=0; i<nums.size(); i++)
        {
            if(i>0 && nums[i]==nums[i-1])
                continue;
            int left = i + 1, right = nums.size() - 1;
            while(left < right)
            {
                int t = nums[i] + nums[left] + nums[right];
                if(t < 0)
                    left++;
                else if(t > 0)
                    right --;
                else
                {
                    vector<int> v{nums[i], nums[left], nums[right]};
                    ans.push_back(v);
                    left++;
                    right--;
                    
                    while(left < right &&
                     nums[left] == nums[left-1] &&
                     nums[right] == nums[right+1])
                    {
                        left++;
                        right--;
                    }
                }
                
            }
        }
        return ans;
    }
};