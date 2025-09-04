class Solution {
public:
    int findClosest(int x, int y, int z) {
        int zxGap = z-x;
        int zyGap = z-y;
        if((zxGap*zxGap) > (zyGap*zyGap)){
            return 2;
        }else if((zxGap*zxGap) < (zyGap*zyGap)){
            return 1;
        }else{
            return 0;
        }
    }
};