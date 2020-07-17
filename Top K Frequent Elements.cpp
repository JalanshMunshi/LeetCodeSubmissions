class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;
        for(int i : nums)
            m[i]++;
        priority_queue<pair<int, int>> q;
        for(auto it : m)
            q.push({it.second, it.first});
        vector<int> ans;
        while(k--)
            ans.push_back(q.top().second), q.pop();
        return ans;
    }
};