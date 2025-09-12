#include <string>
using namespace std;

class Solution {
public:
    bool doesAliceWin(string s) {
        for(int i = 0; i < s.size(); i++){
            char ch = s[i];
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
                return true;
            }
        }
        return false;
    }
};