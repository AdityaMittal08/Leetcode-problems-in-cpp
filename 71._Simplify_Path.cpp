#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {

        stack<string> st;
        string answer;
        for(int i = 0; i < path.size(); i++){
            if(path[i] == '/'){
                continue;
            }
            string temp;
            while(i < path.size() && path[i] != '/'){
                temp += path[i];
                i++;
            }
            if(temp == "."){
                continue;
            }else if(temp == ".."){
                if(!st.empty()){
                    st.pop();
                }
            }else{
                st.push(temp);
            }
        }

        while(!st.empty()){
            answer = '/' + st.top() + answer;
            st.pop();
        }
        if(answer.size() == 0){
            return "/";
        }

        return answer;
    }
};