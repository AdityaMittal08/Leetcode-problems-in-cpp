#include <vector>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        if(k > nums.size()){
            return nums.size();
        }
        int left = 0;
        int maxCount = 0;
        int zeroCount = 0;
        int right = 0;
        for(right; right < nums.size(); right++){
            if(nums[right] == 0){
                zeroCount++;
            }
            if(zeroCount > k){
                if(nums[left] == 0){
                    zeroCount--;
                }
                left++;
            }
            maxCount = max(maxCount, (right - left + 1));
        }
        return maxCount;
    }
};