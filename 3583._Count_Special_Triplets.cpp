#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        long long answer = 0;
        int mod = 1000000007;
        unordered_map <int, int> freq_next;
        unordered_map <int, int> freq_prev;
        for(int i = 0; i < nums.size(); i++){
            freq_next[nums[i]]++;
        }
        for(int i = 0; i < nums.size(); i++){
            freq_next[nums[i]]--;
            int target = nums[i]*2;
            if(freq_next.count(target) && freq_prev.count(target)){
                long long count_prev = freq_prev.at(target);
                long long count_next = freq_next.at(target);
                answer = (answer + count_next * count_prev) % mod;
            }
            freq_prev[nums[i]]++;
        }
        return (int)answer;
    }
};