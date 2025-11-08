#include <string>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j = 0;
        for(int k = 0; k < t.size() and j < s.size(); k++){
            if(s[j] == t[k]){
                j++;
            }
        }

        return (j == s.size());
    }
};