#include <vector>
using namespace std;

class Solution {
private:
    int getNice(vector <int> nums, int k, int n){
        int left = 0;
        int count = 0;
        int subArrSize = 0;
        for(int right = 0; right < n; right++){
            if(nums[right] % 2 != 0){
                subArrSize++;
            }
            while(subArrSize > k){
                if(nums[left] % 2 != 0){
                    subArrSize--;
                }
                left++;
            }
            count += right - left + 1;
        }
        return count;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        return getNice(nums, k, n) - getNice(nums, k - 1, n);
    }
};