class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        
        unordered_map<string, int> m;
        vector<string> ans;
        for(string s : names)
        {
            int i = m[s];
            string t = s;
            while(m[t] > 0)
            {
                t = s + '(' + to_string(i++) + ')';
                m[s] = i;
            }
            m[t]++;
            ans.push_back(t);
        }
        return ans;
    }
};