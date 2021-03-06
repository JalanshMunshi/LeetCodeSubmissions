class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        vector<int> ans(amount + 1);
        ans[0] = 1;
        for(int i=0; i<coins.size(); i++)
            for(int j=coins[i]; j<=amount; j++)
                ans[j] += ans[j - coins[i]];
        return ans[amount];
    }
};