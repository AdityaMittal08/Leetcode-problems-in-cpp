#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int answer = 0;
        for(int i = citations.size() - 1; i >= 0; i--){
            if(citations[i] > answer){
                answer ++;
            }else{
                break;
            }
        }
        return answer;
    }
};