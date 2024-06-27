class Solution {
public:
    //     int f(int  i , int j, string &text1, string &text2
    //     ,vector<vector<int>> &dp ){
    //         if( i < 0 || j < 0 )
    //         return 0;

    // if(text1[i] == text2[j])
    //  return dp[i][j] = 1 + f(i-1,j-1,text1 , text2 , dp);
    // return dp[i][j] = max(f(i-1,j,text1 , text2 , dp) , f(i,j-1,text1 , text2
    // , dp));

    //     }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        // base
        for (int i = 0; i <= n; i++)
            dp[i][0] = 0;
        for (int j = 0; j <= m; j++)
            dp[0][j] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[n][m];
    }
};