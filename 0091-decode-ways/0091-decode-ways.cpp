class Solution {
public:
    int helper(string s, int n, int i, vector<int>& dp) {
        if (i == n) {
            return 1; // Base case: reached the end of the string
        }
        if (dp[i] != -1) return dp[i];
        if (s[i] == '0') return 0; // Leading zero is not valid

        int one = helper(s, n, i + 1, dp); // Single digit decode
        int two = 0;

        if (i + 1 < n) { // Two-digit decode
            int sub = stoi(s.substr(i, 2));
            if (sub <= 26) {
                two = helper(s, n, i + 2, dp);
            }
        }

        return dp[i] = one + two;
    }

    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return helper(s, n, 0, dp);
    }
};
