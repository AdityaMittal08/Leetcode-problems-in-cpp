#include <vector>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ans1, ans2;
        int count1 = 0, count2 = 0;
        int n = nums.size();
        for(int num : nums){
            if(num == ans1){
                count1++;
            }else if(num == ans2){
                count2++;
            }else if(count1 == 0){
                ans1 = num;
                count1 = 1;
            }else if(count2 == 0){
                ans2 = num;
                count2 = 1;
            }else{
                count1--;
                count2--;
            }
        }

        count1 = 0;
        count2 = 0;

        for(int num: nums){
            if(num == ans1){
                count1++;
            }else if(num == ans2){
                count2++;
            }
        }

        vector <int> answer;
     
        if(count1 > n/3) answer.push_back(ans1);
        if(count2 > n/3) answer.push_back(ans2);

        return answer;
    }
};