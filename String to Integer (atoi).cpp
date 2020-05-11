class Solution {
public:
    int myAtoi(string str) {
        
        int len = str.length();
        if(len == 0 || isalpha(str[0]))
            return 0;
        int i=0;
        while(str[i] == ' ')
            i++;
        if(i >= len)
            return 0;
        if(isalpha(str[i]))
            return 0;
        else
        {
            int ans;
            stringstream ss;
            ss << str;
            ss >> ans;
            return ans;
        }
        return 0;
    }
};