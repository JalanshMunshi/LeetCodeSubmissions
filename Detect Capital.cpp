class Solution {
public:
    bool detectCapitalUse(string word) {
        bool allCaps = true, allSmall = true, firstCap = true;
        for(char c : word)
        {
            if(allCaps && !(c >= 'A' && c <= 'Z'))
            {
                allCaps = false;
            }
            if(allSmall && !(c >= 'a' && c <= 'z'))
            {
                allSmall = false;
            }
        }
        if(allCaps || allSmall)
            return allCaps | allSmall;
        if(word[0] >= 'A' && word[0] <= 'Z')
            firstCap = true;
        allSmall = true;
        for(int i=1; i<word.length(); i++)
            if(!(word[i] >= 'a' && word[i] <= 'z'))
            {
                allSmall = false;
                break;
            }
        return firstCap & allSmall;
    }
};