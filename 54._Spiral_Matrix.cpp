#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size() - 1;
        int cols;
        vector<int> answer;
        int trackRows = 0;
        int trackCols = 0;
        cols = matrix[0].size() - 1;
        while(trackRows <= rows && trackCols <= cols){
            for(int j = trackCols; j <= cols; j++){
                answer.push_back(matrix[trackRows][j]);
            }
            trackRows++;

            if (trackRows > rows) break;

            for(int i = trackRows; i <= rows; i++){
                answer.push_back(matrix[i][cols]);
            }
            cols--;

            if (trackCols > cols) break;

            for(int j = cols; j >= trackCols; j--){
                answer.push_back(matrix[rows][j]);
            }
            rows--;
            for(int i = rows; i >= trackRows; i--){
                answer.push_back(matrix[i][trackCols]);
            }
            trackCols++;
        }

        return answer;
    }
};