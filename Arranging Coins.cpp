class Solution {
public:
    int arrangeCoins(int n) {
        
        int start = 0, end = n, ans = 0;
        while(start <= end)
        {
            long mid = (start + end) / 2;
            long t = (mid * (mid + 1)) / 2;
            if(t <= n)
            {
                ans = mid;
                start = mid + 1;
            }
            else
                end = mid - 1;
        }
    return ans;
    }
};