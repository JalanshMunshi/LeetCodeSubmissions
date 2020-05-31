class Solution {
public:
    void dfs(vector<vector<int>> &adj, int src, int &ans, vector<bool> &vis)
    {
        vis[src] = true;
        for(auto i : adj[src])
        {
            if(vis[i] == false)
            {
                ans++;
                dfs(adj, i, ans, vis);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        
        vector<vector<int>> adj(n);
        for(auto v : connections)
            adj[v[0]].push_back(v[1]);
        vector<bool> vis(n, false);
        int ans = 0;
        for(int i=0; i<n; i++)
            if(vis[i] == false)
                dfs(adj, i, ans, vis);
        return ans;
    }
};