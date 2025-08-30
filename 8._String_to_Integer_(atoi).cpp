#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        long long answer = 0;
        int negative = 1;
        int i = 0;

        while(s[i] == ' '){
            i++;
        }
        if(i < n && (s[i] == '-' || s[i] == '+')){
            if(s[i] == '-'){
                negative = -1;
            }
            i++;
        }
        while(i < n && isdigit(s[i])){
            int digit = s[i] - '0';
            
            if (answer > INT_MAX / 10 || (answer == INT_MAX / 10 && digit > 7)) {
                return (negative == 1) ? INT_MAX : INT_MIN;
            }
            answer = answer*10 + digit;
            i++;
        }

        return negative*answer;
    }
};