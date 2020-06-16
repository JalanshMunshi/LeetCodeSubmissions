class Solution {
public:
    string validIPAddress(string IP) {
        
        string v4 = "IPv4", v6 = "IPv6", none = "Neither";
        bool fv4 = false, fv6 = false;
        if(IP.find('.') != string::npos)
            fv4 = true;
        if(IP.find(':') != string::npos)
            fv6 = true;
        if((fv4 && fv6) || (!fv4 && !fv6))
            return none;
        char arr[IP.size() + 1];
        for(int i=0; i<IP.size(); i++)
            arr[i] = IP[i];
        arr[IP.size()] = '\0';
        
        if(fv4) //ipv4 suspect
        {
            if(IP[0] == '.' || 
               IP[IP.size() - 1] == '.' || 
               count(IP.begin(), IP.end(), '.') != 3)
                return none;
            vector<string> v;
            char *str = strtok(arr, ".");
            while(str)
            {
                v.push_back(str);
                str = strtok(NULL, ".");
            }
            if(v.size() != 4)
                return none;
            for(string s : v)
            {
                if(s.length()>3 || 
                   (s[0] == '0' && s.length() > 1))
                    return none;
                else
                {
                    int val = 0;
                    for(int j=0; j<s.length(); j++)
                        val = 10 * val + (s[j] - '0');
                    if(val < 0 || val > 255)
                        return none;
                }
            }
            return v4;
        }
        else if(fv6)
        {
            if(IP[0] == ':' || 
               IP[IP.size() - 1] == ':' || 
               count(IP.begin(), IP.end(), ':') != 7)
                return none;
            vector<string> v;
            char *str = strtok(arr, ":");
            while(str)
            {
                v.push_back(str);
                str = strtok(NULL, ":");
            }
            if(v.size() != 8)
                return none;
            for(string s : v)
            {
                if(s.length()>4)
                    return none;
                else
                {
                    for(int j=0; j<s.length(); j++)
                    {
                        if(!(isdigit(s[j])) &&
                          (s[j]  < 'a' || s[j] > 'f') &&
                          (s[j] < 'A' || s[j] > 'F'))
                            return none;
                    }
                }
            }
            return v6;
        }
        return none;
    }
};