class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n <= 1)
            return 0;
        if(n == 2 && prices[1] > prices[0])
            return prices[1] - prices[0];
        else if(n == 2 && prices[1] < prices[0])
            return 0;
        vector<vector<int>> profit(n, vector<int>(2)); // 0 -> no stock, 1 -> has stock
        // Initialising the first 2 days
        profit[0][0] = 0;
        profit[0][1] = -prices[0]; // because if we buy it on first day, then negative loss
        profit[1][0] = max(profit[0][0], profit[0][1] + prices[1]);
        profit[1][1] = max(profit[0][1], profit[0][0] - prices[1]);
        for(int i=2; i<n; i++)
        {
            profit[i][0] = max(profit[i-1][0], profit[i-1][1] + prices[i]);
            profit[i][1] = max(profit[i-1][1], profit[i-2][0] - prices[i]);
        }
        return profit[n-1][0];
    }
};