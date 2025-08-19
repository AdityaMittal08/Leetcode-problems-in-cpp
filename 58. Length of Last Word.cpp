#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int size1 = s.size();
        int last = size1- 1;
        int answer = 0;
        
        if(size1 == 1){
            answer ++;
            return answer;
        }
        while(s[last] == ' '){
            last--;
        }
        while(s[last] != ' '){
            if(last == 0){
                answer ++;
                break;
            }
            answer++;
            last--;
        }
        return answer;
    }
};