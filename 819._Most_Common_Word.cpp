#include <string>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <vector>
using namespace std;


class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map <string, int> wordFrequencies;
        unordered_set <string> ban(banned.begin(), banned.end());

        for(char &c : paragraph){
            if(isalpha(c)){
                c = tolower(c);
            }else{
                c = ' ';
            }
        }
        istringstream wordStream(paragraph);
        string currentWord;

        pair<string, int> result;

        while(wordStream >> currentWord){
            if(ban.find(currentWord) == ban.end()){
                wordFrequencies[currentWord]++;
                int newCount = wordFrequencies[currentWord];

                if(newCount > result.second){
                    result.first = currentWord;
                    result.second = newCount;
                }
            }
        }

        return result.first;
    }
};