#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }
        int size1 = haystack.size();
        int size2 = needle.size();

        for(int i = 0; i <= size1 - size2; i++){
            int j;
            for(j = 0; j <size2; j++){
                if(haystack[i+j] != needle[j]){
                    break;
                }
            }
            if(j == size2){
                return i;
            }
        }
        return -1;
    }
};