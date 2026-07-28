class Solution {
public:
    double myPow(double x, int n) {
        long long m = n;
        if(m < 0){
            x = 1.0/x;
            m = -m;
        }

        double ans = 1.0;

        while(m > 0){
            if(m % 2 != 0){
                ans *= x;
            }

            x *= x;
            m /= 2;
        }
        return ans;
    }
};