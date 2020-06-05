class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        long sum = INT_MAX;
        for(int i=0; i<nums.size(); i++)
        {
            if(i>0 && nums[i] == nums[i-1])
                continue;
            long left = i + 1, right = nums.size() - 1;
            while(left < right)
            {
                long t = nums[i] + nums[left] + nums[right];
                if(t < target)
                {
                    if(target - t < abs(sum - target))
                        sum = t;
                    left++;
                }
                else if(t > target)
                {
                    if(t - target < abs(sum - target))
                        sum = t;
                    right--;
                }
                else
                {
                    return t;
                }
            }
        }
        return sum;
    }
};