class Solution {
public:
    void helper(unordered_map<int, string> m, string digits, vector<string> &ans, int len, string s, int index)
    {
        if(len <= 0) //last digit characters
        {
            ans.push_back(s);
            return;
        }
        string str = m[digits[index] - '0'];
        for(int i=0; i<str.length(); i++)
        {
            // Append the chars and calling the helper function recursively
            s += str[i]; 
            helper(m, digits, ans, len - 1, s, index + 1);
            // Remove the last character as it has already been counted
            s = s.substr(0, s.length() - 1);
        }
    }
    
    unordered_map<int, string> map_initialize()
    {
        unordered_map<int, string> m;
        m[2] = "abc";
        m[3] = "def";
        m[4] = "ghi";
        m[5] = "jkl";
        m[6] = "mno";
        m[7] = "pqrs";
        m[8] = "tuv";
        m[9] = "wxyz";
        
        return m;
    }
    
    vector<string> letterCombinations(string digits) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        unordered_map<int, string> m = map_initialize();
        int len = digits.length();
        vector<string> ans;
        if(!len)
            return ans;
        helper(m, digits, ans, len, "", 0);
        return ans;
    }
};