#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {        
        string answer;
        int size = strs.size();
        sort(strs.begin(), strs.end());
        string first = strs[0];
        string last = strs[size -1];
        for(int i =0; i < min(first.size(), last.size()); i++){
            if(first[i] != last[i]){
                return answer;
            }
            answer += first[i];
        }
        return answer;
    }
};