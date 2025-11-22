#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n; i++){
            for(int j = n - 1; j >= 0; j--){
                if(i == j){
                    break;
                }
                swap(matrix[j][i], matrix[i][j]);
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(j > n-1-j){
                    break;
                }
                swap(matrix[i][j], matrix[i][n -1- j]);
            }
        }
    }
};