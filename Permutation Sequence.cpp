// Good post for explanation: https://leetcode.com/problems/permutation-sequence/discuss/696595/C%2B%2B-or-Very-Easy-and-Detailed-Explanation-(Idea-%2B-code)
class Solution {
private:
    vector<int>fact = {1,1,2,6,24,120,720,5040,40320,362880};
    void helper(string &ans, vector<int> v, int n, int k)
    {
        if(n == 1)
        {
            ans += ('0' + v.back());
            return;
        }
        int index = k / fact[n - 1];
        if(k % fact[n - 1] == 0)
            index--;
        ans += ('0' + v[index]);
        v.erase(v.begin() + index);
        k -= fact[n - 1] * index;
        helper(ans, v, n-1, k);
    }
public:
    string getPermutation(int n, int k) {
        
        vector<int> v;
        for(int i=1; i<=n; i++)
            v.push_back(i);
        string ans = "";
        helper(ans, v, n, k);
        return ans;
    }
};