#include <vector>
using namespace std;

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        long long MOD = 1e9 + 7;

        vector <long long> dp(n+1, 0);

        dp[1] = 1;
        long long share = 0;

        for(int i = 2; i<=n; i++){
            if(i - delay >= 1){
                share = (share + dp[i - delay]) % MOD;
            }

            if( i - forget >= 1){
                share = (share - dp[i - forget] + MOD) % MOD;
            }

            dp[i] = share;
        }

        long long total_aware = 0;
        for(int i = n - forget + 1; i<=n; i++){
            total_aware = (total_aware + dp[i]) % MOD;
        }

        return total_aware;
    }
};