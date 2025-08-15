#include <map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map <char, int> value = 
        {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

        int answer = 0;
        for(int i = 0; i < s.size(); i++){
            if(value[s[i]] >= value[s[i+1]]){
                answer = answer + value[s[i]];
            }
            else{
                answer = answer - value[s[i]];
            }
        }
        return answer;
    }
};