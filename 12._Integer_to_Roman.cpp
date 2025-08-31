#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string answer = "";

        vector < int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector < string> roman =  {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        for(int i = 0; i < values.size(); i++){
            while(num >= values[i]){
                answer += roman[i];
                num -= values[i];
            }
        }
        return answer;

    }
};