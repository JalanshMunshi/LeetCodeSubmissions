// DP approach - better
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n == 0)
            return matrix;
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX - 100)); //INT_MAX - 100 to avoid overflow.
        // Top-down. First pass for checking the up and left cells.
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
            {
                if(matrix[i][j] == 0)
                    dp[i][j] = 0;
                else
                {
                    if(i - 1 >= 0)
                        dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
                    if(j - 1 >= 0)
                        dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);
                }
            }
        // Bottom-up. Second pass for checking the down and right cells.
        for(int i=n-1; i>=0; i--)
            for(int j=m-1; j>=0; j--)
            {
                if(matrix[i][j] == 0)
                    dp[i][j] = 0;
                else
                {
                    if(i + 1 < n)
                        dp[i][j] = min(dp[i][j], dp[i+1][j] + 1);
                    if(j + 1 < m)
                        dp[i][j] = min(dp[i][j], dp[i][j+1] + 1);
                }
            }
        return dp;
    }
};

// Graph - BFS approach
class Solution {
private:
    vector<vector<int>> ans;
    void bfs(vector<vector<int>> &matrix, int i, int j, int n, int m)
    {
        // int dist = 0;
        // if(matrix[i][j] == 0)
        // {
        //     ans[i][j] = dist;
        //     return;
        // }
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {i, j}});
        while(!q.empty())
        {
            auto t = q.front();
            q.pop();
            int dist = t.first, x = t.second.first, y = t.second.second;
            if(matrix[x][y] == 0)
            {
                ans[i][j] = dist;
                // cout<<x<<" "<<y<<" "<<ans[x][y]<<endl;
                return;
            }
            if(x-1 >= 0)
                q.push({dist + 1, {x - 1, y}});
            if(x+1 < n)
                q.push({dist + 1, {x + 1, y}});
            if(y-1 >= 0)
                q.push({dist + 1, {x, y - 1}});
            if(y+1<m)
                q.push({dist + 1, {x, y + 1}});
        }
    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n == 0)
            return ans;
        int m = matrix[0].size();
        ans = vector<vector<int>>(n, vector<int>(m, INT_MAX));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                bfs(matrix, i, j, n, m);
            }
        }
        return ans;
    }
};