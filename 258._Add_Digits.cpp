class Solution {
    private:
    int sumation(int num, int val){
        if(num / 10 == 0){
            return num;
        }
        while(num != 0){
            val += num%10;
            num = num/10;
        }
        return sumation(val, 0);
    }
public:
    int addDigits(int num) {
        int value = 0;
        return sumation(num, value);
    }
};