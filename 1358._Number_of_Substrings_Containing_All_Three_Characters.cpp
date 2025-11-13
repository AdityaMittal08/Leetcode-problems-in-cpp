#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int subArrays = 0;
        vector <int> countArr(3, -1);
        for(int i = 0; i < s.size(); i++){
            countArr[s[i] - 'a'] = i;
            if(countArr[0] != -1 && countArr[1] != -1 && countArr[2] != -1){
                subArrays += 1 + min({countArr[0], countArr[1], countArr[2]});
            }
        }
        return subArrays;
    }
};