class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        vector<int> parent(2000);
        for(int i=0; i<parent.size(); i++)
            parent[i] = i;
        vector<int> ans;
        for(auto v : edges)
        {
            int n1 = v[0], n2 = v[1];
            while(n1 != parent[n1])
                n1 = parent[n1];
            while(n2 != parent[n2])
                n2 = parent[n2];
            if(n1 == n2)
                ans = v;
            else
                parent[n1] = n2;
        }
        return ans;
    }
};