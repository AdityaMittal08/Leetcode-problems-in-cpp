#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        int gap = 0;
        while(gap < n){
            if(gap + k <= n){
                reverse(s.begin() + gap, s.begin()+ gap +  k);
            }
            else{
                reverse(s.begin() + gap, s.end());
            }
            gap = gap + 2*k;
        }
        return s;
    }
};