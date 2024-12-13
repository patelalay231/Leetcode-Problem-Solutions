class Solution {
public:
    bool helper(string s, string p, int i, int j,vector<vector<int>>& dp) {
        if(i >= s.size() && j >= p.size()){
            return true;
        }
        if(j >= p.size()){
            return false;
        }
        if(dp[i][j] != -1) return dp[i][j];
        bool match = i < s.size() && (s[i] == p[j] || p[j] == '.');
        if(j+1 < p.size() && p[j+1] == '*'){
            return dp[i][j] = helper(s,p,i,j+2,dp) || (match && helper(s,p,i+1,j,dp));
        }
        if(match)
            return dp[i][j] = helper(s,p,i+1,j+1,dp);
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size()+1,vector<int>(p.size()+1,-1));
        return helper(s,p,0,0,dp);
    }
};