#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.empty()){
            return {};
        }
        vector <string> answer;
        int start = 0;
        for(int i = 1; i <= nums.size(); i++){

            if(i == nums.size() || (long long)nums[i] - nums[i-1] > 1){
                int start_val = nums[start];
                int end_val = nums[i - 1];

                if(start_val == end_val){
                    answer.push_back(to_string(start_val));
                }else{
                    answer.push_back(to_string(start_val) + "->" + to_string(end_val));
                }

                start = i;
            }
        }
        return answer;
    }
};