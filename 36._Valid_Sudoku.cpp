#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9] = { false };
        bool column[9][9] = { false };
        bool box[9][9] = { false };

        for(int i = 0 ; i < board.size(); i++){
            for(int j = 0; j < board.size(); j++){
                if(board[i][j] == '.'){
                    continue;
                }
                int num = board[i][j] - '1';
                int boxIndex = (i / 3)*3 + (j / 3);

                if(rows[i][num] || column[j][num] || box[boxIndex][num]){
                    return false;
                }
                rows[i][num] = column[j][num] = box[boxIndex][num] = true;
            }
        }
        return true;
    }
};