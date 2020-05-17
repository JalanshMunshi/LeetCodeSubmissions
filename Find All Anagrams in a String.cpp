class Solution {
public:
    bool countCompare(vector<int> patCount, vector<int> winCount)
    {
        for(int i=0; i<26; i++)
            if(patCount[i] != winCount[i])
                return false;
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        
        int sLen = s.length(), pLen = p.length();
        vector<int> patCount(26, 0), winCount(26, 0); //pattern count and current window count
        for(int i=0; i<pLen; i++)
            patCount[p[i] - 'a']++;
        vector<int> ans;
        int curLen = 0;
        for(int i=0; i<sLen; i++)
        {
            curLen++;
            winCount[s[i] - 'a']++;
            if(curLen > pLen)
            {
                curLen--;
                winCount[s[i - curLen] - 'a']--;
            }
            bool flag = true;
            if(countCompare(patCount, winCount))
                ans.push_back(i - curLen + 1);
        }
        return ans;
    }
};