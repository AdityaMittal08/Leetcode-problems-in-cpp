#include <vector>
using namespace std;

class Solution {
private:
    void getPermutations(vector<int> &arr, int idx, vector<vector<int>>&result){

        if(idx == arr.size()){
            result.push_back({arr});
            return;
        }
        for(int i = idx; i < arr.size(); i++){
            swap(arr[idx], arr[i]);
            getPermutations(arr, idx+1, result);
            
            swap(arr[idx], arr[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        getPermutations(nums, 0, result);

        return result;
    }
};