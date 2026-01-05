#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long answer = 0;
        int count = 0;
        int smallestNumber = 100001;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix.size(); j++){
                answer += abs(matrix[i][j]);
                if(matrix[i][j] < 0){
                    count++;
                }
                smallestNumber = min(smallestNumber, abs(matrix[i][j]));
            }
        }

        if(count % 2 == 0){
            return answer;
        }
        return (answer - 2*smallestNumber);
    }
};