class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xors = 0;
        for(int i : nums)
            xors ^= i;
        int lowestSetBit = xors & (-xors), a = 0, b = 0;
        for(int i : nums)
        {
            if((i & lowestSetBit) == 0)
                a ^= i;
            else
                b ^= i;
        }
        return {a, b};
    }
};