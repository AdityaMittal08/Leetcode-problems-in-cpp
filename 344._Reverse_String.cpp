#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int j = 0;
        for(int i = 1; i < s.size()/ 2 + 1; i++){
            char value = s[s.size() - i];
            s[s.size() - i] = s[j];
            s[j] = value;
            j++;
        }
    }
};