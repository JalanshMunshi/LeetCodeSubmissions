class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        
        for(int i=0; i<prices.size(); i++)
        {
            int disc = 0;
            for(int j = i+1; j<prices.size(); j++)
            {
                if(prices[j] <= prices[i])
                {
                    disc = prices[j];
                    break;
                }
            }
            prices[i] -= disc;
        }
        return prices;
    }
};