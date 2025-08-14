#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        string strNum = to_string(x);
        for(int i = 0; i < strNum.length(); i++){
            int first = strNum[i];
            int last = strNum[strNum.length()- 1 - i];
            if(first == last){
                continue;
            }
            else{
                return false;
            }
        }
        return true;
    }
};