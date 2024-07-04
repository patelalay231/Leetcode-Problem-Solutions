class Solution {
private:

    int solveMemoization(string &s, string &t, int p1, int p2, vector<vector<int>> &dp)
    {
        if(p1<0 || p2<0)
            return 0;
        
        if(dp[p1][p2] != -1)
            return dp[p1][p2];
        
        int ans = 0;
        if(s[p1] == t[p2])
            ans = 1 + solveMemoization(s, t, p1-1, p2-1, dp);
        else  
            ans = max(solveMemoization(s, t, p1-1, p2, dp), solveMemoization(s, t, p1, p2-1, dp));
        
        dp[p1][p2] = ans;
        return dp[p1][p2];
    }

public:
    int minInsertions(string s) {
        int n = s.size();
        string t = s;
        reverse(t.begin(), t.end());

        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        int longestPalindrome = solveMemoization(s, t, n-1, n-1, dp);

        return n - longestPalindrome;
    }
};