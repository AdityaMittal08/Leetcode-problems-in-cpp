#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {

        std::sort(events.begin(), events.end(), 
        [&](const std::vector<std::string>& a, const std::vector<std::string>& b) {
        
            int value_a = std::stoi(a[1]); 
            
            int value_b = std::stoi(b[1]);
            if (value_a != value_b) {
                return value_a < value_b;
            }
            if(b[0] == "OFFLINE"){
                return false;
            }

            return true;
        });
        
        vector <int> count(numberOfUsers);
        vector <int> next_online_time(numberOfUsers);
        for(auto&& event : events){
            int current_time = stoi(event[1]);
            if(event[0] == "MESSAGE"){
                if(event[2] == "ALL"){
                    for(int j = 0; j < numberOfUsers; j++){
                        count[j]++;
                    }
                }else if(event[2] == "HERE"){
                    for(int j = 0; j < numberOfUsers; j++){
                        if(next_online_time[j] <= current_time){
                            count[j]++;
                        }
                    }
                }else{
                    int idx = 0;
                    for(int j = 0; j < event[2].size(); j++){
                        if(isdigit(event[2][j])){
                            idx = idx * 10 + (event[2][j] - '0');
                        }
                        if(j + 1 == event[2].size() || event[2][j+1] == ' '){
                            count[idx]++;
                            idx = 0;
                        }
                    }

                }
            }else{
                int idx = stoi(event[2]);
                next_online_time[idx] = current_time + 60;
            }
        }

        return count;
    }
};