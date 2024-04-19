class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        vector<int> idx(3,-1);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            idx[s[i] - 'a'] = i;
            if(idx[0] != -1 && idx[1] != -1 && idx[2] != -1){
                cnt += 1+ min(min(idx[0],idx[1]),idx[2]);
            }
        }
        return cnt++;
    }
};