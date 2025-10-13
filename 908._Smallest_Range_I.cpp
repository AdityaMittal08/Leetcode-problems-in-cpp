#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        if (nums.size() <= 1) {
            return 0;
        }
        sort(nums.begin(), nums.end());

        int min_val = nums[0];
        int max_val = nums[nums.size() - 1];
        
        int diff = max_val - min_val;

        if (diff <= 2 * k) {
            return 0;
        } else {
            return diff - 2 * k;
        }
    }
};