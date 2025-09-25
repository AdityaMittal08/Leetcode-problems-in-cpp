#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string answer = "1";
        for(int i = 2; i <= n; i++){
            string temp = "";
            for(int j = 0; j < answer.size(); j++){
                int counter = 1;
                while(j+ 1 < answer.size() && answer[j] == answer[j+1]){
                    counter++;
                    j++;
                }
                temp += to_string(counter) + answer[j]; 
            }
            answer = temp;
        }

        return answer;
    }
};