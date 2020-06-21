class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int c = 0, n = nums.size();
        for(int i=0; i<n; i++)
        {
            if(nums[i] != 0)
            {
                nums[c++] = nums[i];
            }
        }
        while(c < n)
            nums[c++] = 0;
    }
};