#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map <int, int> map;
        for(int i = 0; i < arr.size(); i++){
            map[arr[i]]++;
        }
        int largest_number = -1;
        for(auto const& pair : map){
            if(pair.first == pair.second){
                if(pair.first > largest_number){
                    largest_number = pair.first;
                }
            }
        }

        return largest_number;
    }
};