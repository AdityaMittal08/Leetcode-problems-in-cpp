#include <vector>
using namespace std;

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int count = k;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1){
                if(count < k){
                    return false;
                }
                count = 0;
                continue;
            }else{
                count++;
            }
        }
        return true;
    }
};