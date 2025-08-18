class Solution {
public:
   int removeDuplicates(vector<int>& nums) {
        int k = 1;
        if(nums.size() == 1){
            return k;
        }
        int j = 0;
        for (int i = 1; i < nums.size() ; i++){
            if(nums[j] != nums[i]){
                nums[j+1] = nums[i];
                k++;
                j++;
            }
        }
        return k;
    }
};