#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int start, left, right;
        start = 0;
        int maxLength = 1;
        
        if(n <1){
            return s.substr(start, maxLength);
        }

        for(int i = 0; i< n; i++){
            left = i;
            right = i;
            while(right < n && left >= 0 && s[left] == s[right]){
                if(right-left+ 1> maxLength){
                    maxLength = right -left + 1;
                    start = left;
                }
                right ++;
                left --;
            }

            left = i;
            right = i+1;
            while(right < n && left >= 0 && s[left] == s[right] ){
                if(right-left+ 1> maxLength){
                    maxLength = right -left + 1;
                    start = left;
                }
                right ++;
                left --;
            }
        }
        return s.substr(start, maxLength);
    }
};