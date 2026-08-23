#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        unordered_set <int> check(nums.begin(), nums.end());
        int maxCount = 0;

        for (int num : check) {
            if (!check.contains(num - 1)) {
                int count = 1;
                while (check.contains(num + count)) {
                    count++;
                }
                maxCount = max(maxCount, count);
            }
        }

        return maxCount;
    }
};