#include <string>
using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        int ans = 0;
        int n = word.size();
        int multiple = 1;
        while(n > 0){
            if((n - 8) >= 0){
                ans += multiple*8;
                multiple++;
            }else{
                ans += n*multiple;
            }
            n = n - 8;
        }


        return ans;
    }
};