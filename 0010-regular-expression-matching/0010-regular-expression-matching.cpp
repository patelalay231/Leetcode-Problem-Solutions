class Solution {
public:
    bool helper(const string &s, const string &p, int i, int j, vector<vector<int>> &dp) {
        if (j == p.size()) {
            // If pattern is fully processed, return true if string is also fully processed.
            return i == s.size();
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        bool match = (i < s.size() && (s[i] == p[j] || p[j] == '.'));

        if (j + 1 < p.size() && p[j + 1] == '*') {
            // Consider two cases:
            // 1. Skip '*' and preceding character.
            // 2. Use '*' to match current character if there's a match.
            dp[i][j] = helper(s, p, i, j + 2, dp) || (match && helper(s, p, i + 1, j, dp));
            return dp[i][j];
        }

        if (match) {
            dp[i][j] = helper(s, p, i + 1, j + 1, dp);
            return dp[i][j];
        }

        dp[i][j] = false;
        return false;
    }

    bool isMatch(string s, string p) {
        // Use only necessary memory: (s.size() + 1) rows and (p.size() + 1) columns.
        vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1, -1));
        return helper(s, p, 0, 0, dp);
    }
};
