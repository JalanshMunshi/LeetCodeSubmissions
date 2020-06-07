class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        
        sort(arr.begin(),  arr.end());
        int n = arr.size(), median;
        median = arr[(n-1)/2];
        priority_queue<pair<int, int>> p;
        vector<int> ans;
        int i = 0, j = n - 1, t = k;
        if(k == 1)
        {
            ans.push_back(arr[j]);
            return ans;
        }
        while(i <= j)
        {
            if(abs(arr[j] - median) < abs(arr[i] - median))
            {
                p.push({t--, arr[i]});
                i++;
            }
            else
            {
                p.push({t--, arr[j]});
                j--;
            }
        }
        while(k--)
        {
            ans.push_back(p.top().second);
            p.pop();
        }
        return ans;
    }
};