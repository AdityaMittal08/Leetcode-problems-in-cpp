#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        string converted = "";
        for(int i = 0; i < s.size(); i++){
            if(isalpha(s[i]) || isdigit(s[i])){
                converted += s[i];
            }
        }   
        int j = converted.size() - 1;
        int i = 0;
        while(i < j){
            if(converted[i] != converted[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};