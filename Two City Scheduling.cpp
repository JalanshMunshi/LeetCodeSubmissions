class Solution {
public:
    static bool comparator(vector<int> a, vector<int> b)
    {
        return a[1] - a[0] > b[1] - b[0];
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        sort(costs.begin(), costs.end(), comparator);
        int ans = 0, i = 0, j = costs.size() - 1;
        while(i < j)
            ans += costs[i++][0] + costs[j--][1];
        return ans;
    }
};