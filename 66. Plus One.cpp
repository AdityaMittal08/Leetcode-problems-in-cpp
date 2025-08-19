#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size1= digits.size();
        int last = size1 - 1;
        int first = 0;
        while(digits[last] == 9){
            digits[last] = 0;
            last--;
            if(digits[first] == 0){
                auto it = digits.begin() + first; 
                digits.insert(it, 1);
                return digits;
            }
        }
        digits[last]++;
        return digits;
    }
};