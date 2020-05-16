class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        
        int total = 0, maxSub = INT_MIN, minSub = INT_MAX, maxCur = 0, minCur = 0;
        for(int i=0; i<A.size(); i++)
        {
            total += A[i];
            maxCur = max(A[i], maxCur + A[i]);
            minCur = min(A[i], minCur + A[i]);
            maxSub = max(maxSub, maxCur);
            minSub = min(minSub, minCur);
        }
        if(total == minSub)
            return maxSub;
        return max(maxSub, total - minSub);
    }
};