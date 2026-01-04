#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int maxReachable = 0;
        int lastJumpedPos = 0;
        int jumps = 0;
        while(lastJumpedPos < n - 1){
            maxReachable = max(maxReachable, i + nums[i]);
            if(i == lastJumpedPos){
                lastJumpedPos = maxReachable;
                jumps++;
            }
            i++;
        }
        return jumps;
    }
};