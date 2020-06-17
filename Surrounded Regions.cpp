class Solution {
private:
    void floodFill(vector<vector<char>> &board, int i, int j, char prev, char curr)
    {
        if(i < 0 || i >= board.size() ||
          j < 0 || j >= board[0].size())
            return;
        if(board[i][j] != prev)
            return;
        
        board[i][j] = curr;
        cout<<board[i][j]<<endl;
        floodFill(board, i, j-1, prev, curr);
        floodFill(board, i, j+1, prev, curr);
        floodFill(board, i-1, j, prev, curr);
        floodFill(board, i+1, j, prev, curr);
    }
public:
    void solve(vector<vector<char>>& board) {
        
        int n = board.size();
        if(n == 0)
            return;
        int m = board[0].size();
        // replace the O's with *
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(board[i][j] == 'O')
                    board[i][j] = '*';
        // conditional flood fill on the edges
        for(int i=0; i<n; i++)
        {
            if(board[i][0] == '*')
                floodFill(board, i, 0, '*', 'O');
            if(board[i][m-1] == '*')
                floodFill(board, i, m-1, '*', 'O');
        }
        for(int i=0; i<m; i++)
        {
            if(board[0][i] == '*')
                floodFill(board, 0, i, '*', 'O');
            if(board[n-1][i] == '*')
                floodFill(board, n-1, i, '*', 'O');
        }
        // Replace the * with X
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(board[i][j] == '*')
                    board[i][j] = 'X';
    }
};