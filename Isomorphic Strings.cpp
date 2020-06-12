class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        unordered_map<char, int> m; //mapping from s to t
        unordered_map<char, bool> vis; //to check if the char from t is visited or not
        for(int i=0; i<s.length(); i++)
        {
            if(m.find(s[i]) == m.end())
            {
                if(vis.find(t[i]) != vis.end())
                    return false;
                vis[t[i]] = true;
                m[s[i]] = t[i];
            }
            else if(m[s[i]] != t[i])
                    return false;
        }
        return true;
    }
};