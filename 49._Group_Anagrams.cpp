#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string, vector<string>> groups;
        vector<vector<string>> result;

        for(string s : strs){
            string k = s;
            sort(k.begin(), k.end());
            groups[k].push_back(s);
        }

        for(const auto& pair : groups){
            result.push_back(pair.second);
        }
        
        return result;
    }
};