class Solution {
public:
    int numSub(string s) {
        int mod = 1e9 + 7;
        vector<int> dp(s.length() + 1, 1);
        dp[0] = 0, dp[1] = 1;
        for(int i=2; i<=s.length(); i++)
            dp[i] = (dp[i - 1] % mod) + (i * dp[i]) % mod;
        int len = 0, ans = 0;
        for(int i=0; i<s.length(); i++)
        {
            len = 0;
            while(i<s.length() && s[i] == '1')
                len++, i++;
            if(len)
                ans += dp[len];
        }
        return ans;
    }
};