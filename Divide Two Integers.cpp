class Solution {
public:
    int divide(int dividend, int divisor) {
        
        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
        long dd = labs(dividend), dv = labs(divisor), ans = 0;
        while(dd >= dv)
        {
            long t = dv, c = 1;
            while(t << 1 <= dd)
            {
                t <<= 1;
                c <<= 1;
            }
            dd -= t;
            ans += c;
        }
        return sign*ans;
    }
};