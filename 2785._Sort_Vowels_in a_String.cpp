#include <string>
#include <algorithm>
using namespace std;

class Solution {
private: 
    bool isVowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
            || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }

public:
    string sortVowels(string s) {
        string t = "";

        for(char c : s){
            if(isVowel(c)){
                t += c;
            }
        }

        int count = 0;
        string ans = "";
        sort(t.begin(), t.end());
        for(int j = 0; j < s.size() ; j++){
            if(isVowel(s[j])){
                ans += t[count];
                count++;
            }
            else{
                ans += s[j];
            }
        }

        return ans;
    }
};