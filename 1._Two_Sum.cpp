#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> m;

        for(int i = 0; i <=nums.size(); i++){
            int complement = target - nums[i];
            if(m.count(complement)){
                return {m[complement], i};
            }
            else{
                m[nums[i]] = i;
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