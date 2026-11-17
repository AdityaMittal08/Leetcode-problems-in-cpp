#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int maxHL = 0;
        int maxHR = 0;
        int n = height.size();
        int i = 0;
        int j = n - 1;
        int ans = 0;

        while(i < j){
            int HL = height[i];
            int HR = height[j];
            if(HL <= HR){
                if(HL >= maxHL){
                    maxHL = HL;
                }else{
                    ans += maxHL - HL;
                }
                i++;
            }else{
                if(HR >= maxHR){
                    maxHR = HR;
                }else{
                    ans += maxHR - HR;
                }
                j--;
            }
            
        }
        return ans;
    }
};