#include <string>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string answer = "";
        int i = 0;
        while( i < word1.size() || i < word2.size()){
            if(i < word1.size()){
                answer += word1[i];
            }

            if(i < word2.size()){
                answer += word2[i];
            }
            i++;
        }

        return answer;
    }
};