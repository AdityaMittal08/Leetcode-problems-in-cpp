#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        unordered_set <int> set(nums.begin(), nums.end());

        int max_length = 0;
        for(int i : set){
            if(set.find(i-1) == set.end()){
                int current_num = i;
                int current_length = 1;
                while(set.find(current_num + 1) != set.end()){
                    current_num++;
                    current_length++;
                }
                max_length = max(max_length, current_length);
            }
        }

        return max_length;
    }
};