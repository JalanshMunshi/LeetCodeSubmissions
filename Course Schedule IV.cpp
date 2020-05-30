class Solution {
public:
    bool bfs(vector<int> adj[], int n, int src, int dest)
    {
        vector<bool> vis(n, false);
        vis[src] = true;
        queue<int> q;
        q.push(src);
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            for(int i=0; i<adj[u].size(); i++)
            {
                if(vis[adj[u][i]] == false)
                {
                    q.push(adj[u][i]);
                    vis[adj[u][i]] = true;
                    if(adj[u][i] == dest)
                        return true;
                }
            }
        }
        return false;
    }
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& preq, vector<vector<int>>& queries) {
        
        vector<int> adj[n];
        for(auto v : preq)
        {
            adj[v[0]].push_back(v[1]);
        }
        vector<bool> ans;
        for(auto v : queries)
        {
            int src = v[0], dest = v[1];
            if(bfs(adj, n, src, dest))
                ans.push_back(true);
           else
               ans.push_back(false);
       }
        return ans;
    }
};