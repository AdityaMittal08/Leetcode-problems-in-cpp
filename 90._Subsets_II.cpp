#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    void subsets(vector<int> &arr, int i, vector<vector<int>> &result, vector<int> &ans){
        if( i == arr.size()){
            result.push_back({ans});
            return;
        }

        ans.push_back(arr[i]);
        subsets(arr, i+1, result, ans);

        int idx = i +1;
        while(idx < arr.size() && arr[idx] == arr[idx - 1]){
            idx++;
        }
        ans.pop_back();
        subsets(arr, idx, result, ans);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> ans;
        int i = 0;
        subsets(nums, i, result, ans);
        return result;
    }
};