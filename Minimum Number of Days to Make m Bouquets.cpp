class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int n = bloomDay.size(), left = 0, right = 1e9;
        if(m * k > n)
            return -1;
        while(left < right)
        {
            int mid = (left + right) / 2, flowers = 0, bouqs = 0;
            for(int i=0; i<n; i++)
            {
                if(bloomDay[i] > mid)
                    flowers = 0;
                else if(++flowers >= k)
                {
                    bouqs++;
                    flowers = 0;
                }
            }
            if(bouqs < m)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};