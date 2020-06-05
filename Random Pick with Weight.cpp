class Solution {
    private: vector<int> weights;
    private: int sum = 0;
    public: Solution(vector<int>& w) {
        
        for(int i=0; i<w.size(); i++)
        {
            sum += w[i];
            weights.push_back(sum);
        }
    }
    
    public: int pickIndex() {
        
        int r = rand() % sum + 1; // generate a random number between 1 to sum.
        return binarySearch(r);
    }
    private: int binarySearch(int val)
    {
        int low = 0, high = weights.size() - 1;
        while(low < high)
        {
            int mid = (low + high) / 2;
            if(val > weights[mid])
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */