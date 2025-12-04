#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <int> st;
        for(int i = 0; i < tokens.size(); i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "/" || tokens[i] == "*"){
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                if(tokens[i] == "+"){
                    int result = second + first;
                    st.push(result);
                }else if(tokens[i] == "-"){
                    int result = second - first;
                    st.push(result);
                }
                else if(tokens[i] == "/"){
                    int result = second / first;
                    st.push(result);
                }
                else if(tokens[i] == "*"){
                    int result = second * first; 
                    st.push(result);
                }
            }else{
                int value = stoi(tokens[i]);
                st.push(value);
            }
        }
        return st.top();
    }
};