#include <string>
using namespace std;

class Solution {
public:
    string reformat(string s) {
        string words = "";
        string numbers = "";
        for(int i = 0; i < s.size(); i++){
            if(isalpha(s[i])){
                words += s[i];
            }else{
                numbers += s[i];
            }
        }
        int count_words = words.size();
        int count_numbers = numbers.size();

        string answer = "";
        if(abs(count_words - count_numbers) > 1){
            return answer;
        }
        int j = 0;
        int k = 0;
        bool words_greater = (count_words >= count_numbers);

        for(int i = 0; i < s.size(); i++){
            if(words_greater){
                if(i % 2 == 0){
                    answer += words[j++];
                }else{
                    answer += numbers[k++];
                }
            }else{
                if(i % 2 == 0){
                    answer += numbers[j++];
                }else{
                    answer += words[k++];
                }
            }
        }
        return answer;
    }
};