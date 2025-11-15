#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> dictionary;

        for(int i = 0; i < magazine.size(); i++){
            dictionary[magazine[i]]++;
        }
        for(int i = 0; i < ransomNote.size(); i++){
            if(--dictionary[ransomNote[i]] < 0){
                return false;
            }
        }
        return true;
    }
};