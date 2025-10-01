class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int answer = numBottles;
        while(numBottles >= numExchange){
            int remains = numBottles / numExchange;
            answer += remains;
            int remainingBottles = numBottles % numExchange;
            numBottles = remainingBottles + remains;
        }

        return answer;
    }
};