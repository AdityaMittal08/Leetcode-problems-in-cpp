#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isValid(string s) {        
        stack <char> container;
        unordered_map <char, char> myMap =
        {{'(',')'}, {'{','}'}, {'[',']'}}; 
        auto it = myMap.begin();
        for(int i = 0; i < s.size(); i++){
            char element = s[i];
            if(element == '(' || element == '{' || element == '['){
                container.push(s[i]);
            }
            else{
                if (!container.empty()){
                    char top = container.top();
                    container.pop();
                    if(myMap[top] != s[i]){
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
        }
        if (container.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};
