// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        
        long start = 1, end = n;
        while(start <= end)
        {
            long mid = (start + end) / 2;
            if(isBadVersion(mid))
                end = mid - 1;
            else
                start = mid + 1;
        }
        return start;
    }
};