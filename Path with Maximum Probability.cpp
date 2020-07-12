class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        vector<vector<pair<int, double>>> adj(n);
        for(int i=0; i<edges.size(); i++)
        {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        vector<double> probs(n, 0);
        probs[start] = 1.0;
        priority_queue<pair<double, int>> q;
        q.push({1.0, start});
        while(!q.empty())
        {
            int v = q.top().second;
            double p = q.top().first;
            q.pop();
            for(auto it : adj[v])
            {
                int verti = it.first;
                double prob = it.second;
                if(probs[verti] < probs[v] * prob)
                {
                    probs[verti] = probs[v] * prob;
                    q.push({probs[verti], verti});
                }
            }
        }
        return probs[end];
    }
};