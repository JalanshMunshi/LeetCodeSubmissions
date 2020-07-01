// Read this post - https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/discuss/197668/Count-the-Number-of-Islands-O(N)
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        
        for(auto v : stones)
            Union(v[0], 10000 + v[1]);
        return stones.size() - components;
    }
private:
    map<int, int> parent;
    int components = 0;
    
    int find(int x)
    {
        if(parent.count(x) == 0)
        {
            parent[x] = x;
            components++;
        }
        if(x != parent[x])
            parent[x] = find(parent[x]);
        return parent[x];
    }
    
    void Union(int x, int y)
    {
        x = find(x);
        y = find(y);
        if(x != y)
        {
            parent[x] = y;
            components--;
        }
    }
};