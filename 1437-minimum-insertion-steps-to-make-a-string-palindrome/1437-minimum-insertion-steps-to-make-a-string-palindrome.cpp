class Solution {
public:
    int lcs(string& s1,string& s2,int idx1,int idx2,vector<vector<int>>& dp){
        if(idx1 < 0 || idx2 < 0){
            return 0;
        }
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        if(s1[idx1] == s2[idx2]){
            dp[idx1][idx2] = 1 + lcs(s1,s2,idx1-1,idx2-1,dp);
            return dp[idx1][idx2];
        }
        return dp[idx1][idx2] = max(lcs(s1,s2,idx1-1,idx2,dp),lcs(s1,s2,idx1,idx2-1,dp));
    }
    int minInsertions(string s) {
        string revS = s;
        reverse(s.begin(),s.end());
        int len = s.length();
        vector<vector<int>> dp(len,vector<int>(len,-1));
        return len - lcs(s,revS,len-1,len-1,dp);
    }
};