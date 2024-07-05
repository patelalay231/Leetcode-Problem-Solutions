class Solution {
public:
    bool f(int idxs, int idxp, string& s, string& p, vector<vector<int>>& dp) {

        if (idxs < 0 and idxp < 0) {
            return true;
        }
        if (idxs >= 0 and
            idxp < 0) // string is still left btw pattern has been exhausted
        {
            return false;
        }
        if (idxs < 0 and idxp >= 0) {
            for (int ii = 0; ii <= idxp; ii++) {
                if (p[ii] != '*') {
                    return false;
                }
            }
            return true;
        }
        if (dp[idxs][idxp] != -1) {
            return dp[idxs][idxp];
        }

        if (p[idxp] == s[idxs] or p[idxp] == '?') {
            return dp[idxs][idxp] = f(idxs - 1, idxp - 1, s, p, dp);
        }

        if (p[idxp] == '*') {
            return dp[idxs][idxp] =
                       f(idxs - 1, idxp, s, p, dp) or f(idxs, idxp - 1, s, p, dp);
        }
        return dp[idxs][idxp] = false;
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n - 1, m - 1, s, p, dp);
    }
    };