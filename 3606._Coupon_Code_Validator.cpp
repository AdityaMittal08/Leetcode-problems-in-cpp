#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
    private:
    bool isAlphaNumeric(string s){
        if (s.empty()) {
            return false; 
        }
        for(int i = 0; i < s.size(); i++){
            if(!isalnum(s[i]) && s[i] != '_'){
                return false;
            }
        }
        return true;
    }
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        unordered_map <string, int> map = {
            {"electronics", 0},
            {"grocery", 1},
            {"pharmacy", 2},
            {"restaurant", 3},
        };
        vector <pair<int, string>> store;
        for(int i = 0; i < isActive.size(); i++){
            if(isActive[i] != true){

                continue;
            }
            if(map.count(businessLine[i]) == 0){

                continue;
            }
            if(!isAlphaNumeric(code[i])){

                continue;
            }
            int sortOrder = map[businessLine[i]];
            store.push_back({sortOrder, code[i]});
        }
        
        vector <string> answer;
        sort(store.begin(), store.end());
        
        for(auto& value : store){
            answer.push_back(value.second);
        }

        return answer;
    }
};