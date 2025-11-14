#include <vector>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int totalSum = 0;
        for(int i = 0; i < k; i++){
            totalSum += cardPoints[i];
        }
        int tempSum = totalSum;
        for(int i = k - 1; i >= 0; i--){
            tempSum = tempSum - cardPoints[i]  + cardPoints[n-k+i];

            totalSum = max(totalSum, tempSum);
        }
        return totalSum;
    }
};