class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        
        map<int, vector<int>> m;
        for(int i=1; i<15; i++)
        {
            vector<int> curr(cells.size());
            for(int j=1; j<7; j++)
                curr[j] = cells[j - 1] == cells[j + 1] ? 1 : 0;
            cells = curr;
            m[i] = curr;
        }
        return m[N % 14 == 0 ? 14 : N % 14];
    }
};