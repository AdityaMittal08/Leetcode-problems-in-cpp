#include <vector>
#include <string>
using namespace std;

class Solution {
private:   
    bool isSafe(vector<string> &board, int row, int col, int n){
        for(int j = 0; j < n; j++){
            if(board[row][j] == 'Q'){
                return false;
            }
        }
        for(int i = 0; i < n; i++){
            if(board[i][col] == 'Q'){
                return false;
            }
        }
        for(int i = row, j = col; i>= 0 && j>=0; i--, j--){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        for(int i = row, j = col; i>= 0 && j>=0; i--, j++){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        return true;
    }

    void nQueen(vector<string> &board, int row, int n, vector<vector<string>> & answer){
        if(row == n){
            answer.push_back({board});
            return;
        }
        for(int j = 0; j < n; j++){
            if(isSafe(board, row, j, n)){
                board[row][j] = 'Q';
                nQueen(board, row + 1, n, answer);
                board[row][j] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> answer;
        vector<string>board(n, string(n, '.'));
        nQueen(board, 0, n, answer);

        return answer;
    }
};