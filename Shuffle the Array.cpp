class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        
        vector<int> ans;
        int i=0, j=n, flag = 0;
        while(j < n*2)
        {
            if(!flag)
            {
                ans.push_back(nums[i]);
                i++;
                flag = !flag;
            }
            else
            {
                ans.push_back(nums[j]);
                j++;
                flag = !flag;
            }
        }
        return ans;
    }
};