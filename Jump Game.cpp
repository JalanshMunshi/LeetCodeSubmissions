class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1)
            return true;
        if(nums[0] == 0)
            return false;
        int n = nums.size() - 1;
        for(int i=nums.size()-2; i>=0; i--)
            if(nums[i] >= n - i)
                n = i;
        return n == 0 ? true : false;
    }
};