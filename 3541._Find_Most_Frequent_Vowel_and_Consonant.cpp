#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map <char, int> vowels_count = {};
        unordered_map <char, int> consonant_count = {};
        string vowels = "aeiou";
        bool vowelFound = false;
        for(int i = 0; i < s.size(); i++){
            for(int j = 0; j < vowels.size(); j++){
                if(s[i] == vowels[j]){
                    vowels_count[s[i]]++;
                    vowelFound = true;
                    continue;
                }
            }
            if(!vowelFound){
                consonant_count[s[i]]++;
            }
            vowelFound = false;
        }
        int max_current = 0;
        for(const auto& pair: vowels_count){
            if(pair.second > max_current){
                max_current = pair.second;
            }
        }

        int max_current2 = 0;
        for(const auto& pair : consonant_count){
            if(pair.second > max_current2){
                max_current2 = pair.second;
            }
        }

        return max_current + max_current2;

    }
};