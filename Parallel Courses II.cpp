class Solution {
    static bool comparator(int a, int b)
    {
        return a > b;
    }
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k) {
        
        if(dependencies.size() == 0)
            return (n / k) + (n % k);
        map<int, vector<int>> adj;
        vector<int> indeg(n, 0);
        for(auto v : dependencies)
        {
            adj[v[0]].push_back(v[1]);
            indeg[v[1] - 1]++;
        }
        queue<int> q;
        // push all vertices/subject with in degree 0 to the queue
        for(int i=0; i<n; i++)
            if(indeg[i] == 0)
                q.push(i + 1);
        int sems = 0;
        while(!q.empty())
        {
            sems++;
            queue<int> qt;
            for(int i=0; i<k; i++)
            {
                if(q.empty())
                    break;
                int f = q.front();
                q.pop();
                sort(adj[f].begin(), adj[f].end(), comparator);
                for(int j : adj[f])
                {
                    indeg[j - 1]--;
                    if(indeg[j - 1] == 0)
                        qt.push(j);
                }
            }
            while(!qt.empty())
            {
                q.push(qt.front());
                qt.pop();
            }
        }
        return sems;
    }
};