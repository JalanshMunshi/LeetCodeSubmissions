class Solution {
private:
    void helper(vector<int> &cans, int target, vector<int> currComb, vector<vector<int>> &ans, int start)
    {
        if(!target)
        {
            ans.push_back(currComb);
            return;
        }
        for(int i=start; i<cans.size() && target >= cans[i]; i++)
        {
            if(i == start || cans[i] != cans[i-1])
            {
                currComb.push_back(cans[i]);
                helper(cans, target - cans[i], currComb, ans, i + 1);
                currComb.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& cans, int target) {
        sort(cans.begin(), cans.end());
        vector<vector<int>> ans;
        vector<int> currComb;
        helper(cans, target, currComb, ans, 0);
        return ans;
    }
};