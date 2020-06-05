class Solution {
public:
    string convertToTitle(int n) {
        
        string ans = "";
        while(n)
        {
            int r = n % 26;
            n /= 26;
            if(!r)
            {
                r = 26;
                n--;
            }
            ans += 'A' + r - 1;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};