#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 1){
            return 1;
        }
        int j = 0;
        int count = 1;
        for(int i = 1; i< nums.size(); i++){
            if(nums[i] != nums[j]){
                nums[j+1] = nums[i];
                count = 1;
                j++;
            }else{
                count++;
                if(count < 3){
                    nums[j+1] = nums[i];
                    j++;
                }
            }
        }
        return (j+1);
    }
};