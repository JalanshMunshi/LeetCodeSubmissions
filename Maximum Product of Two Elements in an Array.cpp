class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        for(int i=0; i<nums.size(); i++)
            nums[i]--;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n-2]*nums[n-1];
    }
};