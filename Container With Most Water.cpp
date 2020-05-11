class Solution {
public:
    int maxArea(vector<int>& height) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(!height.size())
            return 0;
        int l = 0, r = height.size() - 1;
        int ans = 0;
        while(l < r)
        {
            int area = (r - l)*min(height[l], height[r]);
            ans = max(ans, area);
            if(height[l] < height[r])
                l++;
            else
                r--;
        }
        return ans;
    }
};