#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector <int> nums3; 
        for (int val : nums1){
            for (int val2 : nums2){
              if(val == val2){
                nums3.push_back(val);
              }
            }
        }
        sort(nums3.begin(), nums3.end());
        auto it = unique(nums3.begin(), nums3.end());
        nums3.erase(it, nums3.end());
        return nums3;
    }
};

int main() {
    vector<int> nums1 = {1, 2, 2, 3};
    vector<int> nums2 = {2, 2};
    Solution sol;
    vector<int> value = sol.intersection(nums1, nums2);
    cout << "The answer is: ";
    for (int num : value) {
        cout << num << " ";
    }
    cout << endl;
}