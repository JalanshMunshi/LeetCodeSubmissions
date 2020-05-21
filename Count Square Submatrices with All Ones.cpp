class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        
        int ans = 0, n = matrix.size(), m = matrix[0].size();
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(matrix[i][j] == 1 && i>0 && j>0)
                    matrix[i][j] = min(matrix[i-1][j-1], min(matrix[i-1][j], matrix[i][j-1])) + 1;
                ans += matrix[i][j];
            }
        }
        return ans;
    }
};