class Solution {
public:
    int hIndex(vector<int>& cits) {
        
        if(cits.size() == 0)
            return 0;
        int n = cits.size(), start = 0, end = n - 1, ans = -1;
        while(start <= end)
        {
            int mid = (start + end) / 2, h = n - mid;
            if(cits[mid] >= h)
            {
                ans = max(h, ans);
                end = mid - 1;
            }
            else
                start = mid + 1;
        }
        return ans == -1 ? 0 : ans;
    }
};