#include <vector>
using namespace std;

class Solution {
public:
    bool isSafe(char k, int i, int j, vector<vector<char>>& board){
        for(int l = 0; l < 9; l++) {
            if(board[i][l] == k) return false;
            if(board[l][j] == k) return false;
        }
        int startRow = (i / 3) * 3;
        int startCol = (j / 3) * 3;

        for(int r = startRow; r < startRow + 3; r++) {
            for(int c = startCol; c < startCol + 3; c++) {
                if(board[r][c] == k) return false;
            }
        }
        return true;
    }

    vector<vector<char>> solve(vector<vector<char>>& board, int index){
        if(index == 81){
            return board;
        }

        int i = index/9;
        int j = index%9;

        if(board[i][j] != '.'){
            return solve(board, index + 1);
        }

        for(char k = '1';k <= '9'; k++){
            if(!isSafe(k, i, j, board)){
                continue;
            }
            board[i][j] = k;

            vector<vector<char>> result = solve(board, index + 1);

            if(!result.empty()){
                return result;
            }

            board[i][j] = '.';
        }

        return {};
    }

    void solveSudoku(vector<vector<char>>& board) {
        board = solve(board, 0);
    }
};