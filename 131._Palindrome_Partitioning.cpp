#include <string>
#include <vector>
using namespace std;

class Solution {
private:
    bool isPalindrome(string s){
        int i=0;
        int j=s.size()-1;
        while(i<j){
            if(s[i++]!=s[j--]){
                return false;
            }
        }
        return true;
    }
    void getAllParts(string s, vector <string> &partitions, vector<vector<string>> &ans){
        if(s.size() == 0){
            ans.push_back(partitions);
            return;
        }
        for(int i = 0; i < s.size(); i++){
            string part = s.substr(0, i+ 1);
            if(isPalindrome(part)){
                partitions.push_back(part);
                getAllParts(s.substr(i+ 1), partitions, ans);
                partitions.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> partitions;
        getAllParts(s, partitions, ans);

        return ans;
    }
};