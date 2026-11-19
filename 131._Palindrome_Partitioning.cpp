#include <string>
#include <vector>
using namespace std;

class Solution {
public:

    bool checkPalindrome(string arr){
        int i = 0;
        int j = arr.size() - 1;

        while(i <= j){
            if(arr[i] != arr[j]){
                return false;
            }
            i++;
            j--;
        }

        return true;
    }

    void getPalindrome(vector<vector<string>> &palinds, vector<string> &arr, string &s, int j){
        if(j == s.size()){
            palinds.push_back(arr);
            return;
        }

        string k = "";

        for(int i = j; i < s.size(); i++){
            k += s[i];
            if(checkPalindrome(k)){
                arr.push_back(k);
                getPalindrome(palinds, arr, s, i + 1);
                arr.pop_back();
            }
        }

        return;
    }


    vector<vector<string>> partition(string s) {
        vector<vector<string>> palinds;
        vector<string>arr;
        getPalindrome(palinds, arr, s, 0);

        return palinds;
    }
};