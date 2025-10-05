#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector <int> values;
        int j = 1;
        for(int i = 0; i < arr.size(); i++){
            if(i+ 1 < arr.size() && arr[i] == arr[i+1]){
                j++;
            }else{
                values.push_back(j);
                j = 1;
            }
        }
        sort(values.begin() , values.end());
        for(int k = 0; k < values.size()-1; k++){
            if(values[k] == values[k+1]){
                return false;
            }
        }

        return true;
    }
};