class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        
        int ans = 0;
        for(int i=0; i<target.size(); i++)
        {
            ans ^= target[i];
            ans ^= arr[i];
        }
        return ans == 0;
    }
};