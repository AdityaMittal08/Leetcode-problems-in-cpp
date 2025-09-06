#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int j = 0;
        int maxGap = 0;
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] < prices[j]){
                j = i;
                continue;
            }else if(prices[i] > prices[j]){
                maxGap = max(maxGap, prices[i] - prices[j]);
            }else{
                continue;
            }
        }
        return maxGap;
    }
};