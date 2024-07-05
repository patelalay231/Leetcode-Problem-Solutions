class Solution {
public:
    bool helper(string& s, string& p, int i, int j,vector<vector<int>>& dp) {
        if (i < 0 && j < 0)
            return true;
        if (i < 0 && j >= 0) {
            for (int k = 0; k <= j; k++) {
                if (p[k] != '*')
                    return false;
            }
            return true;
        }
        if (j < 0 && i >= 0)
            return false;
        if(dp[i][j] != -1) return dp[i][j];
        if (s[i] == p[j] || p[j] == '?') {
            return dp[i][j] = helper(s, p, i - 1, j - 1,dp);
        }
        else if (p[j] == '*') {
            return dp[i][j] = helper(s, p, i - 1, j,dp) || helper(s, p, i, j - 1,dp);
        }
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size(),vector<int>(p.size(),-1));
        return helper(s,p,s.size()-1,p.size()-1,dp);
    }
};