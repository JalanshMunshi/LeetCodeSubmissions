// O(log n) solution
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int start = 0, end = nums.size() - 1;
        vector<int> ans(2, -1);
        if(nums.size() == 0)
            return ans;
        if(nums.size() == 1)
        {
            ans[0] = target == nums[0] ? 0 : -1;
            ans[1] = ans[0];
            return ans;
        }
        // Binary Search for the first index
        int first = -1, last = -1;
        while(start <= end)
        {
            int mid = (start + end) / 2;
            if(nums[mid] > target)
                end = mid - 1;
            else if(nums[mid] < target)
                start = mid + 1;
            else
            {
                first = mid;
                end = mid - 1;
            }
        }
        // Binary Search for the last index
        start = 0, end = nums.size() - 1;
        while(start <= end)
        {
            int mid = (start + end) / 2;
            if(nums[mid] > target)
                end = mid - 1;
            else if(nums[mid] < target)
                start = mid + 1;
            else
            {
                last = mid;
                start = mid + 1;
            }
        }
        ans[0] = first;
        ans[1] = last;
        return ans;
    }
};

// The initial code that I submitted. O(n), but accepted
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int start = 0, end = nums.size() - 1;
        vector<int> ans(2, -1);
        if(nums.size() == 0)
            return ans;
        if(nums.size() == 1)
        {
            ans[0] = target == nums[0] ? 0 : -1;
            ans[1] = target == nums[0] ? 0 : -1;
            return ans;
        }
        while(start <= end)
        {
            int mid = (start + end) / 2;
            if(nums[mid] == target)
            {
                int first = mid, last = mid;
                while(first>0 && nums[first - 1] == nums[mid])
                    first--;
                while(last<nums.size()-1 && nums[last + 1] == nums[mid])
                    last++;
                ans[0] = first;
                ans[1] = last;
                return ans;
            }
            else if(nums[mid] > target)
                end = mid -  1;
            else
                start = mid + 1;
        }
        return ans;
    }
};