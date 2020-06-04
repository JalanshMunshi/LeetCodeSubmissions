// Better approach - O(log(min(x, y))) | space - O(1)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         Binary Search implementation
        
        if(nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1); //to ensure nums1 is the array with smaller size
        int x = nums1.size(), y = nums2.size();
        int low = 0, high = x;
        while(low <= high)
        {
            int partitionX = (low + high) / 2;
            int partitionY = (x + y + 1) / 2 - partitionX;
            
//             use INT_MIN if there are no elements to the left of partitionX
            int maxLeftX = partitionX == 0 ? INT_MIN : nums1[partitionX - 1];
            int minRightX = partitionX == x ? INT_MAX : nums1[partitionX];
            
            int maxLeftY = partitionY == 0 ? INT_MIN : nums2[partitionY - 1];
            int minRightY = partitionY == y ? INT_MAX : nums2[partitionY];
            
            if(maxLeftX <= minRightY && maxLeftY <= minRightX) //median found!
            {
                if((x + y) % 2 == 0)
                    return ((double) max(maxLeftX, maxLeftY) + min(minRightX, minRightY))/2;
                else
                    return (double) max(maxLeftX, maxLeftY);
            }
            else if(maxLeftX > minRightY) //too right in nums1
                high = partitionX - 1;
            else //too left in nums1
                low = partitionX + 1;
        }
        return -1;
    }
};

// Brute force method - O(x + y) | Spacae - O(x + y)
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