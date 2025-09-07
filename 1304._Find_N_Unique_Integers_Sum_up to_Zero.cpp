#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sumZero(int n) {
        vector <int> ans = {};
        int i = 1;
        if(n%2 != 0){
            ans.push_back(0);
            while(i < n){
                ans.push_back(i);
                if(i < n){
                    ans.push_back(-i);
                    i++;
                }
                i++;
            }
        }else{
            while(i < n){
                ans.push_back(i);
                if(i < n){
                    ans.push_back(-i);
                    i++;
                }
                i++;
            }
        }
        return ans;
    }
};