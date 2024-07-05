class Solution {
public:
    bool isMatch(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        vector<bool> prev(n+1, 0), curr(n+1, 0);
        prev[0] = true;
        for(int i=1; i<=n; i++) {
            prev[i] = false;
        }
        
        for(int i=1; i<=m; i++) {
            int flag = true;
            for(int ii=1; ii<=i; ii++) {
                if(s2[ii-1] != '*') flag = false;
            }
            curr[0] = flag;
            for(int j=1; j<=n; j++) {
                if(s1[j-1] == s2[i-1] || s2[i-1] == '?') curr[j] = prev[j-1];
                else if(s2[i-1] == '*') curr[j] = prev[j] | curr[j-1];
                else curr[j] = false;
            }
            prev = curr;
        }
        return prev[n];
    }
};