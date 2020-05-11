class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int> > ans;
        if(numRows == 0)
            return ans;
        ans.push_back({1});
        for(int i=0; i<numRows-1; i++)
        {
            vector<int> temp;
            for(int j=0; j<ans[i].size(); j++)
            {
                int left = 0;
                if(j)
                    left = ans[i][j-1];
                temp.push_back(left + ans[i][j]);
            }
            temp.push_back(1);
            ans.push_back(temp);
        }
        return ans;
    }
};