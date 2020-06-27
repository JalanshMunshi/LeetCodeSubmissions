class Solution {
public:
    string getHint(string secret, string guess) {
        
        string ans = "";
        map<char, int> m;
        for(int i=0; i<secret.length(); i++)
            m[secret[i]]++;
        int b = 0, c = 0;
        // A bit faster approach is to calculate bulls in the first loop itself.
        for(int i=0; i<guess.length(); i++)
        {
            if(guess[i] == secret[i])
            {
                b++;
                m[guess[i]]--;
            }
        }
        for(int i=0; i<guess.length(); i++)
        {
            if(guess[i] != secret[i] && m.find(guess[i]) != m.end()) //present in the secret but not at the correct index
            {
                if(m[guess[i]] > 0)
                {
                    c++;
                    m[guess[i]]--;
                }
            }
        }
        ans += to_string(b) + 'A' + to_string(c) + 'B';
        return ans;
    }
};