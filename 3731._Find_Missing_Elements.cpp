#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> answer;
        sort(nums.begin(), nums.end());
        int j = 1;
        for(int i = 0; i < nums.size() - 1; i++){
            while(nums[i] + j != nums[i+1]){
                answer.push_back(nums[i] + j);
                j++;
            }
            j = 1;
        }

        return answer;
    }
};