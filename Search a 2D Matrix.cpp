class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0)
            return false;
        int x = -1, y = -1, top = 0, bot = matrix.size() - 1, left = 0, right = matrix[0].size() - 1;
        if(right < 0)
            return false;
        while(top <= bot) {
            int mid = (top + bot) / 2;
            if(target >= matrix[mid][0] && target <= matrix[mid][right]) {
                if(target == matrix[mid][0] || target == matrix[mid][right])
                    return true;
                x = mid;
                break;
            }
            else if(target < matrix[mid][0])
                bot = mid - 1;
            else
                top = mid + 1;
        }
        if(x == -1) {
            return false;
        }
        while(left <= right) {
            int mid = (left + right) / 2;
            if(target == matrix[x][mid]) {
                // y = mid;
                return true;
            }
            else if(target < matrix[x][mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        return false;
    }
};