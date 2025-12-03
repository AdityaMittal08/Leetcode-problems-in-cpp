#include <stack>
#include <vector>
using namespace std;

class MinStack {
public:
int minVal;
stack<vector<int>> st;

    MinStack() {
    }
    
    void push(int val) {
        if(st.size() == 0){
            st.push({val, val});
            minVal = val;
        }else{
            minVal = min(minVal, val);
            st.push({val, minVal});
        }
    }
    
    void pop() {
        st.pop();
        if(st.size() != 0){
            minVal = st.top()[1];
        }else{
            minVal = 0;
        }
    }
    
    int top() {
        return st.top()[0];
    }
    
    int getMin() {
        return st.top()[1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */