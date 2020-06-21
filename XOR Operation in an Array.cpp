class Solution {
public:
    int xorOperation(int n, int start) {
        
        int i = 0, ans = start + 2 * i;
        i++;
        while(i < n)
        {
            ans = ans ^ (start + 2 * i);
            i++;
        }
        return ans;
    }
};