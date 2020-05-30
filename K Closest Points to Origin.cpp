class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<vector<int>> ans;
        
        for(int i=0; i<points.size(); i++)
        {
            int x = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            pq.push({x, i});
        }
        while(K--)
        {
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }
        while(!pq.empty())
            pq.pop();
        return ans;
    }
};