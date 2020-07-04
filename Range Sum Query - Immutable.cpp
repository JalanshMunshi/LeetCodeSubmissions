class NumArray {
    vector<int> cumulative;
    vector<int> v;
public:
    NumArray(vector<int>& nums) {
        cumulative = vector<int>(nums.size());
        v = nums;
        if(nums.size() > 0)
        {
            cumulative[0] = nums[0];
            for(int i=1; i<nums.size(); i++)
                cumulative[i] = cumulative[i - 1] + nums[i];
        }
    }
    
    int sumRange(int i, int j) {
        return cumulative[j] - cumulative[i] + v[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */