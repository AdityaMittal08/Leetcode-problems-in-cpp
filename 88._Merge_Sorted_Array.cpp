#include <vector>
using namespace std;

class Solution{
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n){
    int j = 0;
    int k = 0;
    int i = 0;
    vector<int> nums3(m+n);
    while (i < m && j < n){
      if (nums1[i] < nums2[j]){
        nums3[k++] = nums1[i++];
      }
      else{
        nums3[k++] = nums2[j++];
      }
    }
    while (i < m){
      nums3[k++] = nums1[i++];
    }
    while (j < n){
      nums3[k++] = nums2[j++];
    }
    for (int a = 0; a < m + n; a++){
      nums1[a] = nums3[a];
    }
  }
};