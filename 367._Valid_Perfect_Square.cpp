class Solution {
public:
    bool isPerfectSquare(int num){
        long long left = 2;
        long long right = num/2;
        long long mid;
        if(num < 2){
            return true;
        }
        while(left <= right){
            mid =  (left+right)/2;
            long long squared = mid * mid;
            if(squared == num){
                return true;
            }
            if(squared > num){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return false;
    }
};