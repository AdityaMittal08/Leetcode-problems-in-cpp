#include <vector>
using namespace std;

class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }
        int answer;
        int left = nums[0];
        for(int i = 1; i < nums.size(); i++){ 
            int right = sum - left;
            if((left - right) % 2 == 0){
                answer++;
            }
            left += nums[i];
        }

        return answer;
    }
};