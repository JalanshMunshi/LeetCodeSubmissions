class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int n = word2.length(), m = word1.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1));
        for(int i=0; i<=n; i++)
            for(int j=0; j<=m; j++)
            {
                if(i==0)
                    dp[i][j] = j;
                else if(j==0)
                    dp[i][j] = i;
                else
                {
                    if(word1[j-1] == word2[i-1])
                        dp[i][j] = dp[i-1][j-1];    
                    else
                        dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]));
                }
            }
        return dp[n][m];
    }
};