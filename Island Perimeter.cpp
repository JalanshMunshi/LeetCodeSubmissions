class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        
        int peri = 0, n = grid.size();
        if(n == 0)
            return peri;
        int m = grid[0].size();
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
            {
                if(grid[i][j])
                {
                    if(i-1 < 0)
                        peri++;
                    else if(grid[i-1][j] == 0)
                        peri++;
                    if(i+1 > n-1)
                        peri++;
                    else if(grid[i+1][j] == 0)
                        peri++;
                    if(j-1 < 0)
                        peri++;
                    else if(grid[i][j-1] == 0)
                        peri++;
                    if(j+1 > m-1)
                        peri++;
                    else if(grid[i][j+1] == 0)
                        peri++;
                }
            }
        return peri;
    }
};