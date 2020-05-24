class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        
        vector< vector<int> > ans;
        int a = 0, b = 0;
        while(a<A.size() && b<B.size())
        {
            int start = max(A[a][0], B[b][0]);
            int end = min(A[a][1], B[b][1]);
            if(start <= end)
            {
                vector<int> temp;
                temp.push_back(start);
                temp.push_back(end);
                ans.push_back(temp);
            }
            if(A[a][1] < B[b][1])
                a++;
            else
                b++;
        }
        return ans;
    }
};