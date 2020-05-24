class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if(prices.size() == 0)
            return 0;
        int buy = prices[0], sell = -1, profit = 0;
        for(int i=1; i<prices.size(); i++)
        {
            if(prices[i] < buy)
            {
                buy = prices[i];
                sell = -1;
            }
            else
            {
                if(prices[i] > sell)
                    sell = prices[i];
                if(sell - buy > profit)
                    profit = sell - buy;
            }
        }
        return profit;
    }
};