#include <string>
using namespace std;

class Solution {
public:
    bool hasSameDigits(string s) {
        while (s.size() > 2) {
            string next_answer = "";
            for(int i = 0; i < s.size() - 1; i++){
                int value = (s[i] + s[i+ 1] - '0' - '0') % 10;
                next_answer += value + '0';
            }
            s = next_answer;
        }
        return s[0] == s[1];
    }
};