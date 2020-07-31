class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        if(n == 0)
            return 0;
        int m = obstacleGrid[0].size();
        vector<vector<int>> paths(n, vector<int>(m, 0));
        paths[0][0] = obstacleGrid[0][0] == 1 ? -1 : 1;
        for(int i=1; i<m; i++)
            paths[0][i] = paths[0][i-1] == -1 || obstacleGrid[0][i] == 1 ? -1 : 1;
        for(int i=1; i<n; i++)
            paths[i][0] = paths[i-1][0] == -1 || obstacleGrid[i][0] == 1 ? -1 : 1;
        for(int i=1; i<n; i++)
        {
            for(int j=1; j<m; j++)
            {
                if(obstacleGrid[i][j] == 1)
                    paths[i][j] = -1;
                else
                {
                    if(paths[i][j-1] != -1)
                        paths[i][j] += paths[i][j-1];
                    if(paths[i-1][j] != -1)
                        paths[i][j] += paths[i-1][j];
                }
            }
        }
        return paths[n-1][m-1] == -1 ? 0 : paths[n-1][m-1];
    }
};