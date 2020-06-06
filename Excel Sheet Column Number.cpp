class Solution {
public:
    int titleToNumber(string s) {
        
        int ans = 0;
        for(int i=s.length()-1; i>=0; i--)
        {
            ans += (int)pow(26, s.length() - i - 1)*(s[i] - 'A' + 1);
        }
        return ans;
    }
};