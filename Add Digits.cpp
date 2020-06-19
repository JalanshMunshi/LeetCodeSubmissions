// Optimized solution
class Solution {
public:
    int addDigits(int num) {
        
        if(!num)
            return num;
        if(num % 9)
            return num % 9;
        return 9;
    }
};
// Less optimized
class Solution {
public:
    int addDigits(int num) {
        
        if(num > 0)
            while(num / 10 > 0)
                num = num / 10 + num % 10;
        return num;
    }
};