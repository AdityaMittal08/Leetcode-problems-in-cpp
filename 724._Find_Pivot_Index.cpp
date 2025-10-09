#include <vector>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum_right = 0;
        for(int i = 0; i < nums.size(); i++){
            sum_right += nums[i];
        }

        int sum_left = 0;

        for(int i = 0; i <nums.size(); i++){
            sum_right -= nums[i];
            if(sum_left == sum_right){
                return i;
            }
            sum_left += nums[i];
        }
        return -1;
    }
};