#include <cmath>

class Solution {
public:
    int reverse(int x) {
        long long reversed_number = 0;
        while(x != 0){
            long long remainder = x %10;
            reversed_number = reversed_number*10 + remainder;
            x /= 10;
        }
        if(reversed_number >= pow(2, 31) - 1 || reversed_number <= -pow(2, 31)){
            return 0;
        }
        return reversed_number;
    }
};