// See this post - https://leetcode.com/problems/perfect-squares/discuss/223357/C%2B%2B-0s-100-math-solution
class Solution {
public:
    int numSquares(int n) {
        
        // Condition for perfect square.
        if(n == (int) sqrt((double)n) * sqrt((double)n))
            return 1;
        // Condition for Lagrange's 4-square theorem
        while(n % 4 == 0)
            n /= 4;
        if(n % 8 == 7)
            return 4;
        // Condition for 2 numbers
        for(int i=0; i*i<n; i++)
        {
            int t = n - i * i;
            if(t == (int) sqrt((double)t) * sqrt((double)t))
                return 2;
        }
        // Else, three numbers
        return 3;
    }
};