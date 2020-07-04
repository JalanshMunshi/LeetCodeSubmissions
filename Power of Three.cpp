// Better approach. Mathematically oriented. Check out https://leetcode.com/problems/power-of-three/solution/
class Solution {
public:
    bool isPowerOfThree(int n) {
        
        if(n <= 0)
            return false;
        double t = (log10(n) / log10(3));
        return floor(t) == ceil(t);
        // Or just simply write one line of code
        // return n > 0 && 1162261467 % n == 0;
    }
};

// Normal approach
class Solution {
public:
    bool isPowerOfThree(int n) {
        
        while(n > 3)
        {
            if(n % 3 != 0)
                return false;
            n /= 3;
        }
        return n == 3 || n == 1 ? true : false;
    }
};