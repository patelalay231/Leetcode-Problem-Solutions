class Solution {
public:
    int helper(string s, int n, int i,vector<int>& dp) {
        if (n == i) {
            return 1; // Base case: reached the end of the string
        }
        if(dp[i] != -1) return dp[i];
        int one = 0, two = 0;
        if (s[i] == '0') {
            return 0; // Leading zero is not valid
        }
        // Handle single-digit case
        if (s[i] - '0' < 27 && s[i] - '0' > 0) {
            one += helper(s, n, i + 1,dp);
        }

        // Handle two-digit case
        if (i + 1 < n) {
            int sub = stoi(s.substr(i, 2));
            if (sub < 27 && sub > 0) {
                two += helper(s, n, i + 2,dp);
            }
        }

        dp[i] = one + two;
        return dp[i];
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n,-1);
        return helper(s, n, 0,dp);
    }
};