class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        int n = A.size(), ans = 0;
        vector<int> sums(n + 1);
        for(int i=0; i<n; i++)
            sums[i+1] = sums[i] + A[i];
        map<int, int> m;
        for(int i : sums)
        {
            ans += m[i];
            m[i + S] += 1;
        }
        return ans;
    }
};