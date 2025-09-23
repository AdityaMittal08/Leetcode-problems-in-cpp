#include <string>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0;
        int j = 0;
        while(i < version1.size() || j < version2.size()){
            long long revision1 = 0;
            long long revision2 = 0;

            while( i < version1.size() && version1[i] != '.'){
                revision1 += 10*revision1 + (version1[i] - '0');
                i++;
            }

            while( j < version2.size() && version2[j] != '.'){
                revision2 += 10*revision2 + (version2[j] - '0');
                j++;
            }

            if(revision1 > revision2){
                return 1;
            }else if(revision1 < revision2){
                return -1;
            }
            i++;
            j++;
        }
        return 0;
    }
};