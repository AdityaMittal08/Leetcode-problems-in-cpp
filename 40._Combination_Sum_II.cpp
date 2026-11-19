#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void getSum(vector<vector<int>> &cands, vector<int> &arr, vector<int>&candidates, int j, int sum, int target){
        if(target == sum){
            cands.push_back(arr);
            return;
        }
        for(int i = j; i < candidates.size(); i++){
            if(i > j && candidates[i] == candidates[i - 1]){
                continue;
            }

            int candidate = candidates[i];
            sum += candidate;
            if(sum > target){
                break;
            }

            arr.push_back(candidate);

            getSum(cands, arr, candidates, i + 1, sum, target);

            arr.pop_back();
            sum -= candidate;
        }

        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> cands;
        vector<int> arr;
        getSum(cands, arr, candidates, 0, 0, target);

        return cands;
    }
};