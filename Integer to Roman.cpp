class Solution {
public:
    string intToRoman(int num) {
        
        string ans = "";
        vector<int> nums{1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        vector<string> syms{"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        int i = 12;
        while(num>0)
        {
            int q = num/nums[i];
            num = num%nums[i];
            while(q--)
                ans += syms[i];
            i--;
        }
        return ans;
    }
};