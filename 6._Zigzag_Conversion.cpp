#include <string>
#include <vector>
using namespace std;


//SOLUTION - 1
class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        
        if(numRows <= 1 || numRows >= n){
            return s;
        }

        string answer = "";
        int cycleLen = 2*(numRows - 1);

        for(int i = 0; i < numRows; i++){
            for(int j = 0; j + i < n; j+=cycleLen){

                answer += s[i + j];

                if(i != 0 && i != numRows-1 && (j + cycleLen-i) < n){
                    answer += s[j + cycleLen - i];
                }
            }
        }
        return answer;
    }
};

//SOLUTION - 2
class Solution {
public:
    string convert(string s, int numRows) {

        if(numRows == 1 || numRows >= s.length()){
            return s;
        }
        int idx = 0;
        int d = 1;
        vector <vector<char>> rows(numRows);

        for (char c : s){
            rows[idx].push_back(c);
            if(idx==0){
                d = 1;
            }
            else if(idx == numRows-1){
                d = -1;
            }
            idx += d;
        }

        string answer;
        for(const auto&row : rows){
            for(char c : row){
                answer += c;
            }
        }
        return answer;
    }
};

//SOLUTION - 3
class Solution {
public:
    string convert(string s, int numRows) {
        int gap = numRows - 2;
        int n = s.size();
        string answer = "";
        
        if(gap < 0){
            return s;
        }

        for(int i = 0; i < numRows; i++){
            int inbetween = 2*i;
            for(int j = 0; j < n; j++){
                if(i > 0 && i <= numRows-2 && j>0 && j*(numRows + gap) + i-inbetween < n){
                    answer += s[j*(numRows + gap) + i-inbetween];
                }
                if(j*(numRows + gap)+i < n){
                    answer += s[j*(numRows + gap)+i];
                }
            }
        }
        return answer;
    }
};