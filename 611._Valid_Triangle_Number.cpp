#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int answer = 0;
        sort(nums.begin(), nums.end());
        for(int i = nums.size() - 1; i >= 2; i--){
            int left = 0;
            int right = i - 1;
            while(left < right){
                if(nums[left] + nums[right] > nums[i]){
                    answer += (right - left);
                    right--;
                }else{
                    left++;
                }
            }
        }
        return answer;
    }
};