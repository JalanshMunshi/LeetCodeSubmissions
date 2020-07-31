class Solution {
public:
    int climbStairs(int n) {
        if(n == 1)
            return 1;
        if(n == 2)
            return 2;
        int cur = 2, prev = 1;
        for(int i=3; i<=n; i++)
        {
            int t = cur + prev;
            prev = cur;
            cur = t;
        }
        return cur;
    }
};