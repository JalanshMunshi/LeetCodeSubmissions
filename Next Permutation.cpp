class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        if(nums.size() < 2)
            return;
        int pivot = nums.size() - 2;
        while(pivot >= 0 && nums[pivot] >= nums[pivot + 1])
            pivot--;
        if(pivot == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        for(int i=nums.size() - 1; i>pivot; i--)
            if(nums[i] > nums[pivot])
            {
                swap(nums[i], nums[pivot]);
                break;
            }
        reverse(nums.begin() + pivot + 1, nums.end());
    }
};