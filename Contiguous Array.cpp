class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        unordered_map<int, int> m;
        m[0] = -1;
        int n = nums.size(), sum = 0, ans = 0;
        for(int i=0; i<n; i++)
        {
            if(nums[i])
                sum += 1;
            else
                sum -= 1;
            
            if(m.find(sum) != m.end())
                ans = max(ans, i - m[sum]);
            else
                m[sum] = i;
        }
        return ans;
    }
};