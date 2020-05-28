class Solution {
public:
    void bfs(vector<vector<int>> adj, vector<bool> &vis, int src)
    {
        queue<int> q;
        q.push(src);
        vis[src] = true;
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            for(int i=0; i<adj[u].size(); i++)
            {
                if(adj[u][i] == 1 && vis[i] == false)
                {
                    q.push(i);
                    vis[i] = true;
                }
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& M) {
        
        int ans = 0;
        vector<bool> vis(M.size(), false);
        for(int i=0; i<M.size(); i++)
        {
            if(vis[i] == false)
            {
                bfs(M, vis, i);
                ans++;
            }
        }
        return ans;
    }
};