#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int high = n - 1;
        int low = 0;
        int row;
        if(target > matrix[n-1][m-1]){
            return false;
        }else if(target < matrix[0][0]){
            return false;
        }
        while(low <= high){
            int mid = low + (high - low)/2;
            if(target > matrix[mid][0] && target < matrix[mid][m - 1]){
                row = mid;
                break;
            }
            else if(target < matrix[mid][0]){
                high = mid - 1;   
            }else if(target > matrix[mid][m-1]){
                low = mid + 1;
            }else if(target == matrix[mid][0] || target == matrix[mid][m-1]){
                return true;
            }
        }
        
        int low2 = 0;
        int high2 = m- 1;
        while(low2 <= high2){
            int mid2 = low2 + (high2 - low2)/2;
            if(target < matrix[row][mid2]){
                high2 = mid2 - 1;
            }else if(target > matrix[row][mid2]){
                low2 = mid2 + 1;
            }else{
                return true;
            }
        }
        return false;
    }
};