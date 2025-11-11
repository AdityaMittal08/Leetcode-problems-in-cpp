#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int maxCount = 0;
        int maxFreq = 0;
        unordered_map <char, int> map;

        for(int right = 0; right < s.size(); right++){
            map[s[right]]++;
            maxFreq = max(maxFreq, map[s[right]]);
            if((right-left + 1) - maxFreq > k){
                map[s[left]]--;
                left++;
            }
            maxCount = max(maxCount, right - left + 1);
        }
        return maxCount;
    }
};