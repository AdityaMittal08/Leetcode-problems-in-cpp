#include <vector>
using namespace std;

class Solution {
private:
void findingSubsets(vector<int> &arr, vector <int> &ans, int i, vector<vector<int>> &result){
    if(i == arr.size()){
        result.push_back({ans});
        return;
    }
    ans.push_back(arr[i]);
    findingSubsets(arr, ans, i+1, result);

    ans.pop_back();
    findingSubsets(arr, ans, i+1, result);
}
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector <int> ans;
        findingSubsets(nums, ans, 0, result);
        return result;
    }
};