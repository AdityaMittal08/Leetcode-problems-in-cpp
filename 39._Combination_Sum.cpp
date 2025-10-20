#include <vector>
using namespace std;

class Solution {
private:

void combinationSumation(vector<vector<int>> &result, vector<int> &ans, vector<int> &candidates, int target, int idx, int sum){
    if(sum > target){
        return;
    }
    if(sum == target){
        result.push_back(ans);
        return;
    }
    for (int i = idx; i < candidates.size(); i++){
        ans.push_back(candidates[i]);
        combinationSumation(result, ans, candidates, target, i, sum + candidates[i]);
        ans.pop_back();
    }
}

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> ans;
        combinationSumation(result, ans, candidates, target, 0, 0);
        return result;
    }
};