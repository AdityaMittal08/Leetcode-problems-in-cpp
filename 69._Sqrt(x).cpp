class Solution {
public:
    int mySqrt(int x) {
        long long left = 1;
        long long right = x;
        long long mid;
        while(left <= right && x != 0){
            mid =  (left+right)/2;
            if(mid == x/mid){
                return mid;
            }
            if(mid > x/mid){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        if(x == 0){
            return 0;
        }
        return right;
    }
};