// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         vector<int> arr = {};
//         int i = 0;
//         int j = 0;
//         while(i < nums1.size() && j < nums2.size()){
//             if(nums1[i] <= nums2[j]){
//                 arr.push_back(nums1[i]);
//                 i++;
//             }else{
//                 arr.push_back(nums2[j]);
//                 j++;
//             }
//         }

//         while(i < nums1.size()) {
//             arr.push_back(nums1[i]);
//             i++;
//         }
//         while(j < nums2.size()){
//             arr.push_back(nums2[j]);
//             j++;
//         }
//         if(arr.size() % 2 != 0){
//             double ans = (double)arr[arr.size()/2];
//             return ans;
//         }
//         double no1 = arr[arr.size()/2 - 1];
//         double no2 = arr[arr.size()/2];
//         return (double)(no1 + no2)/2;
//     }
// };

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()){
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();

        int low = 0;
        int high = m;

        int half = (m + n + 1)/2;


        while(low <= high){
            int i = low + (high - low)/2;
            int j = half - i;

            int l1 = (i == 0) ? INT_MIN : nums1[i-1];
            int r1 = (i == m) ? INT_MAX : nums1[i];
            int l2 = (j == 0) ? INT_MIN : nums2[j - 1];
            int r2 = (j == n) ? INT_MAX : nums2[j];

            if(l1 <= r2 && l2 <= r1){
                if((m + n) % 2 != 0){
                    return (max(l1, l2));
                }

                return((double)max(l1, l2) + min(r1, r2))/2.0;
            }else if(l1 > r2) {
                high = i - 1;
            }else{
                low = i + 1;
            }
        }

        return 0.0;
    }
};