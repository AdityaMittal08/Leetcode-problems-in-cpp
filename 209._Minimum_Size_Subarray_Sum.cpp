#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        long long sumContent = 0;
        int size = nums.size() + 1;
        for(int right = 0; right < nums.size(); right++){
            sumContent += nums[right];
            while(sumContent >= target){
                size = min(size, right - left + 1);
                sumContent -= nums[left];
                left++;
            }
        }
        if(size == nums.size() + 1){
            return 0;
        }
        return size;
    }
};