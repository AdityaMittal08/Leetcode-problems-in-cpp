#include <vector>
using namespace std;

class Solution {
public:
    int paths(int k, int l, int m, int n, vector<vector<int>>& dp){
        if( k >= m || l >= n){
            return 0;
        }
        if(k == m-1 && l == n-1){
            return 1;
        }
        if(dp[k][l] != -1){
            return dp[k][l];
        }

        return dp[k][l] = paths(k + 1, l, m, n, dp) + paths(k, l+ 1, m, n, dp);         
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return paths(0, 0, m, n, dp);
    }
};