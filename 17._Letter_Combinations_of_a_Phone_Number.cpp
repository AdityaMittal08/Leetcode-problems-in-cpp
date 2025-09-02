#include <vector>
#include <string>
using namespace std;

class Solution {
    private:
        void cons(string digits, int i, const vector <string> &ph, string s, vector<string>& answer){
            if(i == digits.length()){
                answer.push_back(s);
                return;
            }

            int number = (digits[i] - '0') -2;
            for(char c: ph[number]){
                cons(digits, i+1, ph, s +c, answer);
            }
        }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ph = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector <string> answer;

        vector <string> vec = {};

        if (digits.empty()){
            return answer;
        }

        cons(digits, 0, ph, "", answer);
        return answer;

    }
};