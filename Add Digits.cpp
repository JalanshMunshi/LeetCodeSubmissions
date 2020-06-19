class Solution {
public:
    int addDigits(int num) {
        
        if(num > 0)
            while(num / 10 > 0)
                num = num / 10 + num % 10;
        return num;
    }
};