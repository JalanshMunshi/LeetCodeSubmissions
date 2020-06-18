class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        vector<vector<int>> rows(9, vector<int>(9,0));
        vector<vector<int>> cols(9, vector<int>(9,0));
        vector<vector<int>> boxes(9, vector<int>(9,0));
        
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                if(board[i][j] != '.')
                {
                    int t = board[i][j] - '0' - 1;
                    int k = i / 3 * 3 + j / 3;
                    if(rows[t][i] || cols[t][j] || boxes[t][k])
                        return false;
                    rows[t][i] = 1;
                    cols[t][j] = 1;
                    boxes[t][k] = 1;
                }
            }
        }
        return true;
        
    }
};