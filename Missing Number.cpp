class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n = nums.size() + 1, sum = 0;
        int actualSum = (n * (n - 1)) / 2;
        for(int i : nums)
            sum += i;
        return actualSum - sum;
    }
};