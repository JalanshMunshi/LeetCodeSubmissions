class Solution {
public:
    bool isPathCrossing(string path) {
        
        pair<int, int> loc = {0, 0};
        set<pair<int, int>> vis;
        vis.insert(loc);
        bool ans = false;
        for(char c : path)
        {
            if(c == 'N')
            {
                loc.second++;
                if(vis.find(loc) != vis.end())
                    ans = true;
                else
                    vis.insert(loc);
            }
            else if(c == 'S')
            {
                loc.second--;
                if(vis.find(loc) != vis.end())
                    ans = true;
                else
                    vis.insert(loc);
            }
            else if(c == 'E')
            {
                loc.first++;
                if(vis.find(loc) != vis.end())
                    ans = true;
                else
                    vis.insert(loc);
            }
            else
            {
                loc.first--;
                if(vis.find(loc) != vis.end())
                    ans = true;
                else
                    vis.insert(loc);
            }
        }
        return ans;
    }
};