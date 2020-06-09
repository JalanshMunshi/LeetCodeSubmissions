//Better approach - less memory
class Solution {
public:
    int rob(vector<int>& nums) {
        
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return nums[0];
        int prev = nums[0], curr = max(nums[0], nums[1]), curr2;
        for(int i=2; i<nums.size(); i++)
        {
            curr2 = max(prev + nums[i], curr);
            prev = curr;
            curr = curr2;
        }
        return curr;
    }
};

/*class Solution {
public:
    int rob(vector<int>& nums) {
        
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return nums[0];
        vector<int> runTot(nums.size());
        runTot[0] = nums[0];
        runTot[1] = max(nums[0], nums[1]);
        for(int i=2; i<nums.size(); i++)
            runTot[i] = max(runTot[i-1], runTot[i-2] + nums[i]);
        return runTot[nums.size() - 1];
    }
};*/