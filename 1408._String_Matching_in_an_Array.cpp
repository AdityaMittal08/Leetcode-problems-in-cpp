#include <string>
#include <vector>
using namespace std;


class Solution {
private:

bool isSubstringOf(string &sub, string &main){
    for(int i = 0; i < main.size(); i++){
        bool subFits = true;
        for(int j = 0; j < sub.size(); j++){
            if(i + j >= main.size() || main[i + j] != sub[j]){
                subFits = false;
                break;
            }
        }
        if(subFits){
            return true;
        }
    }
    return false;
};
public:
    vector<string> stringMatching(vector<string>& words) {
        vector < string > matchingWords;
        for(int i = 0; i < words.size() ; i++){
            for(int j = 0; j < words.size(); j++){
                if(i == j){
                    continue;
                }

                if(isSubstringOf(words[i], words[j])){
                    matchingWords.push_back(words[i]);
                    break;
                }
            }
        }
        return matchingWords;
    }
};