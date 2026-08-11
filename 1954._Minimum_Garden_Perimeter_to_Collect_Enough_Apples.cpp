class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long low = 1,  high = 100000;
        long long answer = high;
        while(low <= high){
            long long mid = low + (high-low)/ 2;
            long long currentApples = 2LL*mid*(mid + 1)*(2*mid + 1);

            if(currentApples >= neededApples){
                high = mid - 1;
                answer = mid;
            }else{
                low = mid + 1;
            }
            
        }
        return 8LL * answer;
    }
};