#include <vector>
using namespace std;

class Solution {
public:
    int mergeSort(vector<int>& nums, vector<int>& temp, int low, int high) {
        if (low >= high) {
            return 0;
        }

        int mid = low + (high - low) / 2;
        
        int count = mergeSort(nums, temp, low, mid) + mergeSort(nums, temp, mid + 1, high);

        int j = mid + 1;
        for (int i = low; i <= mid; i++) {
            while (j <= high && nums[i] > 2LL * nums[j]) {
                j++;
            }
            count += (j - (mid + 1));
        }

        int left = low, right = mid + 1;
        int k = low;

        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                temp[k++] = nums[left++];
            } else {
                temp[k++] = nums[right++];
            }
        }

        while (left <= mid) temp[k++] = nums[left++];
        while (right <= high) temp[k++] = nums[right++];

        for (int i = low; i <= high; i++) {
            nums[i] = temp[i];
        }

        return count;
    }

    int reversePairs(vector<int>& nums) {
        vector<int> temp(nums.size());
        return mergeSort(nums, temp, 0, nums.size() - 1);
    }
};