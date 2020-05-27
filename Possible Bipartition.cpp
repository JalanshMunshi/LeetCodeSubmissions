class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        
        vector<int> adj[N+1];
        for(int i=0; i<dislikes.size(); i++)
        {
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        vector<int> color(N+1, -1);
        
        for(int i=1; i<=N; i++)
        {
            if(color[i] == -1)
            {
                queue<int> q;
                q.push(i);
                color[i] = 1;
                while(!q.empty())
                {
                    int u = q.front();
                    q.pop();
                    for(int j=0; j<adj[u].size(); j++)
                    {
                        if(color[adj[u][j]] == -1)
                        {
                            q.push(adj[u][j]);
                            color[adj[u][j]] = 1 - color[u];
                        }
                        else if(color[adj[u][j]] == color[u])
                            return false;
                    }
                }
            }
        }
        return true;
    }
};