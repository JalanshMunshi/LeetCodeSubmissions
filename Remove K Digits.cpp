class Solution {
public:
    string removeKdigits(string num, int k) {
        
        if(num.length() == k)
            return "0";
        stack<char> s;
        for(auto i:num)
        {
            while(k && !s.empty() && int(s.top()) > int(i))
            {
                s.pop();
                k--;
            }
            s.push(i);
        }
        while(k--)
            s.pop();
        stack<char> t;
        while(!s.empty())
        {
            t.push(s.top());
            s.pop();
        }
        while(t.top() == '0' && t.size() != 1)
            t.pop();
        string ans = "";
        while(!t.empty())
        {
            ans += t.top();
            t.pop();
        }
        return ans;
    }
};