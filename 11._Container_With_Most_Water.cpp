#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int maxArea = 0;
        int right = height.size()-1;
        while(left <= right){
            if(height[left] >= height[right]){
                maxArea = max(maxArea, height[right]*(right-left));
                right --;
            }
            else{
                maxArea = max(maxArea, height[left]*(right-left));
                left++;
            }
        }
        return maxArea;
    }
};