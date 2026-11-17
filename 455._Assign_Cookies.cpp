class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans = 0;

        sort(s.begin(), s.end());
        sort(g.begin(), g.end());
        if(s.size() == 0){
            return 0;
        }
        int k = 0;
        for(int i = 0; i < g.size(); i++){
            while (k < s.size() && s[k] < g[i]) {
                k++;
            }
            if (k == s.size()) {
                break;
            }
            
            if(g[i] <= s[k]){
                k++;
                ans++;
            }
        }

        return ans;
    }
};