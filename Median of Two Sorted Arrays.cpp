class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size(), m = nums2.size(), i = 0, j = 0;
        vector<int> v;
        while(i<n && j<m)
        {
            if(nums1[i] <= nums2[j])
            {
                v.push_back(nums1[i]);
                i++;
            }
            else
            {
                v.push_back(nums2[j]);
                j++;
            }
        }
        while(i<n)
        {
            v.push_back(nums1[i]);
            i++;
        }
        while(j<m)
        {
            v.push_back(nums2[j]);
            j++;
        }
        int t = n + m;
        // cout<<t;
        if(t%2 == 0)
            return (double)(v[t/2] + v[t/2 - 1])/2;
        else
            return (double)v[t/2];
    }
};