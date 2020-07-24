class Solution {
private:
    vector<vector<int>> adj;
    vector<bool> vis;
    void dfs(vector<vector<int>> &ans, vector<int> path, int src, int dest)
    {
        if(src == dest)
            ans.push_back(path);
        else
        {
            vis[src] = true;
            for(int i : adj[src])
            {
                if(vis[i] == false)
                {
                    path.push_back(i);
                    dfs(ans, path, i, dest);
                    path.pop_back();
                }
            }
            vis[src] = false;
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        adj = vector<vector<int>>(n);
        vis = vector<bool>(n, false);
        for(int i=0; i<n; i++)
            for(int j : graph[i])
                adj[i].push_back(j);
        int src = 0, dest = n - 1;
        vector<vector<int>> ans;
        vector<int> path;
        path.push_back(src);
        dfs(ans, path, src, dest);
        return ans;
    }
};