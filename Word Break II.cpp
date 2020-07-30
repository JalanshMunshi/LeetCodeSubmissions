class Solution {
private:
    vector<string> helper(string s, int n, set<string> dict, int maxLen, map<int, vector<string>> &m)
    {
        if(m.count(n))
            return m[n];
        string str = "";
        for(int i=n; i<s.length() && str.length() <= maxLen; i++)
        {
            str += s[i];
            if(dict.count(str))
            {
                if(i == s.length() - 1) // parsed all chars
                    m[n].push_back(str);
                else
                {
                    vector<string> t = helper(s, i+1, dict, maxLen, m);
                    for(string st : t)
                        m[n].push_back(str + " " + st);
                }
            }
        }
        return m[n];
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set<string> dict;
        int maxLen = 0;
        for(string t : wordDict)
        {
            dict.insert(t);
            maxLen = max(maxLen, (int) t.length());
        }
        map<int, vector<string>> m;
        return helper(s, 0, dict, maxLen, m);
    }
};