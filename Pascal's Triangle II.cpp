class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        if(!rowIndex)
            return {1};
        vector<int> prev, ans;
        ans.push_back(1);
        for(int i=0; i<rowIndex; i++)
        {
            vector<int> temp;
            for(int j=0; j<ans.size(); j++)
            {
                int left = 0;
                if(j)
                    left = ans[j-1];
                temp.push_back(left + ans[j]);
            }
            temp.push_back(1);
            ans = temp;
        }
        return ans;
    }
};

// ---------------Optimized Code------------------
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        vector<int> v(rowIndex+1, 1);
        if(rowIndex == 0 || rowIndex == 1)
            return v;
        for(int i=0; i<=rowIndex; i++)
            for(int j=i-1; j>0; j--)
                v[j] += v[j-1];
        return v;
    }
};