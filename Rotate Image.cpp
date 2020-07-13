class Solution {
    void transpose(vector<vector<int>> &m)
    {
        for(int i=0; i<m.size(); i++)
            for(int j=i; j<m[0].size(); j++)
                swap(m[i][j], m[j][i]);
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        for(int i=0; i<matrix.size(); i++)
        {
            int start = 0, end = matrix[i].size() - 1;
            while(start < end)
            {
                swap(matrix[i][start], matrix[i][end]);
                start++, end--;
            }
        }
    }
};