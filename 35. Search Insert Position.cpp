#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size1 = nums.size();
        int low = 0;
        int high = size1-1;
        int mid = (size1-1)/2;
        while(low <= high){
            mid = (high+low)/2;
            if (nums[mid] == target){
                return mid;
            }
            if(nums[mid] < target){
                low = mid + 1;
            }else{
                high = mid -1;
            }
        }
        return low;
    }
};  