#include <string>
#include <algorithm> 
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1 = num1.size();
        int n2 = num2.size();
        string answer = "";
        int carry = 0;
        for(int i = 0; i < max(n1, n2); i++){
            char digit1 = '0';
            char digit2 = '0';
            if(i < n1){
                digit1 = num1[n1 - i - 1];
            }
            if(i < n2){
                digit2 = num2[n2 - i - 1];
            }
            int value = (digit1 - '0') + (digit2 - '0') + carry;
            if(value > 9){
                carry = 1;
            }else{
                carry = 0;
            }
            answer += char(value % 10 + '0');
        }
        if(carry == 1){
            answer += '1';
        }
        reverse(answer.begin(), answer.end());
        return answer;        
    }
};