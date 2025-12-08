class Solution {
public:
    int countTriples(int n) {
        int answer = 0;
        for(int i = 1; i <= n; i++){
            int c = i*i;
            int left = 1;
            int right = n;
            while(left < right){
                int sum = left*left + right*right;
                if(sum == c){
                    answer += 2;
                    left++;
                    right++;
                    continue;
                }

                if(sum > c){
                    right--;
                    continue;
                }
                left++;
            }

        }

        return answer;
    }
};