#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxDiagonalSquared = 0;
        int currentDiagonalSquared = 0;
        int maxArea = 0;
        int currentArea = 0;

        for(int i = 0; i < dimensions.size(); i++){
            long long currentDiagonalSquared = pow(dimensions[i][0], 2) + pow(dimensions[i][1], 2);            
            currentArea = dimensions[i][0] * dimensions[i][1];

            if(currentDiagonalSquared > maxDiagonalSquared){
                maxArea = currentArea;
                maxDiagonalSquared = currentDiagonalSquared;
            }
            else if(maxDiagonalSquared  == currentDiagonalSquared){
                if(currentArea > maxArea){
                    maxArea = currentArea;
                }
            }
        }
        return maxArea;
    }
};