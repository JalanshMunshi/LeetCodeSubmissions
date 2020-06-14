class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        
        vector<int> cost(n, INT_MAX);
        cost[src] = 0;
        for(int i=0; i<=K; i++)
        {
            vector<int> temp = cost;
            for(auto v : flights)
            {
                int s = v[0], d = v[1], weight = v[2];
                if(cost[s] == INT_MAX)
                    continue;
                temp[d] = min(temp[d], cost[s] + weight);
            }
            cost = temp;
        }
        return cost[dst] == INT_MAX ? -1 : cost[dst];
    }
};