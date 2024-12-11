class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size();
        int cnt = 0;
        int lasti = -1;
        int lastj = -1;
        for(int i=0;i<n;i++){
            if(s1[i] != s2[i]){
                cnt++;
                lastj = lasti;
                lasti = i;
            }
        }
        if(cnt == 0) return true;
        if(cnt != 2) return false;
        if(s1[lasti] != s2[lastj] or s1[lastj] != s2[lasti]) return false;
        return true;
    }
};