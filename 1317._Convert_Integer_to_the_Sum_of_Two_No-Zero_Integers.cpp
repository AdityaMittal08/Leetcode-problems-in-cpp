#include <vector>
using namespace std;


class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int a = 0;
        int b = 0;
        bool zero = true;

        for(int i = 1; i < n; i++){
            a = i;
            b = n - i;
            int store1 = a;
            int store2 = b;
            while(b != 0){
                if(b >= 10 && b %10 == 0){
                    zero = false;
                    break;
                }
                b = b/10;
            }
            while(a != 0){
                if(a >= 10 && a % 10 == 0){
                    zero = false;
                    break;
                }
                a = a/10;
            }
            if(zero == true){
                return {store1, store2};
            }
            zero = true;
        }
        return {0, 0};
    }
};