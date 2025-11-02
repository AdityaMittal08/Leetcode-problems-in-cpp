#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        for(int& num : nums){
            num = abs(num);
        }
        sort(nums.begin(), nums.end());
        nums[0] = 100000;
        long long answer = (long long)nums[0]*(long long)nums[nums.size() - 1]*(long long)nums[nums.size() - 2];

        return abs(answer);
    }
};