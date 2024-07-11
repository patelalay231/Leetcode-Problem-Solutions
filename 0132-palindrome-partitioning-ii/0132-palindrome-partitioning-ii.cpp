class Solution {
public:
    bool isPalindrome(string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    int helper(string& s, int n, int index, vector<int>& dp) {
        if (index == n) {
            return 0;
        }
        if (dp[index] != -1) {
            return dp[index];
        }
        int miniCuts = INT_MAX;
        for (int i = index; i < n; i++) {
            if (isPalindrome(s, index, i)) {
                int cost = 1 + helper(s, n, i + 1, dp);
                miniCuts = min(miniCuts, cost);
            }
        }
        dp[index] = miniCuts;
        return dp[index];
    }

    int minCut(string s) {
        int n = s.length();
        vector<int> dp(n, -1);
        return helper(s, n, 0, dp) - 1;
    }
};
