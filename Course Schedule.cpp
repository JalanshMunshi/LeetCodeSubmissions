class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& preq) {
        
        vector<int> adj[numCourses];
        vector<int> indegs(numCourses, 0);
//         make a adjacency list
        for(auto v : preq)
        {
            adj[v[0]].push_back(v[1]);
            indegs[v[1]]++;
        }
        queue<int> q;
        vector<bool> vis(numCourses, false);
        int ans = 0;
        for(int i=0; i<numCourses; i++)
            if(indegs[i] == 0)
                q.push(i);
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            for(int i=0; i<adj[u].size(); i++)
            {
                indegs[adj[u][i]]--;
                if(indegs[adj[u][i]] == 0)
                    q.push(adj[u][i]);
            }
            ans++;
        }
        return ans == numCourses;
    }
};