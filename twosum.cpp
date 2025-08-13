#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if(nums.size() < 2){
            return {};
        }
        int lastInd = nums.size() - 1;

        for (int startInd = 0; startInd <= lastInd; ){  
            int sum = nums[startInd] + nums[lastInd];
            if(sum == target){
                return {startInd, lastInd};
            }
            startInd++;
            if(startInd == lastInd){
                startInd = 0;
                lastInd --;
            }
        }
        return {};
    }
};
int main(){
  vector <int> nums = {1, 2, 3, 5, 6, 7};
  int target = 5;
  Solution sol;
  vector <int> result = sol.twoSum(nums, target);
  
  for (int i = 0; i < result.size(); i++)
    cout << result[i] << " ";
  return 0;
}