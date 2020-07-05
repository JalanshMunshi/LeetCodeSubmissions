class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        
        int lmax = -1, rmin = -1;
        if(left.size())
        {
            sort(left.begin(), left.end());
            lmax = left[left.size() - 1];
        }
        if(right.size())
        {
            sort(right.begin(), right.end());
            rmin = right[0];
        }
        if(left.size() == 0 && right.size() == 0)
            return 0;
        if(left.size() == 0)
            return n - rmin;
        if(right.size() == 0)
            return lmax;
        return max(n - rmin, lmax);
    }
};