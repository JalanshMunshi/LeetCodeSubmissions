class Solution {
public:
    bool isAlphaNumeric(char c)
    {
        if((c>='0' && c<='9') ||
          (c>='a' && c<='z') ||
          (c>='A' && c<='Z'))
            return true;
        return false;
    }
    bool isPalindrome(string s) {
        
        if(s.length() == 0)
            return true;
        string str = "";
        for(int i=0; i<s.length(); i++)
        {
            if(isAlphaNumeric(s[i]))
                str += tolower(s[i]);
        }
        string temp = str;
        reverse(str.begin(), str.end());
        return str.compare(temp) == 0;
    }
};