#include <string>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int s_map[128] = {};
        int t_map[128] = {};

        for(int i = 0; i < s.size(); i++){
            if(s_map[s[i]] != t_map[t[i]]){
                return false;
            }
            s_map[s[i]] = i+ 1;
            t_map[t[i]] = i + 1;
        }

        return true;
    }
};