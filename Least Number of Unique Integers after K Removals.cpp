class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        
        unordered_map<int, int> m;
        
        for(int i : arr)
        {
            m[i]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p;
        for(auto it : m)
            p.push({it.second, it.first});
        int ans = 0;
        // auto it = m.begin();
        while(k > 0)
        {
            if(k >= p.top().first)
            {
                // cout<<p.top().second;
                k -= p.top().first;
                p.pop();
            }
            else
                break;
        }
        return p.size();
        
        
    }
};