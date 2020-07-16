class Solution {
private:
    static bool comparator(vector<int> a, vector<int> b)
    {
        return a[0] < b[0];
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 0 || intervals.size() == 1)
            return intervals;
        sort(intervals.begin(), intervals.end(), comparator);
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(int i=1; i<intervals.size(); i++)
        {
            int t = ans.size() - 1;
            if(ans[t][1] >= intervals[i][0] && ans[t][1] >= intervals[i][1])
                continue;
            if(ans[t][1] >= intervals[i][0])
                ans[t][1] = intervals[i][1];
            else
                ans.push_back(intervals[i]);
        }
        return ans;
    }
};