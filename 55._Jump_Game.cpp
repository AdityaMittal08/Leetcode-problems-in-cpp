#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        int n = nums.size();

        for(int i = 0; i < nums.size(); i++){
            if(i > maxReach){
                return false;
            }

            maxReach = max(maxReach, i + nums[i]);

            if(maxReach >= n-1){
                return true;
            }
        }

        return true;
    }
};