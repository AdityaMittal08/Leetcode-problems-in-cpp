#include <string>
using namespace std;

class Solution {
public:
    string largestGoodInteger(string num) {
        char maxGet = '\0';
        for(int i = 0; i < num.length() -2; i++){
            if(num[i] == num[i+1] && num[i+1] == num[i+2]){
                maxGet = max(maxGet, num[i]);
            }
        }
        return maxGet == '\0' ? "" : string(3, maxGet);
    }
};