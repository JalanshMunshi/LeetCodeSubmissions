class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int left = 0, right = n - 1, top = 0, bottom = n - 1, dir = 0, t = 1;
        vector<vector<int>> ans(n, vector<int>(n));
        while(left <= right && top <= bottom)
        {
            if(dir == 0) //left to right
            {
                for(int i=left; i<=right; i++)
                {
                    ans[top][i] = t;
                    t++;
                }
                top++;
            }
            else if(dir == 1) //top to bottom
            {
                for(int i=top; i<=bottom; i++)
                {
                    ans[i][right] = t;
                    t++;
                }
                right--;
            }
            else if(dir == 2) //right to left
            {
                for(int i=right; i>=left; i--)
                {
                    ans[bottom][i] = t;
                    t++;
                }
                bottom--;
            }
            else //bottom to top
            {
                for(int i=bottom; i>=top; i--)
                {
                    ans[i][left] = t;
                    t++;
                }
                left++;
            }
            dir = (dir + 1) % 4;
        }
        return ans;
    }
};